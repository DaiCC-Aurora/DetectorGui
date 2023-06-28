#pragma once
#pragma execution_character_set("utf-8")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <qmessagebox.h>
#include <inference_engine.hpp>

// 仅用于debug
#ifndef deb
#define deb std::cout<<"DEBUG POINT"<<std::endl;

#endif


using namespace InferenceEngine;
using namespace cv::dnn;
using namespace cv;
using namespace std;

class Detector {
public:
	bool loadModule(string model_path, float conf=0.25f);
	Mat Detect(Mat frame);

private:
	// 参数
	vector<float> anchors = {
	10,13, 16,30, 33,23,
	30,61, 62,45, 59,119,
	116,90, 156,198, 373,326
	};
	float conf;

	// 转换函数
	int get_anchor_index(int scale_w, int scale_h);
	float get_stride(int scale_w, int scale_h);
	float sigmoid_function(float a);

	// 加载OpenVino插件
	InputsDataMap input_info;
	OutputsDataMap output_info;
	ExecutableNetwork executable_network;
	InferRequest infer_request;
};