/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QWidget* centralWidget;
    QLabel* video;
    QToolButton* pause_play;
    QToolButton* setting;
    QLabel* time;

    void setupUi(QMainWindow* WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QString::fromUtf8("WindowClass"));
        WindowClass->resize(700, 600);
        WindowClass->setMinimumSize(QSize(700, 600));
        WindowClass->setMaximumSize(QSize(700, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN"));
        WindowClass->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/DetectorGui/assets/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        WindowClass->setWindowIcon(icon);
        WindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 242, 242);"));
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        video = new QLabel(centralWidget);
        video->setObjectName(QString::fromUtf8("video"));
        video->setGeometry(QRect(50, 140, 600, 400));
        video->setMinimumSize(QSize(600, 400));
        video->setMaximumSize(QSize(600, 400));
        video->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pause_play = new QToolButton(centralWidget);
        pause_play->setObjectName(QString::fromUtf8("pause_play"));
        pause_play->setGeometry(QRect(50, 50, 60, 60));
        pause_play->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 242, 242);\n"
                                                    "border-color: rgb(242, 242, 242);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/DetectorGui/assets/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pause_play->setIcon(icon1);
        pause_play->setIconSize(QSize(60, 60));
        setting = new QToolButton(centralWidget);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setGeometry(QRect(120, 50, 60, 60));
        setting->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 242, 242);\n"
                                                 "border-color: rgb(242, 242, 242);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/DetectorGui/assets/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon2);
        setting->setIconSize(QSize(60, 60));
        time = new QLabel(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(250, 50, 400, 60));
        time->setMinimumSize(QSize(400, 60));
        time->setMaximumSize(QSize(400, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN"));
        font1.setPointSize(29);
        time->setFont(font1);
        WindowClass->setCentralWidget(centralWidget);

        retranslateUi(WindowClass);

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow* WindowClass)
    {
        WindowClass->setWindowTitle(QCoreApplication::translate("WindowClass", "\344\270\273\351\241\265", nullptr));
        video->setText(QString());
        pause_play->setText(QString());
        setting->setText(QString());
        time->setText(QCoreApplication::translate("WindowClass", "<html><head/><body><p align=\"right\">1900/1/1 00::00::00</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectorGuiClass : public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
