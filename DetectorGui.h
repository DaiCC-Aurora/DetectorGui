#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DetectorGui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DetectorGuiClass; };
QT_END_NAMESPACE

class DetectorGui : public QMainWindow
{
    Q_OBJECT

public:
    DetectorGui(QWidget *parent = nullptr);
    ~DetectorGui();

private:
    Ui::DetectorGuiClass *ui;
};
