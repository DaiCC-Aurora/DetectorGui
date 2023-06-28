#include "DetectorGui.h"
#include <QtWidgets/QApplication>
#include "Detector.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    DetectorGui w;
    w.show();
    return a.exec();
}
