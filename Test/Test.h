#pragma once11

#include <QtWidgets/QMainWindow>
#include "ui_Test.h"

class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(QWidget *parent = Q_NULLPTR);

private:
    Ui::TestClass ui;

private slots:
    
    void motai();

	void Message();

	void openfile();

};
