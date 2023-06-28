#pragma once
#pragma execution_character_set("utf-8")
#include "ui_Settings.h"
#include <qfile.h>
#include <qfontdatabase.h>
#include <qmessagebox.h>
#include <qfiledialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Form; };
QT_END_NAMESPACE

using namespace std;

class Settings : public QWidget {
	Q_OBJECT
public:
	Settings(QWidget* parent = nullptr);
	~Settings();
private:
	Ui::Form* ui;
	// º¯Êý
	void update_();
	void sec_file();
};

extern string s_model_path;
extern float s_conf;
extern bool updated;