#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QMenu>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    fileFilter = "*.mp4;*.avi;*.mov;*.mkv;*.flv;*.f4v;*.m4v;*.rmvb;*.jpg;*.png;*.gif;*.bmp;*.mp3;*.aac;*.wma;*.wav";
    fileListFilter<<"*.mp3"<<"*.mp4"<<"*.avi"<<"*.mkv"<<"*.mov"<<"*.flv"<<"*.rmb"<<"*.rmvb"
                 <<"*.f4v"<<"*.m4v"<<"*.jpg"<<"*.png"<<"*.gif"<<"*.bmp"<<"*.aac"<<".wma"<<"wav";
    //背景颜色
    player=new QMediaPlayer(this);
    playList=new QMediaPlaylist(this);

    QPalette palette;
    palette.setColor(QPalette::Background,Qt::black);
    //图片播放背景
    ui->imglabel->setAutoFillBackground(true);
    ui->imglabel->setPalette(palette);
    ui->imglabel->setScaledContents(true);//等比例拉伸
    //视频播放背景
    ui->videoWidget->setAutoFillBackground(true);
    ui->videoWidget->setPalette(palette);

    ui->fileDirLineEdit->setReadOnly(true);
    //ui->fileDirLineEdit->setEnabled(false);

    ui->videoMute->setIcon(QIcon("image/mute1.png"));
    ui->videoAdvance->setIcon(QIcon("image/advance.png"));
    ui->videoPlayerPause->setIcon(QIcon("image/bf.png"));
    ui->videoRewind->setIcon(QIcon("image/rewind.png"));
    ui->videoStop->setIcon(QIcon("image/stop.png"));
    ui->lastContent->setIcon(QIcon("image/last.png"));
    ui->nextContent->setIcon(QIcon("image/next.png"));
    /**********************系统托盘图标和菜单*************************/
    QIcon icon("image/sysTray16.ico");
    //托盘菜单-恢复窗口
    openApp=new QAction("打开控制界面",this);
    openApp->setIcon(QIcon("image/open.png"));
    connect(openApp,&QAction::triggered,this,&Widget::showNormal);
    //托盘菜单-配置程序
    configApp=new QAction("设置",this);
    configApp->setIcon(QIcon("image/setting.png"));
    connect(configApp,SIGNAL(triggered()),this,SLOT(configApplication()));
    //托盘菜单-退出程序
    quit=new QAction("退出",this);
    quit->setIcon(QIcon("image/exit.png"));
    connect(quit,&QAction::triggered,this,&Widget::exitApplication);
    //托盘菜单添加子动作
    menu=new QMenu(this);//
    menu->addAction(openApp);//
    //menu->addMenu(QIcon("image/title16.ico"),"Test");
    menu->addAction(configApp);//
    menu->addSeparator();//分割线
    menu->addAction(quit);//
    //托盘图标
    sysTrayIcon=new QSystemTrayIcon(this);
    sysTrayIcon->setIcon(icon);
    sysTrayIcon->setContextMenu(menu);
    sysTrayIcon->setToolTip("远程控制服务端");//鼠标指向系统图标时的文字提示
    sysTrayIcon->show();

    connect(sysTrayIcon,&QSystemTrayIcon::activated,this,&Widget::ActivatedSysTrayIcon);

    /*******************获取本机IP 设置端口只读************************/
    readIpTime=new QTimer();
    readIpTime->setInterval(2000);
    connect(readIpTime,SIGNAL(timeout()),this,SLOT(IpTimeOut()));
    readIpTime->start();

    ui->localIP->setReadOnly(true);
    //端口号限制只允许输入数字
    ui->localPORT->setValidator(new QIntValidator(100,99999,this));
    ui->targetPORT->setValidator(new QIntValidator(100,99999,this));
    //正则表达式限制只允许输入IP
    QRegExp exp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    QRegExpValidator *ipVal = new QRegExpValidator(exp);
    ui->targetIP->setValidator(ipVal);
    ui->targetIP->setInputMask("000.000.000.000;");// 用于占位
    //本地IP和端口
    //localIP=QHostAddress(ui->localIP->text().toInt());
    localPort=ui->localPORT->text().toInt();
    //绑定PORT端口
    udpSocket.bind(localPort);
    disconnect(&udpSocket,SIGNAL(readyRead()),this,SLOT(RecvData()));
    connect(&udpSocket,SIGNAL(readyRead()),this,SLOT(RecvData()));
    RecvData();
    /**********************列表循环播放设置*************************/
    QIntValidator *intValidator=new QIntValidator;//整数验证
    intValidator->setRange(1,3600);//允许输入1-3600
    ui->delayLineEdit->setValidator(intValidator);
    ui->delayLineEdit->setPlaceholderText("1-3600秒");
    //ui->delayLineEdit->setStatusTip("循环播放间隔时间");
    listLoopTime=new QTimer();
    //connect(listLoopTime,&QTimer::timeout,this,&Widget::on_nextContent_clicked);
    connect(listLoopTime,SIGNAL(timeout()),this,SLOT(on_nextContent_clicked()));
    /*********************初始化文件列表************************/
    QFile file("C:/Windows/XcrpConfig.cfg");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        /*
        QString s="";
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        file.write(s.toUtf8());
        file.close();
        */
        ui->fileDirLineEdit->setPlaceholderText("~指定文件路径");
    }
    else{
        QByteArray byteArr=file.readAll();
        ui->fileDirLineEdit->setText(QString(byteArr));
        file.close();

        filePath=ui->fileDirLineEdit->text();
        filePath=QDir::fromNativeSeparators(filePath);//转换路径\\为/
        QFileInfo fi=filePath;
        if(!fi.isDir())
        {
            ui->fileDirLineEdit->setText(ui->fileDirLineEdit->text()+"::目录不存在");
        }
        else{
            fileDir = filePath;//转换为目录
            fileDir.setFilter(QDir::Dirs|QDir::Files);//过滤，显示文件和文件夹
            fileDir.setNameFilters(fileListFilter);//过滤文件格式
            fileInfoList=fileDir.entryInfoList(QDir::Files);//获取所选目录下的所有文件

            //获取文件列表
            ReadFiles(fileInfoList.count());
        }
    }
    //绑定声音滑动器
    ui->audioSlider->setSingleStep(10);// 步长
    ui->audioSlider->setRange(0,100);
    ui->audioSlider->setValue(50);

    connect(player, SIGNAL(volumeChanged(int)), ui->audioSlider, SLOT(setValue(int)));
    connect(ui->audioSlider, SIGNAL(valueChanged(int)), player, SLOT(setVolume(int)));

    //绑定视频进度条
    videoTime=new QTimer();
    videoTime->setInterval(500);
    ui->videoSlider->setRange(0,1000);
    ui->videoSlider->setEnabled(false);
    ui->position->setReadOnly(true);
    ui->position->setEnabled(false);
    connect(videoTime,SIGNAL(timeout()),this,SLOT(on_videoTimeOut()));

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(tryOnStop(QMediaPlayer::State)));

    // 全局事件侦听器
    ui->imglabel->installEventFilter(this);
    ui->videoWidget->installEventFilter(this);
}
Widget::~Widget()
{
    delete ui;
}
//开机启动时读取IP
void Widget::IpTimeOut()
{
    QString localHostName=QHostInfo::localHostName();
    QHostInfo hostInfo=QHostInfo::fromName(localHostName);
    foreach (QHostAddress address,hostInfo.addresses()) {
        //iIPV4
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
            //ing...
        }
        ui->localIP->setText(address.toString());
    }
    if(ui->localIP->text()!="127.0.0.1")
    {
        readIpTime->stop();
    }
}
//发送数据
void Widget::on_btnSendData_clicked()
{
    targetIP=QHostAddress(ui->targetIP->text());
    targetPort=ui->targetPORT->text().toInt();
    QString str=ui->sendTextEdit->toPlainText()+"\n";
    QByteArray sendData=str.toLatin1();
    udpSocket.writeDatagram(sendData,sendData.length(),targetIP,targetPort);

    if(!ui->targetIP->text().isEmpty())
    {

    }
    else if(!ui->targetPORT->text().isEmpty())
    {

    }else if(!ui->sendTextEdit->toPlainText().isEmpty())
    {

    }
}
//接收数据
void Widget::RecvData()
{
    QHostAddress address;
    quint16 port=0;
    QByteArray dataBuf;
    while (udpSocket.hasPendingDatagrams()) {
        dataBuf.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(dataBuf.data(),dataBuf.size(),&address,&port);
    }
    if(!dataBuf.isEmpty())
    {
        quint32 i32=address.toIPv4Address();
        QHostAddress add=QHostAddress(i32);
        ui->recvTextEdit->append("来自："+add.toString());
        ui->recvTextEdit->append(dataBuf);

        CompareData(QString(dataBuf));
    }
}
//关闭主界面事件，界面不可见收到系统托盘处
void Widget::closeEvent(QCloseEvent * event)
{
    if(sysTrayIcon->isVisible())
    {
        this->hide();
        sysTrayIcon->showMessage("","双击打开控制界面",QSystemTrayIcon::Information,1000);
        event->ignore();
    }
    else{
        event->accept();
    }
}
//托盘图标
void Widget::ActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
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
//读取文件
void Widget::ReadFiles(int count)
{
    if(!count)
    {
        ui->fileDirLineEdit->setText(ui->fileDirLineEdit->text()+"::目录为空");
    }
    else{
        //列出目录下的所有文件
        for(int i=0;i<fileInfoList.count();i++)
        {
            fileName = fileInfoList.at(i).fileName();
            filePath = fileInfoList.at(i).filePath();
            QListWidgetItem *listItem = new QListWidgetItem(QIcon(filePath),fileName);

            if(fileInfoList.at(i).fileName()=="."||fileInfoList.at(i).fileName()=="..")// 跳过这两个隐藏目录
            {
                continue;
            }
            if(fileName.endsWith(".mp4")||fileName.endsWith(".avi")||fileName.endsWith(".mov")||fileName.endsWith(".mkv")||
                    fileName.endsWith(".flv")||fileName.endsWith(".f4v")||fileName.endsWith(".rmvb"))
            {
                listItem->setIcon(QIcon("image/video.png"));
            }
            if(fileName.endsWith(".mp3")||fileName.endsWith(".aac")||fileName.endsWith(".wma")||fileName.endsWith(".wav"))
            {
                listItem->setIcon(QIcon("image/music.png"));
            }
            ui->fileListWidget->addItem(listItem);
        }
        ui->fileListWidget->item(0)->setSelected(true);
        ui->fileListWidget->setFocus();//列表焦点
        ui->fileListWidget->setCurrentRow(0);
        temp=ui->fileListWidget->currentRow();//temp计数指向 当前行

        ShowContent();
    }
}
//退出程序
void Widget::exitApplication()
{
    QApplication* app;
    app->exit(0);
    /*
    int i=QMessageBox::warning(this,tr("Warning"),tr("将停用iPad远程控制"),tr("确认"),tr("取消"));
    if(!i) app->exit(0);
    else{
        this->show();
        app->setQuitOnLastWindowClosed(false);
    }
    */
}
//对比数据
void Widget::CompareData(QString str)
{
    if(str=="LAST")
    {
        on_lastContent_clicked();
    }
    else if(str=="NEXT")
    {
        on_nextContent_clicked();
    }
    else if(str=="PAUSE")
    {
        on_videoPlayerPause_clicked();
    }
    else if(str=="STOP")
    {
        on_videoStop_clicked();
    }
    else if(str=="MUTE")
    {
        on_videoMute_clicked();
    }
    else if(str=="ADVANCE")
    {
        on_videoAdvance_clicked();
    }
    else if(str=="REWIND")
    {
        on_videoRewind_clicked();
    }
    else if(str=="VOLUME+")
    {
        player->setMuted(false);
        player->setVolume(player->volume()+10);
    }
    else if(str=="VOLUME-")
    {
        player->setVolume(player->volume()-10);
    }
    else if(str=="LISTLOOP")
    {
        ui->delayLineEdit->setText("5");
        ui->loopCheckBox->setCheckState(Qt::Checked);

        listLoopTime->start(delayTime.toInt()*1000);
        qDebug()<<"e";
    }
    else if(str=="CANCELLOOP")
    {
        listLoopTime->stop();
        ui->delayLineEdit->clear();
        ui->loopCheckBox->setCheckState(Qt::Unchecked);
    }
}
//设置参数
void Widget::configApplication()
{

}
//全局事件
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    //Object
    if(obj==ui->imglabel)
    {
        //MouseEvent
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            if(!autoFlag)
            {
                ui->imglabel->setWindowFlags(Qt::Dialog);//设置QLabel为顶级窗口
                ui->imglabel->showFullScreen();//设置QLabel窗口全屏
                autoFlag=true;
            }
        }
        //KeyboardEvent
        if(event->type()==QEvent::KeyRelease)
        {
            QKeyEvent *e=static_cast<QKeyEvent*>(event);//把QEvent类型转为QKeyEvent
            switch (e->key()) {
            case Qt::Key_Escape:
                if(1)
                {
                    ui->imglabel->setWindowFlags(Qt::SubWindow);//取消QLabel顶级窗口
                    ui->imglabel->showNormal();//退出全屏
                    ui->imglabel->setGeometry(10,20,581,361);//重置x,y,w,h
                    autoFlag=0;
                }
                break;
            case Qt::Key_Left:
                on_lastContent_clicked();
                break;
            case Qt::Key_Right:
                on_nextContent_clicked();
                qDebug()<<"right";
                break;
            case Qt::Key_F8:
                ui->delayLineEdit->setText("2");
                delayTime=ui->delayLineEdit->text();//应该使用int？
                listLoopTime->start(delayTime.toInt()*1000);//启动定时器并设置播放时间间隔
                break;
            case Qt::Key_F4:
                listLoopTime->stop();
                delayTime.clear();
                break;
            default:
                break;
            }
        }
    }
    if(obj==ui->videoWidget)
    {
        if(event->type()==QEvent::MouseButtonDblClick)
        {
            ui->videoWidget->setWindowFlags(Qt::Dialog);//设置QLabel为顶级窗口
            ui->videoWidget->showFullScreen();//设置QLabel窗口全屏
            autoFlag=true;
        }
        if(event->type()==QEvent::KeyRelease)
        {
            QKeyEvent *e=static_cast<QKeyEvent*>(event);//把QEvent类型转为QKeyEvent
            switch (e->key()) {
            case Qt::Key_Escape:
                if(1)
                {
                    ui->videoWidget->setWindowFlags(Qt::SubWindow);//取消QLabel顶级窗口
                    ui->videoWidget->showNormal();//退出全屏
                    ui->videoWidget->setGeometry(10,20,581,361);//重置x,y,w,h
                    autoFlag=0;
                }
                break;
            case Qt::Key_Left:
                on_lastContent_clicked();
                break;
            case Qt::Key_Right:
                on_nextContent_clicked();
                qDebug()<<"right";
                break;
            case Qt::Key_F8:
                ui->delayLineEdit->setText("5");
                delayTime=ui->delayLineEdit->text();//应该使用int？
                listLoopTime->start(delayTime.toInt()*1000);//启动定时器并设置播放时间间隔
                break;
            case Qt::Key_F4:
                listLoopTime->stop();
                delayTime.clear();
                break;
            default:
                break;
            }
        }
    }
    return QObject::eventFilter(obj,event);
}

