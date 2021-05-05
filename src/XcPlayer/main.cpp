#include "widget.h"
#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //高清屏幕自适应
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    //只运行一个实例
    QSharedMemory shared("try");
    if(shared.attach())
        return 0;
    shared.create(1);


    Widget w;
    //去掉标题栏
   // w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();


    return a.exec();
}
