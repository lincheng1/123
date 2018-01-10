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

	//�˵���
	//QMenuBar *meBar = new QMenuBar(this);
	QMenuBar *mBar =this->menuBar();  //�ڲ���Ϊ���Ƿ���˵���
	setMenuBar(mBar);
	//meBar->setParent(this);

	//��Ӳ˵�
	QMenu *pFile = mBar->addMenu("File");
	//��Ӳ˵��� ��Ӷ���
	QAction *pclose=pFile->addAction("close");
	pFile->addSeparator();
	//��Ӳ˵���
	QAction *pOpen = pFile->addAction("�Ի���");

	QAction *tishi = pFile->addAction("message");

	QAction *open = pFile->addAction("open");


	
	
	//��ӹ�����
	QToolBar *toolbar = this->addToolBar("toolbar");
	//��ӿ�ݼ�
	toolbar->addAction(pclose);
	QPushButton *a = new QPushButton;
	a->setText("AA");

	//�����������
	toolbar->addWidget(a);

	//toolbar->move(0,100);


	////��ӹ�����2
	//QToolBar *mTool = addToolBar("tool");
	//mTool->setParent(this);
	//mTool->resize(600, 20);
	//mTool->move(0,40);
	////��ӹ�����2
	//QAction *Pclose = mTool->addAction("close");


	//״̬��
	QStatusBar *statu =statusBar();//this->setStatusBar(&statu);///////////////////////////
	QLabel *La = new QLabel(this);
	La->setText("help see you agine");
    statu->addWidget(La);

	//���Ŀռ�
	QTextEdit *edit = new QTextEdit(this);
	setCentralWidget(edit);

	//��������
	QDockWidget *dock = new QDockWidget(this);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	//����������ӿؼ�
	QTextEdit *edit1 = new QTextEdit(this);	
	dock->setWidget(edit1);



	 //connect(pFile,&QAction::triggered,this,&QMainWindow::close);	
	 connect(pclose, &QAction::triggered, this, &QMainWindow::close);

	 connect(pOpen, &QAction::triggered, this, &Test::motai);
	 connect(tishi, &QAction::triggered, this, &Test::Message);

	 connect(open, &QAction::triggered, this, &Test::openfile);

}

//ģ̬�Ի���
void Test::motai()
{
	QDialog dlg;
	dlg.exec();
}

void Test::Message()
{
	//QMessageBox::about(this, "Help", "Are you OK");

	//ö�� enum StandardButton {Ok, Open, Save, Cancel, ..., ButtonMask}����ֵΪint
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


