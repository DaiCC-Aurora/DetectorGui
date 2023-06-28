#include "DetectorGui.h"

string s_model_path;
float s_conf;
bool updated;
//VideoCapture cap(0);      // 对于测试

/*
* @brief Window构造函数
* @param parent - 父对象
*/
DetectorGui::DetectorGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetectorGuiClass())
{
    ui->setupUi(this);

    // 初始化
    this->is_loaded_module = false;
    this->is_playing = false;
    // 设置样式, 字体
    QFile qss("style.qss");
    qss.open(QFile::ReadOnly);
    QString style = QLatin1String(qss.readAll());
    this->setStyleSheet(style);
    qss.close();
    int fontId = QFontDatabase::addApplicationFont("assets/font.ttf");
    if (fontId >= 0) {
        QString mysh = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(mysh);
        this->setFont(font);
    }
    else {
        QMessageBox warn;
        warn.warning(nullptr, "Oops", "😥 加载字体文件失败\nERROR_CODE: 0X0001", "确定", "取消");
        exit(EXIT_FAILURE);
    }

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &DetectorGui::timeout);
    connect(ui->pause_play, &QToolButton::clicked, this, &DetectorGui::turn);
    connect(ui->setting, &QToolButton::clicked, this, &DetectorGui::open_settings);
    timer->start(10);
    // 新建预测类
    detector = new Detector();
}

/*
* @brief timeout信号
*/
void DetectorGui::timeout() {
    // TODO: 更新时间
    time_t time_now = time(0); char temp_datetime[64]; strftime(temp_datetime, sizeof(temp_datetime), "%Y/%m/%d  %X", localtime(&time_now));
    QString date = temp_datetime;// format: yyyy/mm/dd hh:mm:ss	\
    									example: 1990/1/1   00:00:00
    ui->time->setText(date);

    // TODO: 检查是否更新
    if (updated) {
        updated = false;
        detector->loadModule(s_model_path, s_conf);
        this->is_loaded_module = true;
    }

    // TODO: 更新video
    if (is_playing) {
        Mat f = imread("C:/001.jpg");
        imshow("", detector->Detect(f));
    }
}

void DetectorGui::open_settings() {
    Settings *settings = new Settings();
    settings->show();
}

void DetectorGui::turn() {
    if (is_playing) {
        // play -> pause
        is_playing = !is_playing;
        ui->pause_play->setIcon(QIcon(":/DetectorGui/assets/play.png"));
        ui->setting->setEnabled(true);
    }
    else {
        // pause -> play
        if (is_loaded_module) {
            is_playing = !is_playing;
            ui->pause_play->setIcon(QIcon(":/DetectorGui/assets/pause.png"));
            ui->setting->setEnabled(false);
        }
        else {
            QMessageBox error;
            error.warning(nullptr, "Oops", "😥 未加载模型\nEORROR_CODE: 0X0003");
        }
    }
}


DetectorGui::~DetectorGui()
{
    delete ui;
}
