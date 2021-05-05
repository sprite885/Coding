#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ui->btn->autoFillBackground()=true;
    ui->btn->setIcon(QIcon("D:/Coding/open1.png"));
}

Dialog::~Dialog()
{
    delete ui;
}
