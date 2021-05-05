#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "ini_config.h"  //包含配置文件的头文件以调用类

#include <QDebug>
#include <QFileDialog>
#include <QHostInfo>
#include <windows.h>
#include <QCloseEvent>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //读取序列号
    QString lpRootPathName = "C:\\";
    DWORD VolumeSerialNumber;
    GetVolumeInformation((LPTSTR)lpRootPathName.utf16(),NULL,12,&VolumeSerialNumber,NULL,NULL,NULL,15);
    VolumeSerialNumber^=0xfcfd6a7be8;

    QString str=QString::number(VolumeSerialNumber);
    QByteArray byt=QCryptographicHash::hash(str.toLatin1(),QCryptographicHash::Md5);
    QString md5;
    md5.append(byt.toHex());
    qDebug()<<"MD5:"<<md5;

    QSettings *reg=new QSettings("HKEY_CURRENT_USER\\Software\\xczn",QSettings::NativeFormat);

    if(VolumeSerialNumber==reg->value("keyG:").toLongLong())
    {
        //this->window()->setWindowTitle("XC-RemotePlayer-正式版");
        delete reg;
    }else{
        QMessageBox::warning(this,"Warning:","软件未注册\n购买后使用正版",tr("OK"));
        //this->window()->setWindowTitle("XC-RemotePlayer-试用");
        delete reg;
        return ;
    }
    qDebug()<<"检测后执行";
    ui->menuFiles->setTitle(tr("文件(&F)"));
    ui->lineEdit_videoTime->setEnabled(false);
    ui->lineEdit_videoTime->setReadOnly(false);

/**********************系统托盘图标和菜单*************************/

    //恢复窗口
    openApp=new QAction("打开界面",this);
    openApp->setIcon(QIcon("image/open.png"));
    connect(openApp,SIGNAL(triggered()),this,SLOT(showNormal()));
    //托盘菜单-配置程序
    configApp=new QAction("设置",this);
    configApp->setIcon(QIcon("image/setting.png"));
    connect(configApp,SIGNAL(triggered()),this,SLOT(on_btnSetting_clicked()));
    //托盘菜单-退出程序
    quit=new QAction("退出",this);
    quit->setIcon(QIcon("image/exit.png"));
    connect(quit,&QAction::triggered,this,&MainWindow::on_actionExit_triggered);
    //托盘菜单添加子动作
    menu=new QMenu(this);//
    menu->addAction(openApp);//
    //menu->addMenu(QIcon("image/title16.ico"),"Test");
    menu->addAction(configApp);//
    menu->addSeparator();//分割线
    menu->addAction(quit);//
    //托盘图标
    sysTrayIcon=new QSystemTrayIcon(this);
    sysTrayIcon->setIcon(QIcon("image/sysTray16.ico"));
    sysTrayIcon->setContextMenu(menu);
    sysTrayIcon->setToolTip("远程控制服务端");//鼠标指向系统图标时的文字提示
    sysTrayIcon->show();
    //sysTrayIcon->showMessage("","双击打开控制界面",QSystemTrayIcon::Information,3000);
    connect(sysTrayIcon,&QSystemTrayIcon::activated,this,&MainWindow::ActivatedSysTrayIcon);

    /**********************getIP*************************/
    QString localHostName=QHostInfo::localHostName();
    QHostInfo hostInfo=QHostInfo::fromName(localHostName);
    foreach (QHostAddress address,hostInfo.addresses()) {
        //iIPV4
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
            //ing...
        }
        ui->statusBar->setStatusTip("本机IP："+address.toString());
    }

    fileFilter = "*.mp4;*.avi;*.mov;*.mkv;*.flv;*.f4v;*.m4v;*.rmvb;*.jpg;*.png;*.gif;*.bmp;*.mp3;*.aac;*.wma;*.wav";
    fileListFilter<<"*.mp3"<<"*.mp4"<<"*.avi"<<"*.mkv"<<"*.mov"<<"*.flv"<<"*.rmb"<<"*.rmvb"
                 <<"*.f4v"<<"*.m4v"<<"*.jpg"<<"*.png"<<"*.gif"<<"*.bmp"<<"*.aac"<<".wma"<<"wav";

}

