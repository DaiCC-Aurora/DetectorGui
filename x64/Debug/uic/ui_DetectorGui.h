/********************************************************************************
** Form generated from reading UI file 'DetectorGui.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORGUI_H
#define UI_DETECTORGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorGuiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DetectorGuiClass)
    {
        if (DetectorGuiClass->objectName().isEmpty())
            DetectorGuiClass->setObjectName(QString::fromUtf8("DetectorGuiClass"));
        DetectorGuiClass->resize(600, 400);
        menuBar = new QMenuBar(DetectorGuiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DetectorGuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DetectorGuiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DetectorGuiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DetectorGuiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DetectorGuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DetectorGuiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DetectorGuiClass->setStatusBar(statusBar);

        retranslateUi(DetectorGuiClass);

        QMetaObject::connectSlotsByName(DetectorGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *DetectorGuiClass)
    {
        DetectorGuiClass->setWindowTitle(QCoreApplication::translate("DetectorGuiClass", "DetectorGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectorGuiClass: public Ui_DetectorGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORGUI_H
