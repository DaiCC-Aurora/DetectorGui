/********************************************************************************
** Form generated from reading UI file 'SettingsHbJdeJ.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTINGSHBJDEJ_H
#define SETTINGSHBJDEJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *xml_file;
    QPushButton *sec_file;
    QLineEdit *conf;
    QLineEdit *imgsz;
    QPushButton *save;
    QPushButton *cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 440);
        Form->setMinimumSize(QSize(400, 440));
        Form->setMaximumSize(QSize(400, 440));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN"));
        font.setPointSize(10);
        Form->setFont(font);
        xml_file = new QLineEdit(Form);
        xml_file->setObjectName(QString::fromUtf8("xml_file"));
        xml_file->setGeometry(QRect(40, 200, 280, 40));
        xml_file->setMinimumSize(QSize(280, 40));
        xml_file->setMaximumSize(QSize(310, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        xml_file->setFont(font1);
        xml_file->setContextMenuPolicy(Qt::DefaultContextMenu);
        xml_file->setMaxLength(128);
        xml_file->setReadOnly(true);
        sec_file = new QPushButton(Form);
        sec_file->setObjectName(QString::fromUtf8("sec_file"));
        sec_file->setGeometry(QRect(320, 200, 40, 40));
        conf = new QLineEdit(Form);
        conf->setObjectName(QString::fromUtf8("conf"));
        conf->setGeometry(QRect(40, 120, 320, 40));
        conf->setMinimumSize(QSize(320, 40));
        conf->setMaximumSize(QSize(320, 40));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        conf->setFont(font2);
        conf->setMaxLength(5);
        imgsz = new QLineEdit(Form);
        imgsz->setObjectName(QString::fromUtf8("imgsz"));
        imgsz->setGeometry(QRect(40, 50, 320, 40));
        imgsz->setMinimumSize(QSize(320, 40));
        imgsz->setMaximumSize(QSize(320, 40));
        imgsz->setFont(font2);
        imgsz->setMaxLength(9);
        imgsz->setFrame(true);
        imgsz->setDragEnabled(false);
        save = new QPushButton(Form);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(200, 320, 70, 40));
        save->setMinimumSize(QSize(70, 40));
        save->setMaximumSize(QSize(70, 40));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(false);
        font3.setWeight(50);
        save->setFont(font3);
        cancel = new QPushButton(Form);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(290, 320, 71, 40));
        QFont font4;
        font4.setPointSize(13);
        cancel->setFont(font4);
        cancel->setAutoDefault(false);
        cancel->setFlat(false);

        retranslateUi(Form);

        cancel->setDefault(false);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\350\256\276\347\275\256", nullptr));
        xml_file->setText(QString());
        xml_file->setPlaceholderText(QCoreApplication::translate("Form", "Ä£ÐÍÂ·¾¶", nullptr));
        sec_file->setText(QCoreApplication::translate("Form", "...", nullptr));
        conf->setPlaceholderText(QCoreApplication::translate("Form", "\351\230\210\345\200\274", nullptr));
        imgsz->setInputMask(QString());
        imgsz->setText(QString());
        imgsz->setPlaceholderText(QCoreApplication::translate("Form", "\345\233\276\347\211\207\345\260\272\345\257\270", nullptr));
        save->setText(QCoreApplication::translate("Form", "\344\277\235\345\255\230", nullptr));
        cancel->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTINGSHBJDEJ_H
