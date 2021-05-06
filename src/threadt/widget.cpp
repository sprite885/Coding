#include "widget.h"
#include "ui_widget.h"
#include <QToolButton>
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

     this->setWindowFlags(Qt::FramelessWindowHint);
    QToolButton *toolbtn=new QToolButton();
    QToolButton *toolbtn1=new QToolButton();
    QToolButton *toolbtn2=new QToolButton();
    toolbtn->setIcon(QIcon("../../icon/A8.png"));
    toolbtn1->setIcon(QIcon("../../icon/A9.png"));
    toolbtn2->setIcon(QIcon("../../icon/A10.png"));

    toolbtn->show();
    toolbtn1->show();
    toolbtn2->show();
    toolbtn->setGeometry(100,100,30,30);
    toolbtn1->setGeometry(130,100,30,30);
    toolbtn2->setGeometry(160,100,30,30);


   // camp->run();
}

Widget::~Widget()
{
    delete ui;
}