MainWindow::~MainWindow()
{
    delete ui;
}

//close
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(sysTrayIcon->isVisible())
    {
        this->hide();
        sysTrayIcon->showMessage("","双击打开界面",QSystemTrayIcon::Information,1000);
        event->ignore();
    }
}
//全局事件
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

}

void MainWindow::RecvData()
{

}

void MainWindow::CompareData(QString str)
{

}
//托盘图标
void MainWindow::ActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger://单击
        this->show();
        break;
    case QSystemTrayIcon::DoubleClick://双击
        this->showNormal();
        break;

    default:
        break;
    }
}

void MainWindow::ReadFiles(int count)
{

}

void MainWindow::ShowContent()
{

}
//选择文件
void MainWindow::on_actionSelectFile_triggered()
{
    filePath=QFileDialog::getOpenFileName(this,"选择文件","D:\\",fileFilter);
    if(filePath.isEmpty())
    {
         qDebug()<<"取消选择";
    }
    else{
        ui->lineEdit_videoTime->setText(" 00.00.00/00.00.00");

        fileDir=filePath;//
        fileDir.cdUp();//

        //路径转换
        QString sdir=fileDir.absolutePath();
        sdir=QDir::toNativeSeparators(sdir);
        ini_config().SetFilesPaht(sdir);
    }
}
//playList
void MainWindow::on_actionPlayList_triggered()
{

}
//TCP
void MainWindow::on_actionTCP_triggered()
{

}
//UDP
void MainWindow::on_actionUDP_triggered()
{

}
//ListLoop
void MainWindow::on_actionListLoop_triggered()
{

}
//NoLoop
void MainWindow::on_actionNoLoop_triggered()
{

}
//exit
void MainWindow::on_actionExit_triggered()
{
    QApplication* app;
    /*
    int i=QMessageBox::warning(this,tr("Warning"),tr("将停用iPad远程控制"),tr("确认"),tr("取消"));
    if(i)
    {
        this->show();
        app->setQuitOnLastWindowClosed(false);
        return;
    }
    */
    app->exit(0);
}
//about
void MainWindow::on_actionAbout_triggered()
{/*
    QMessageBox::about(NULL,"about","远程控制播放器!\n"
                                    "通信方式：UDP/TCP;\t\n"
                                    "指令代码：\n"
                                    "上一曲：\tLAST\n"
                                    "下一曲：\tNEXT\n"
                                    "播放/暂停：\tPAUSE\n"
                                    "停止：\t\tSTOP\n"
                                    "静音：\t\tMUTE\n"
                                    "快进：\t\tADVANCE\n"
                                    "快退：\t\tREWIND\n"
                                    "声音+：\t\tVOLUME+\n"
                                    "声音-：\t\tVOLUME-\n"
                                    "循环间隔：\tDELAYLOOP\n"
                                    "循环播放：\tLISTLOOP\n"
                                    "取消循环：\tNOLOOP\n");*/
}
/************************************************************************/

void MainWindow::on_btnPlayer_clicked()
{

}

void MainWindow::on_btnLast_clicked()
{

}

void MainWindow::on_btnRewind_clicked()
{

}

void MainWindow::on_btnStop_clicked()
{

}

void MainWindow::on_btnAdvance_clicked()
{

}

void MainWindow::on_btnNext_clicked()
{

}

void MainWindow::on_btnMute_clicked()
{

}

//settingWindow
void MainWindow::on_btnSetting_clicked()
{
    SetDialog=new SettingDialog;
    SetDialog->setWindowTitle("Setting");
    SetDialog->show();
}