//上一内容
void Widget::on_lastContent_clicked()
{
    if(!(ui->fileListWidget->count()))
    {
        QMessageBox::about(this, "提示", "请先选择文件");
    }
    else{
        temp=ui->fileListWidget->currentRow();
        if(temp!=0)
        {
            ui->fileListWidget->setCurrentRow(temp-1);
            ShowContent();
        }
        else{
            temp=ui->fileListWidget->count()-1;
            ui->fileListWidget->setCurrentRow(temp);
            ShowContent();
        }
    }
}
//下一内容
void Widget::on_nextContent_clicked()
{
    if(!(ui->fileListWidget->count()))
    {
        QMessageBox::about(this, "提示", "请先选择文件");
    }
    else{
        temp=ui->fileListWidget->currentRow();
        if(temp!=ui->fileListWidget->count()-1)
        {
            ui->fileListWidget->setCurrentRow(temp+1);
            ShowContent();
        }
        else{
            temp=0;
            ui->fileListWidget->setCurrentRow(temp);
            ShowContent();
        }
    }
}
//video播放暂停
void Widget::on_videoPlayerPause_clicked()
{
    if(!player->currentMedia().isNull())
    {
        if(playPause)
        {
            player->pause();
            videoTime->stop();
            ui->videoPlayerPause->setIcon(QIcon("image/bf1.png"));
            playPause=false;
        }
        else if(!playPause)
        {
            player->play();
            videoTime->start();
            ui->videoPlayerPause->setIcon(QIcon("image/bf.png"));
            playPause=true;
        }
    }

}
//video快进5秒
void Widget::on_videoAdvance_clicked()
{
    player->setPosition(player->position()+5000);
}
//video快退5秒
void Widget::on_videoRewind_clicked()
{
    player->setPosition(player->position()-5000);
}
//视频停止播放的检测
void Widget::tryOnStop(QMediaPlayer::State)
{
    qDebug()<<player->state();
}
//video停止
void Widget::on_videoStop_clicked()
{
    if(!player->currentMedia().isNull())
    {
        videoTime->stop();
        player->stop();
        ui->position->setText("00.00.00/00.00.00");
        playPause=false;
        ui->videoPlayerPause->setIcon(QIcon("image/bf.png"));
        ui->videoSlider->setValue(0);
    }
}
//video静音
void Widget::on_videoMute_clicked()
{
    bool bbb=player->isMuted();
    if(!player->currentMedia().isNull())
    {
        if(!player->isMuted())
        {
            player->setMuted(true);
            ui->videoMute->setIcon(QIcon("image/mute.png"));

            qDebug()<<"静音"<<bbb;
        }
        else if(player->isMuted())
        {
            player->setMuted(false);
            ui->videoMute->setIcon(QIcon("image/mute1.png"));
            qDebug()<<"非静音"<<bbb;
        }
    }
}

