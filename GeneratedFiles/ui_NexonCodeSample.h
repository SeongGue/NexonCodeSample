/********************************************************************************
** Form generated from reading UI file 'NexonCodeSample.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEXONCODESAMPLE_H
#define UI_NEXONCODESAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NexonCodeSampleClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NexonCodeSampleClass)
    {
        if (NexonCodeSampleClass->objectName().isEmpty())
            NexonCodeSampleClass->setObjectName(QStringLiteral("NexonCodeSampleClass"));
        NexonCodeSampleClass->resize(600, 400);
        menuBar = new QMenuBar(NexonCodeSampleClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NexonCodeSampleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NexonCodeSampleClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NexonCodeSampleClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NexonCodeSampleClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NexonCodeSampleClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NexonCodeSampleClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NexonCodeSampleClass->setStatusBar(statusBar);

        retranslateUi(NexonCodeSampleClass);

        QMetaObject::connectSlotsByName(NexonCodeSampleClass);
    } // setupUi

    void retranslateUi(QMainWindow *NexonCodeSampleClass)
    {
        NexonCodeSampleClass->setWindowTitle(QApplication::translate("NexonCodeSampleClass", "NexonCodeSample", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NexonCodeSampleClass: public Ui_NexonCodeSampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEXONCODESAMPLE_H
