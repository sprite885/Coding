#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QDir>

#include "settingdialog.h"
#include "ui_settingdialog.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent *event);//重写窗口关闭事件

protected:

    bool eventFilter(QObject *obj,QEvent *event);//全局事件函数

private slots:
    void RecvData();//接收数据函数
    void CompareData(QString str);//对比数据函数
    void ActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);//系统托盘图标函数

    void ReadFiles(int count);//读取文件
    void ShowContent();//播放选择内容函数

    void on_actionSelectFile_triggered();

    void on_actionPlayList_triggered();

    void on_actionTCP_triggered();

    void on_actionUDP_triggered();

    void on_actionListLoop_triggered();

    void on_actionNoLoop_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_btnPlayer_clicked();

    void on_btnLast_clicked();

    void on_btnRewind_clicked();

    void on_btnStop_clicked();

    void on_btnAdvance_clicked();

    void on_btnNext_clicked();

    void on_btnMute_clicked();

    void on_btnSetting_clicked();

private:
    Ui::MainWindow *ui;

    SettingDialog *SetDialog;

    //托盘图标
    QSystemTrayIcon *sysTrayIcon;//系统图标
    QAction *openApp;//打开窗口
    QAction *configApp;//
    QAction *quit;//退出程序
    QMenu *menu;//系统托盘菜单

    QDir fileDir;//目录
    QString fileName;//文件名
    QString filePath;//文件路径
    QString fileFilter;//文件过滤
    QStringList fileListFilter;//列表过滤
};

#endif // MAINWINDOW_H
