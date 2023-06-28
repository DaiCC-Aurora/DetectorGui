#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QtCore/qfile.h>
#include <qfiledialog>
#include <qimage.h>
#include <qtimer.h>
#include <qfontdatabase.h>
#include <qmessagebox.h>
#include "Settings.h"
#include "ui_DetectorGui.h"
#include "Detector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DetectorGuiClass; };
QT_END_NAMESPACE

using namespace std;

class DetectorGui : public QMainWindow
{
    Q_OBJECT

public:
    DetectorGui(QWidget *parent = nullptr);
    ~DetectorGui();

private:
    Ui::DetectorGuiClass *ui;
    QTimer *timer;   // ¶¨Ê±Æ÷
    bool is_playing;
    bool is_loaded_module;
    Detector* detector;

    // º¯Êý
    void timeout();
    void open_settings();
    void turn();
};
