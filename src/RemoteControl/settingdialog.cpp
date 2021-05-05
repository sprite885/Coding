#include "settingdialog.h"
#include "ui_settingdialog.h"

#include "ini_config.h"
#include <QMessageBox>
#include <windows.h>
#include <QRegExp>
#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    QSettings *reg=new QSettings("HKEY_CURRENT_USER\\Software\\xczn",QSettings::NativeFormat);
    reg->setValue("keyG:",3284);
    delete reg;

    //正则表达式限制只允许输入IP
    QRegExp exp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    QRegExpValidator *ipVal = new QRegExpValidator(exp);
    ui->lineEdit_targetIp->setValidator(ipVal);
    ui->lineEdit_targetIp->setInputMask("000.000.000.000");
    //输入格式限制
    QIntValidator *validator=new QIntValidator;
    validator->setRange(100,99999);
    ui->lineEdit_targetPort->setValidator(validator);
    ui->lineEdit_TcpPort->setValidator(validator);
    ui->lineEdit_UdpPort->setValidator(validator);
    ui->lineEdit_delayTime->setValidator(new QIntValidator(1,3600,this));
    //输入提示
    ui->lineEdit_targetPort->setPlaceholderText("Port:100-99999");
    ui->lineEdit_TcpPort->setPlaceholderText("Port:100-99999");
    ui->lineEdit_UdpPort->setPlaceholderText("Port:100-99999");
    ui->lineEdit_delayTime->setPlaceholderText("1-3600秒");

    if(ini_config().GetTargetIP()=="null"||
            ini_config().GetTargetIP().isEmpty()||
            ini_config().GetTargetIP()=="...")
    {
        ui->lineEdit_targetIp->setText("255.255.255.255");
    }else{
        ui->lineEdit_targetIp->setText(ini_config().GetTargetIP());
    }
    if(ini_config().GetTargetPort().isNull())
    {
        ui->lineEdit_targetPort->setText("9999");
    }else{
        ui->lineEdit_targetPort->setText(ini_config().GetTargetPort());
    }
    if(ini_config().GetLocalTcpPort().isNull())
    {
        ui->lineEdit_TcpPort->setText("7777");
    }
    else{
        ui->lineEdit_TcpPort->setText(ini_config().GetLocalTcpPort());
    }
    if(ini_config().GetLocalUdpPort().isNull())
    {
        ui->lineEdit_UdpPort->setText("8888");
    }
    else{
        ui->lineEdit_UdpPort->setText(ini_config().GetLocalUdpPort());
    }
    if(ini_config().GetLoopDelayTime().isNull())
    {
        ui->lineEdit_delayTime->setText("5");
    }
    else{
        ui->lineEdit_delayTime->setText(ini_config().GetLoopDelayTime());
    }

    if(ini_config().GetFilesPaht().isNull())
    {
        ui->lineEdit_filePath->setText("D:\\");
    }else{
        ui->lineEdit_filePath->setText(ini_config().GetFilesPaht());
    }
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_btnSave_clicked()
{
    if(ui->lineEdit_delayTime->text().isEmpty()||
            ui->lineEdit_filePath->text().isEmpty()||
            ui->lineEdit_targetIp->text().isEmpty()||
            ui->lineEdit_targetIp->text()=="..."||
            ui->lineEdit_targetPort->text().isEmpty()||
            ui->lineEdit_TcpPort->text().isEmpty()||
            ui->lineEdit_UdpPort->text().isEmpty())
    {
        QMessageBox::warning(this,"Warning:","完整设置参数列表",tr("OK"));
        return ;
    }
    if(ui->lineEdit_TcpPort->text()==ui->lineEdit_UdpPort->text())
    {
        QMessageBox::warning(this,QStringLiteral("Warning:"),QStringLiteral("TCP-UDP端口重复"),tr("OK"));
        return ;
    }
    ini_config().SetTargetIP(ui->lineEdit_targetIp->text());
    ini_config().SetTargetPort(ui->lineEdit_targetPort->text());
    ini_config().SetFilesPaht(ui->lineEdit_filePath->text());
    ini_config().SetLocalTcpPort(ui->lineEdit_TcpPort->text());
    ini_config().SetLocalUdpPort(ui->lineEdit_UdpPort->text());
    ini_config().SetLoopDelayTime(ui->lineEdit_delayTime->text());
    accept();
}
