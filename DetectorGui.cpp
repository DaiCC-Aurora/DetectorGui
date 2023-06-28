#include "DetectorGui.h"

DetectorGui::DetectorGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetectorGuiClass())
{
    ui->setupUi(this);
}

DetectorGui::~DetectorGui()
{
    delete ui;
}
