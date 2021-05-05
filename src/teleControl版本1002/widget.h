#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QEvent>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QHostInfo>
#include <QMovie>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QStringList>
#include <QSystemTrayIcon>
#include <QTime>
#include <QThread>
#include <QVideoWidget>
#include <windows.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    //系统托盘图标
    QSystemTrayIcon *sysTrayIcon;//系统图标
    QAction *openApp;//打开窗口
    QAction *configApp;//
    QAction *quit;//退出程序
    QMenu *menu;//系统托盘菜单
    //UDP-指令收发
    QUdpSocket udpSocket;//UDP,接收指令
    QHostAddress targetIP;//目标IP
    quint16 targetPort;//目标端口
    QHostAddress localIP;//本机IP
    quint16 localPort;//本机端口

private:
    void exitApplication();//退出程序函数
    void closeEvent(QCloseEvent * event);//重写窗口关闭事件
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void RecvData();//接收数据函数
    void CompareData(QString str);//对比数据函数
    void ActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);//系统托盘图标函数

    void IpTimeOut();//
    void ShowContent();//播放选择内容函数
    void on_videoTimeOut();//
    void ReadFiles(int count);//读取文件

    void configApplication();//
    void on_selectFiles_clicked();
    void on_lastContent_clicked();
    void on_nextContent_clicked();
    void on_loopCheckBox_clicked(bool checked);
    void on_fileListWidget_clicked(const QModelIndex &index);

    void on_btnSendData_clicked();
    void on_videoPlayerPause_clicked();
    void on_videoStop_clicked();
    void on_videoMute_clicked();
    void on_videoAdvance_clicked();
    void on_videoRewind_clicked();
    void tryOnStop(QMediaPlayer::State);

    void on_fileListWidget_doubleClicked(const QModelIndex &index);

protected:
    bool eventFilter(QObject *obj,QEvent *event);//全局事件函数

private:
    Ui::Widget *ui;

    int temp=0;//当前文件位置
    int fileNumber=0;//文件在列表中的位置数
    int fileSum=0;//文件总数

    QTimer *readIpTime;//初始化循环读IP
    QTimer *videoTime;//video播放时间
    QTimer *listLoopTime;//列表循环时间
    QString delayTime;//间隔时间

    QDir fileDir;//目录
    QString fileName;//文件名
    QString filePath;//文件路径
    QString fileFilter;//文件过滤
    QStringList fileListFilter;//列表过滤
    QFileInfoList fileInfoList;//文件列表

    QMediaPlayer *player;//视频文件播放
    QMediaPlaylist *playList;//视频文件列表

    bool playPause=false;//播放暂停
    bool autoFlag=false;//自动标志位
    bool loopModel=false;//播放模式

    //TCP客户端-发送文件

    //TCP服务端-接收文件
    QTcpSocket *serverTcpSocked;//TCP
    QTcpServer *clientTcpServer;//TCP
    QString objIP;//发送者IP
    quint16 objPort;//发送者端口
    quint16 serverPort;//设置接收端口
    QByteArray recvBlick;//接收文件块
};

#endif // WIDGET_H




























