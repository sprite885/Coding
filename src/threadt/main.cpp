#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QSharedMemory>
#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QScreen>

int main(int argc, char *argv[])
{
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

    QApplication a(argc, argv);

    Widget w;
    w.show();

/*
    w.move(0,0);
    w.resize(640,400);


    QScreen *scr=QGuiApplication::primaryScreen();
    QRect mm=scr->availableGeometry();
    int sw=mm.width();
    int sh=mm.height();
    qDebug()<<"screen:"<<sw<<"X"<<sh;

    //w.showFullScreen();

    qDebug()<<w.width()<<"X"<<w.height()<<endl;

*/
    return a.exec();
}
