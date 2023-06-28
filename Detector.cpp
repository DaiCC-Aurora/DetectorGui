#include "Detector.h"

/*
* @brief ����ģ��, ����, �������
* @param model_path - ģ��λ��, ֧��xml(openvino)/onnxģ��
* @param conf - ��ֵ
*/
bool Detector::loadModule(string model_path, float conf) {
	try {
		Core* ie = new Core();
		auto network = ie->ReadNetwork(model_path);
		input_info = network.getInputsInfo();
		output_info = network.getOutputsInfo();

		// ���������ʽ
		for (auto& item : input_info) {
			auto input_data = item.second;
			input_data->setPrecision(Precision::FP32);
			input_data->setLayout(Layout::NCHW);
			input_data->getPreProcess().setResizeAlgorithm(RESIZE_BILINEAR);
			input_data->getPreProcess().setColorFormat(ColorFormat::RGB);
		}

		// ���������ʽ
		for (auto& item : output_info) {
			auto output_data = item.second;
			output_data->setPrecision(Precision::FP32);
		}
		auto executable_network = ie->LoadNetwork(network, "GPU");

		// ��������
		infer_request = executable_network.CreateInferRequest();
		return true;
	} catch(exception& e) {
		return false;
	}
}

/*
* @brief ����
* @return ����������ͼƬ
*/
Mat Detector::Detect(Mat frame) {
	// ��������
	int frame_height = frame.rows, frame_width = frame.cols;
	float scale_x = frame_width / 640.0, scale_y = frame_height / 640.0;

	// �������
	vector<Rect> boxes;
	vector<int> classIDs;
	vector<float> confidence;
	for (auto& item : input_info) {
		auto input_name = item.first;

		// ��ȡ����BLOB
		auto input = this->infer_request.GetBlob(input_name);
		size_t num_channels = input->getTensorDesc().getDims()[1],
			   h			= input->getTensorDesc().getDims()[2],
			   w			= input->getTensorDesc().getDims()[3],
			   frame_size	= h * w;
		Mat blob_image;
		resize(frame, blob_image, Size(h, w));

		// NCHW
		float* data = static_cast<float*>(input->buffer());
		for (size_t row = 0; row < h; row++) {
			for (size_t col = 0; col < w; col++) {
				for (size_t ch = 0; ch < num_channels; ch++) {
					data[frame_size * ch + row * w + col] = float(blob_image.at<Vec3b>(row, col)[ch]) / 255.0;
				}
			}
		}
	}
	this->infer_request.Infer();

	for (auto& item : output_info) {
		auto output_name = item.first;
		auto output = infer_request.GetBlob(output_name);
		
		const float* output_blob = static_cast<PrecisionTrait<Precision::FP32>::value_type*>(output->buffer());
		const SizeVector outputDims = output->getTensorDesc().getDims();
		const int	out_n		 = outputDims[0],
					out_c		 = outputDims[1],
					side_h		 = outputDims[2],
					side_w		 = outputDims[3],
					side_data	 = outputDims[4];

		float stride = this->get_stride(side_h, side_h);
		int anthor_index = this->get_anchor_index(side_h, side_h);
		int side_square = side_h * side_w;
		int side_data_square = side_square * side_data;
		int side_data_w = side_w * side_data;

		for (int i = 0; i < side_square; ++i) {
			for (int c = 0; c < out_c; c++) {
				int row = i / side_h;
				int col = i % side_h;
				int object_index = c * side_data_square + row * side_data_w + col * side_data;

				// ��ֵ����
				float conf_ = this->sigmoid_function(output_blob[object_index + 4]);
				if (conf_ < this->conf) continue;

				// ������������
				float	x = (this->sigmoid_function(output_blob[object_index]) * 2 - 0.5 + col) * stride,
						y = (this->sigmoid_function(output_blob[object_index + 1]) * 2 - 0.5 + row) * stride,
						w = pow(this->sigmoid_function(output_blob[object_index + 2]) * 2, 2) * this->anchors[anthor_index + c * 2],
						h = pow(this->sigmoid_function(output_blob[object_index + 3]) * 2, 2) * this->anchors[anthor_index + c * 2 + 1];
				float max_prob = -1;
				int class_index = -1;

				// �������
				for (int d = 5; d < 85; d++) {
					float prob = this->sigmoid_function(output_blob[object_index + d]);
					if (prob > max_prob) {
						max_prob = prob;
						class_index = d - 5;
					}
				}

				// ת������
				int x1 = saturate_cast<int>((x - w / 2) * scale_x),	// ����->x
					y1 = saturate_cast<int>((y - h / 2) * scale_y),	// ����->y
					x2 = saturate_cast<int>((x + w / 2) * scale_x),	// ����->x
					y2 = saturate_cast<int>((y + h / 2) * scale_y);	// ����->y

				// �������
				classIDs.push_back(class_index);
				confidence.push_back((float)conf_);
				boxes.push_back(Rect(x1, y1, x2 - x1, y2 - y1));
			}
		}
	}

	vector<int> indices;
	NMSBoxes(boxes, confidence, this->conf, 0.5, indices);
	for (size_t i = 0; i < indices.size(); ++i) {
		int idx = indices[i];
		Rect box = boxes[idx];
		rectangle(frame, box, Scalar(140, 199, 0), 4, 8, 0);
	}
	return frame;
}

/*
* @brief ��ȡê��
* @param scale_w - NULL
* @param scale_h - NULL
*/
int Detector::get_anchor_index(int scale_w, int scale_h) {
	switch (scale_w) {
	case 20: return 12;
	case 40: return 6;
	case 80: return 0;
	default: return -1;
	}
}

/*
* @brief ��ȡ����
* @param scale_w - NULL
* @param scale_h - NULL
*/
float Detector::get_stride(int scale_w, int scale_h) {
	switch (scale_w) {
	case 20: return 32.0;
	case 40: return 16.0;
	case 80: return 8.0;
	default: return -1;
	}
}

/*
* @brief Sigmoid
* @param a - input
*/
float Detector::sigmoid_function(float a) {
	float b = 1. / (1. + exp(-a));
	return b;
}