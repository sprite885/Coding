#ifndef INI_CONFIG_H
#define INI_CONFIG_H

#include <QString>
#include <QSettings>

class ini_config
{
public:
    ini_config();
    virtual ~ini_config();

    //void CreatFile(QString FilePath,QString FileName);
    //目标IP
    QString GetTargetIP();
    void SetTargetIP(QString strTargetIp);
    //目标PORT
    QString GetTargetPort();
    void SetTargetPort(QString strTargetPort);
    //本机UDP端口
    QString GetLocalUdpPort();
    void SetLocalUdpPort(QString strUdpPort);
    //本机TCP端口
    QString GetLocalTcpPort();
    void SetLocalTcpPort(QString strTcpPort);
    //循环播放标志flag
    bool GetListLoop();
    void SetListLoop(bool listloop);
    //循环间隔时间
    QString GetLoopDelayTime();
    void SetLoopDelayTime(QString loopDelayTime);
    //通信标志flag
    bool GetTeleFlag();
    void SetTeleFlag(bool teleflag);
    //文件路径
    QString GetFilesPaht();
    void SetFilesPaht(QString strFilesPaht);

private:
    QString strFileName;
    QSettings *mSettings;
};

#endif // INI_CONFIG_H
