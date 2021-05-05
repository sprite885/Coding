#include "ini_config.h"

#include <QtCore/QtCore>
#include <QFile>
#include <QDebug>

ini_config::ini_config()
{
    strFileName="D:/Config.ini";

    //"Config.ini"配置文件，文件存在则打开，不存在则创建
    mSettings=new QSettings(strFileName,QSettings::IniFormat);
}

ini_config::~ini_config()
{
    delete mSettings;
    mSettings=NULL;
}
//目标IP
QString ini_config::GetTargetIP()
{
     if(mSettings->value("netParameters/TargetIP")=="")
        {
         return "null";
     }
    return mSettings->value("netParameters/TargetIP").toString();
}
//目标IP
void ini_config::SetTargetIP(QString strTargetIp)
{
    mSettings->setValue("netParameters/TargetIP",strTargetIp);
}
//目标端口
QString ini_config::GetTargetPort()
{
    return mSettings->value("netParameters/TargetPort").toString();
}
//目标端口
void ini_config::SetTargetPort(QString strTargetPort)
{
    mSettings->setValue("netParameters/TargetPort",strTargetPort);
}
//本机UDP端口
QString ini_config::GetLocalUdpPort()
{
    return mSettings->value("netParameters/LocalUdpPort").toString();
}
//本机UDP端口
void ini_config::SetLocalUdpPort(QString strUdpPort)
{
    mSettings->setValue("netParameters/LocalUdpPort",strUdpPort);
}
//本机TCP端口
QString ini_config::GetLocalTcpPort()
{
    return mSettings->value("netParameters/LocalTcpPort").toString();
}
//本机TCP端口
void ini_config::SetLocalTcpPort(QString strTcpPort)
{
    mSettings->setValue("netParameters/LocalTcpPort",strTcpPort);
}
//循环播放标志flag
bool ini_config::GetListLoop()
{
    if(mSettings->value("Player/ListLoop")==true)
        return true;
    return false;
}
//循环播放标志flag
void ini_config::SetListLoop(bool listloop)
{
    mSettings->setValue("Player/ListLoop",listloop);
}
//循环间隔时间
QString ini_config::GetLoopDelayTime()
{
    return mSettings->value("Player/LoopDelay").toString();
}
//循环间隔时间
void ini_config::SetLoopDelayTime(QString loopDelayTime)
{
    mSettings->setValue("Player/LoopDelay",loopDelayTime);
}
//通信标志flag
bool ini_config::GetTeleFlag()
{

}
//通信标志flag
void ini_config::SetTeleFlag(bool teleflag)
{

}
//文件路径
QString ini_config::GetFilesPaht()
{
    return mSettings->value("FilePath/filePath").toString();
}
//文件路径
void ini_config::SetFilesPaht(QString strFilesPath)
{
    mSettings->setValue("FilePath/filePath",strFilesPath);
}

