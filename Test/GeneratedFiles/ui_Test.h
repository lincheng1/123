/********************************************************************************
** Form generated from reading UI file 'Test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu11;
    QMenu *menu22;
    QMenu *menu33;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestClass)
    {
        if (TestClass->objectName().isEmpty())
            TestClass->setObjectName(QStringLiteral("TestClass"));
        TestClass->resize(600, 400);
        centralWidget = new QWidget(TestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu11 = new QMenu(menuBar);
        menu11->setObjectName(QStringLiteral("menu11"));
        menu22 = new QMenu(menuBar);
        menu22->setObjectName(QStringLiteral("menu22"));
        menu33 = new QMenu(menuBar);
        menu33->setObjectName(QStringLiteral("menu33"));
        TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestClass->setStatusBar(statusBar);

        menuBar->addAction(menu11->menuAction());
        menuBar->addAction(menu22->menuAction());
        menuBar->addAction(menu33->menuAction());

        retranslateUi(TestClass);

        QMetaObject::connectSlotsByName(TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestClass)
    {
        TestClass->setWindowTitle(QApplication::translate("TestClass", "Test", Q_NULLPTR));
        menu11->setTitle(QApplication::translate("TestClass", "11", Q_NULLPTR));
        menu22->setTitle(QApplication::translate("TestClass", "22", Q_NULLPTR));
        menu33->setTitle(QApplication::translate("TestClass", "33", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestClass: public Ui_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
