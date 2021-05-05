#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口透明度
    //this->setWindowOpacity(0.9);

    //去掉标题栏
    //this->setWindowFlags(Qt::FramelessWindowHint);
    ui->btn->setIcon(QIcon("../../icon/1open.png"));
    ui->pushButton_2->setIcon(QIcon("../../icon/2play.png"));
    ui->pushButton_3->setIcon(QIcon("../../icon/3pause.png"));
    ui->pushButton_4->setIcon(QIcon("../../icon/4last.png"));
    ui->pushButton_5->setIcon(QIcon("../../icon/5seekL.png"));
    ui->pushButton_6->setIcon(QIcon("../../icon/6seekR.png"));
    ui->pushButton_7->setIcon(QIcon("../../icon/7next.png"));
    ui->pushButton_8->setIcon(QIcon("../../icon/8stop.png"));
    ui->pushButton_9->setIcon(QIcon("../../icon/9setting.png"));
    ui->pushButton_10->setIcon(QIcon("../../icon/10list.png"));


}
Widget::~Widget()
{
    delete ui;
}
