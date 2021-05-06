#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QPushButton>
#include <QToolButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口透明度
    //this->setWindowOpacity(0.9);

    //去掉标题栏
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon("../../icon/12185532.png"));

    QToolButton *toolbtn=new QToolButton();
    QToolButton *toolbtn1=new QToolButton();
    QToolButton *toolbtn2=new QToolButton();
    toolbtn->setIcon(QIcon("../../icon/open.png"));
    toolbtn1->setIcon(QIcon("../../icon/a10.png"));
    toolbtn2->setIcon(QIcon("../../icon/a9.png"));


    /*黄色图标
    ui->btn->setIcon(QIcon("../../icon/1open.png"));
    ui->pushButton_2->setIcon(QIcon("../../icon/2play.png"));
    //ui->pushButton_3->setIcon(QIcon("../../icon/3pause.png"));
    ui->pushButton_4->setIcon(QIcon("../../icon/4last.png"));
    ui->pushButton_5->setIcon(QIcon("../../icon/5seekL.png"));
    ui->pushButton_6->setIcon(QIcon("../../icon/6seekR.png"));
    ui->pushButton_7->setIcon(QIcon("../../icon/7next.png"));
    ui->pushButton_8->setIcon(QIcon("../../icon/8stop.png"));
    ui->pushButton_9->setIcon(QIcon("../../icon/9setting.png"));
    ui->pushButton_10->setIcon(QIcon("../../icon/10list.png"));
    ui->pushButton_11->setIcon(QIcon("../../icon/11volume.png"));
    //ui->pushButton_12->setIcon(QIcon("../../icon/12mute.png"));
*/

    //黑色图标
    ui->btn->setIcon(QIcon("../../icon/A1.png"));
    ui->pushButton_2->setIcon(QIcon("../../icon/A2.png"));

    ui->pushButton_4->setIcon(QIcon("../../icon/A4.png"));
    ui->pushButton_5->setIcon(QIcon("../../icon/A5.png"));
    ui->pushButton_6->setIcon(QIcon("../../icon/seek-R.png"));
    ui->pushButton_7->setIcon(QIcon("../../icon/next.png"));
    ui->pushButton_8->setIcon(QIcon("../../icon/A8.png"));
    ui->pushButton_9->setIcon(QIcon("../../icon/setting.png"));
    ui->pushButton_10->setIcon(QIcon("../../icon/A10.png"));
    ui->pushButton_11->setIcon(QIcon("../../icon/A11.png"));


    /*/白色图标
    ui->btn->setIcon(QIcon("../../icon/W-open.png"));

    ui->pushButton_2->setIcon(QIcon("../../icon/W-play.png"));
    ui->pushButton_3->setIcon(QIcon("../../icon/W-pause.png"));
    ui->pushButton_4->setIcon(QIcon("../../icon/W-last.png"));
    ui->pushButton_5->setIcon(QIcon("../../icon/W-seek-L.png"));
    ui->pushButton_6->setIcon(QIcon("../../icon/W-seek-R.png"));
    ui->pushButton_7->setIcon(QIcon("../../icon/W-next.png"));
    ui->pushButton_8->setIcon(QIcon("../../icon/W-stop.png"));
    ui->pushButton_9->setIcon(QIcon("../../icon/W-setting.png"));
    ui->pushButton_10->setIcon(QIcon("../../icon/W-list.png"));
    ui->pushButton_11->setIcon(QIcon("../../icon/W-mute.png"));
    ui->pushButton_12->setIcon(QIcon("../../icon/W-volume.png"));
*/
    //ui->btn->setAutoFillBackground(true);


    ui->btn->setFlat(true);
    ui->pushButton_2->setFlat(true);
    ui->pushButton_4->setFlat(true);
    ui->pushButton_5->setFlat(true);
    ui->pushButton_6->setFlat(true);
    ui->pushButton_7->setFlat(true);
    ui->pushButton_8->setFlat(true);
    ui->pushButton_9->setFlat(true);
    ui->pushButton_10->setFlat(true);
    ui->pushButton_11->setFlat(true);

    //QPalette pal=ui->btn->palette();
    QPalette *pal=new QPalette();
    pal->setColor(QPalette::Background,QColor(100,100,100));
    ui->btn->setPalette(*pal);
    ui->btn->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_2->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_4->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_5->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_6->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_7->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_8->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_9->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_10->setStyleSheet("background-color: rgb(50,50,50)");
    ui->pushButton_11->setStyleSheet("background-color: rgb(50,50,50)");

}
Widget::~Widget()
{
    delete ui;
}
