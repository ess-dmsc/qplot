/********************************************************************************
** Form generated from reading UI file 'TestApp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTAPP_H
#define UI_TESTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QPlot1D.h"
#include "QPlot2D.h"

QT_BEGIN_NAMESPACE

class Ui_TestApp
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPlot::Multi1D *plot1d;
    QPlot::Plot2D *plot2d;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestApp)
    {
        if (TestApp->objectName().isEmpty())
            TestApp->setObjectName(QStringLiteral("TestApp"));
        TestApp->resize(1582, 913);
        TestApp->setIconSize(QSize(18, 18));
        TestApp->setDocumentMode(false);
        centralWidget = new QWidget(TestApp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot1d = new QPlot::Multi1D(centralWidget);
        plot1d->setObjectName(QStringLiteral("plot1d"));

        gridLayout->addWidget(plot1d, 0, 0, 1, 1);

        plot2d = new QPlot::Plot2D(centralWidget);
        plot2d->setObjectName(QStringLiteral("plot2d"));

        gridLayout->addWidget(plot2d, 0, 1, 1, 1);

        TestApp->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestApp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestApp->setStatusBar(statusBar);

        retranslateUi(TestApp);

        QMetaObject::connectSlotsByName(TestApp);
    } // setupUi

    void retranslateUi(QMainWindow *TestApp)
    {
        TestApp->setWindowTitle(QApplication::translate("TestApp", "TestApp", 0));
    } // retranslateUi

};

namespace Ui {
    class TestApp: public Ui_TestApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTAPP_H
