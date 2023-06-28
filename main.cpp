#include "DetectorGui.h"
#include <QtWidgets/QApplication>
#include "Detector.h"

int main(int argc, char *argv[]) {
    // test
    Detector det;
    det.loadModule("C:/Users/Administrator/Desktop/20230413/status.onnx");
    Mat img = imread("C:/001.jpg");
    deb;
    Mat f = det.Detect(img); deb;
    imshow("Window", f);

    QApplication a(argc, argv);
    DetectorGui w;
    w.show();
    return a.exec();
}
