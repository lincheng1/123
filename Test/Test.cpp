#include "Test.h"
#include<QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar22>
#include <QDebug>
#include <QStatusBar>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>


Test::Test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//菜单栏
	//QMenuBar *meBar = new QMenuBar(this);
	QMenuBar *mBar =this->menuBar();  //内部会为我们分配菜单兰
	setMenuBar(mBar);
	//meBar->setParent(this);

	//添加菜单
	QMenu *pFile = mBar->addMenu("File");
	//添加菜单项 添加动作
	QAction *pclose=pFile->addAction("close");
	pFile->addSeparator();
	//添加菜单项
	QAction *pOpen = pFile->addAction("对话框");

	QAction *tishi = pFile->addAction("message");

	QAction *open = pFile->addAction("open");


	
	
	//添加工具栏
	QToolBar *toolbar = this->addToolBar("toolbar");
	//添加快捷键
	toolbar->addAction(pclose);
	QPushButton *a = new QPushButton;
	a->setText("AA");

	//从左往右添加
	toolbar->addWidget(a);

	//toolbar->move(0,100);


	////添加工具栏2
	//QToolBar *mTool = addToolBar("tool");
	//mTool->setParent(this);
	//mTool->resize(600, 20);
	//mTool->move(0,40);
	////添加工具项2
	//QAction *Pclose = mTool->addAction("close");


	//状态栏
	QStatusBar *statu =statusBar();//this->setStatusBar(&statu);///////////////////////////
	QLabel *La = new QLabel(this);
	La->setText("help see you agine");
    statu->addWidget(La);

	//核心空间
	QTextEdit *edit = new QTextEdit(this);
	setCentralWidget(edit);

	//浮动窗口
	QDockWidget *dock = new QDockWidget(this);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	//浮动窗口添加控件
	QTextEdit *edit1 = new QTextEdit(this);	
	dock->setWidget(edit1);



	 //connect(pFile,&QAction::triggered,this,&QMainWindow::close);	
	 connect(pclose, &QAction::triggered, this, &QMainWindow::close);

	 connect(pOpen, &QAction::triggered, this, &Test::motai);
	 connect(tishi, &QAction::triggered, this, &Test::Message);

	 connect(open, &QAction::triggered, this, &Test::openfile);

}

//模态对话框
void Test::motai()
{
	QDialog dlg;
	dlg.exec();
}

void Test::Message()
{
	//QMessageBox::about(this, "Help", "Are you OK");

	//枚举 enum StandardButton {Ok, Open, Save, Cancel, ..., ButtonMask}返回值为int
	int ret=QMessageBox::question(this, "Hello", "ni hao", QMessageBox::Ok, QMessageBox::Cancel);

	switch (ret)
	{
	case QMessageBox::Ok : qDebug() << "OK";   break;

	case QMessageBox::Cancel: qDebug() << "cancle";   break;

	default:
		break;
	
	}

}

void Test::openfile()
{
	QString path = QFileDialog::getOpenFileName(this, "file", "../", tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml);;all(*.*)"));
	qDebug() << path;
}