//列表循环播放按钮
void Widget::on_loopCheckBox_clicked(bool checked)
{
    if(ui->delayLineEdit->text().isEmpty())
    {
        QMessageBox::about(this,"Tip:","请输入间隔时间(秒)!");
        ui->delayLineEdit->setFocus();
        ui->loopCheckBox->setCheckState(Qt::Unchecked);//重置为未选中状态
        loopModel=false;
    }
    else if(ui->fileListWidget->count()==0)
    {
        QMessageBox::about(this,"Tip:","文件播放列表为空");
        ui->loopCheckBox->setCheckState(Qt::Unchecked);//重置为未选中状态
        loopModel=false;
    }else if(checked)
    {
        delayTime=ui->delayLineEdit->text();
        listLoopTime->start(delayTime.toInt()*1000);
        loopModel=true;
    }
    else if(!checked){
        listLoopTime->stop();
        delayTime.clear();
        ui->delayLineEdit->clear();
        loopModel=false;
    }
}
//文件列表单击
void Widget::on_fileListWidget_clicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    Q_UNUSED(index);
    if(ui->loopCheckBox->checkState())
    {
        videoTime->stop();
        listLoopTime->stop();
        delayTime.clear();
        ui->delayLineEdit->clear();
        ui->loopCheckBox->setCheckState(Qt::Unchecked);
    }
    ShowContent();//播放内容
    temp=ui->fileListWidget->currentRow();
}
//文件列表双击播放
void Widget::on_fileListWidget_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    //ing...
}
//视屏播放进度条
void Widget::on_videoTimeOut()
{
    ui->videoSlider->setValue(player->position()*1000/player->duration());

    qint64 posin=player->position()/1000;
    int h,m,s;
    h = posin/3600;
    m = (posin-h*3600)/60;
    s = posin-h*3600-m*60;

    //video时长
    qint64 dura=player->duration()/1000;
    int h1,m1,s1;
    h1 = dura/3600;
    m1 = (dura-h1*3600)/60;
    s1 = dura-h1*3600-m1*60;

    //把int型转化为string类型后再设置为label的text
    ui->position->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).
                          arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0'))
                          +"/"+QString("%1:%2:%3").arg(h1,2,10,QLatin1Char('0')).
                          arg(m1,2,10,QLatin1Char('0')).arg(s1,2,10,QLatin1Char('0')));
    if(player->state()==QMediaPlayer::StoppedState)
    {
       qDebug()<<"停止播放";
       if(loopModel)
       {
           //on_nextContent_clicked();
           listLoopTime->start(delayTime.toInt()*1000);
           qDebug()<<"LOOP=true";
       }
       else{
           player->play();
           qDebug()<<"LOOP=false";
       }
       videoTime->stop();
    }
}
//播放内容
void Widget::ShowContent()
{
    //文件完整路径
    QString file=(fileDir.absolutePath()+"/"+ui->fileListWidget->currentItem()->text());
    qDebug()<<file;
    if(file.endsWith(".jpg")||file.endsWith(".JPG")||file.endsWith(".Jpg")||file.endsWith(".Png")||
            file.endsWith(".bmp")||file.endsWith(".PNG")||file.endsWith(".png"))//判断jpg,png
    {
        if(!player->currentMedia().isNull())
        {
            player->stop();
            videoTime->stop();
            ui->videoWidget->close();
        }
        ui->videoSlider->setValue(0);
        ui->position->setText("00.00.00/00.00.00");
        ui->imglabel->setVisible(true);
        ui->imglabel->setPixmap(QPixmap(file));//直接显示图片
        /*
        ui->imglabel->setWindowFlags(Qt::Dialog);//设置QLabel为顶级窗口
        ui->imglabel->setWindowFlags(ui->imglabel->windowFlags()|Qt::WindowStaysOnTopHint);
        ui->imglabel->showFullScreen();//设置QLabel窗口全屏
*/
        //取消videoWidget顶级窗口
        ui->videoWidget->setWindowFlags(Qt::SubWindow);
        ui->videoWidget->showNormal();//退出全屏
        ui->videoWidget->setGeometry(10,20,581,361);//重置x,y,w,h
        ui->videoWidget->setVisible(false);
    }
    else if(file.endsWith(".gif") ||file.endsWith(".Gig")|| file.endsWith(".GIF"))
    {
        if(!player->currentMedia().isNull())
        {
            player->stop();
            videoTime->stop();
            ui->videoWidget->close();
        }
        ui->videoSlider->setValue(0);
        ui->position->setText("00.00.00/00.00.00");

        QMovie *movie=new QMovie(file);
        ui->imglabel->setVisible(true);
        ui->imglabel->setMovie(movie);
        movie->start();
        /*
        ui->imglabel->setWindowFlags(Qt::Dialog);//设置QLabel为顶级窗口
        ui->imglabel->setWindowFlags(ui->imglabel->windowFlags()|Qt::WindowStaysOnTopHint);
        ui->imglabel->showFullScreen();//设置QLabel窗口全屏
*/
        ui->videoWidget->setWindowFlags(Qt::SubWindow);//取消videoWidget顶级窗口
        ui->videoWidget->showNormal();//退出全屏
        ui->videoWidget->setGeometry(10,20,581,361);//重置x,y,w,h
        ui->videoWidget->close();
    }
    else if(file.endsWith(".mp4")||file.endsWith(".avi")||file.endsWith(".mov")||file.endsWith(".mpeg")||
            file.endsWith(".mkv")||file.endsWith(".flv")||file.endsWith(".f4v")||file.endsWith(".rmvb")||
            file.endsWith(".mp3")||file.endsWith(".wma")||file.endsWith(".aac")||file.endsWith(".wav"))
    {
        if(!player->currentMedia().isNull())
        {
            playPause=false;
            listLoopTime->stop();
            player->stop();
            ui->videoWidget->close();
        }
        videoTime->stop();
        ui->videoWidget->show();
        listLoopTime->stop();
        ui->imglabel->clear();
        ui->imglabel->setVisible(false);
        ui->videoSlider->setValue(0);

        /*
        ui->videoWidget->setWindowFlags(Qt::Dialog);//设置videoWidget为顶级窗口
        ui->videoWidget->setWindowFlags(ui->videoWidget->windowFlags()|Qt::WindowStaysOnTopHint);
        ui->videoWidget->showFullScreen();//设置videoWidget窗口全屏
*/
        playList->clear();
        playList->addMedia(QUrl(file));
        player->setVideoOutput(ui->videoWidget);

        player->setMedia(QUrl::fromLocalFile(file));

        //player->setPlaylist(playList);
        //playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

        player->setVolume(ui->audioSlider->value());
        player->play();

        videoTime->start();
        ui->videoWidget->setAspectRatioMode(Qt::AspectRatioMode(0));//拉伸填充屏幕
        playPause=true;//播放暂停按钮，播放后为真
        ui->videoPlayerPause->setIcon(QIcon("image/bf1.png"));
        loopModel=1;//循环模式，播放后为真
/*
        ui->imglabel->setWindowFlags(Qt::SubWindow);//取消QLabel顶级窗口
        ui->imglabel->showNormal();//退出全屏
        ui->imglabel->setGeometry(10,20,581,361);//重置x,y,w,h
*/
    }
}

//选择文件
void Widget::on_selectFiles_clicked()
{
    filePath=QFileDialog::getOpenFileName(this,"选择文件","D:\\",fileFilter);
    if(filePath.isEmpty())
    {
        qDebug()<<"取消选择";
    }
    else {
        ui->fileListWidget->clear();//
        fileDir=filePath;//
        fileDir.cdUp();//
        fileDir.setNameFilters(fileListFilter);//
        fileInfoList=fileDir.entryInfoList(QDir::Files);//获取dir目录下的所有文件
        ReadFiles(fileInfoList.count());

        //写入文件
        QString sdir=fileDir.absolutePath();
        sdir=QDir::toNativeSeparators(sdir);//路径转换
        ui->fileDirLineEdit->setText(sdir);//显示路径
        QFile writefile("C:/Windows/XcrpConfig.cfg");
        writefile.open(QIODevice::WriteOnly|QIODevice::Text);
        writefile.write(sdir.toUtf8());
        writefile.close();
    }
}





