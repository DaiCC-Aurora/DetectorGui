#include "Settings.h"
#ifndef deb
#define deb std::cout<<"DEBUG POINT"<<std::endl;
#endif

Settings::Settings(QWidget* parent) : QWidget(parent), ui(new Ui::Form()) {
	ui->setupUi(this);
    // 初始化
    // 设置样式, 字体
    QFile qss("style.qss");
    qss.open(QFile::ReadOnly);
    QString style = QLatin1String(qss.readAll());
    this->setStyleSheet(style);
    qss.close();
    int fontId = QFontDatabase::addApplicationFont("assets/font.ttf");
    QString mysh = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(mysh);
    this->setFont(font);
    ui->xml_file->setEnabled(false);
    connect(ui->save, &QPushButton::clicked, this, &Settings::update_);
    connect(ui->sec_file, &QPushButton::clicked, this, &Settings::sec_file);
    connect(ui->cancel, &QPushButton::clicked, this, &Settings::close);
}

/*
* @brief 检查输入并更新
*/
void Settings::update_() {
    // TODO: 检查输入是否合法
    try {
        if (ui->conf->text().toFloat() <= 0.0f || ui->imgsz->text().toInt() <= 0 || ui->conf->text().toFloat() >= 1.0f) {
            QMessageBox warn;
            warn.warning(nullptr, "Oops", "😥 输入含有非法字符, 请重试\nERROR_CODE: 0X0002", "确定", "取消");
        }
    }
    catch (exception &e) {
        QMessageBox warn;
        warn.warning(nullptr, "Oops", "😥 输入含有非法字符, 请重试\nERROR_CODE: 0X0002", "确定", "取消");
    }
    // TODO: 更改全局变量
    //SET::set(ui->xml_file->text().toStdString(), ui->conf->text().toInt());
    s_conf = ui->conf->text().toInt();
    s_model_path = ui->xml_file->text().toStdString();
    updated = true;
    this->close();
}

/*
* @brief 选择模型路径
*/
void Settings::sec_file() {
    ui->xml_file->setEnabled(true);
    auto model_path = QFileDialog::getOpenFileName(nullptr, "选择权重文件", ".", "onnx files (*.onnx);xml files(*.xml)");
    ui->xml_file->setText(model_path);
    ui->xml_file->setEnabled(false);
}

Settings::~Settings() { delete ui; }