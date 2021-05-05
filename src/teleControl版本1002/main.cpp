#include "widget.h"
#include <QApplication>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    //高清屏幕自适应
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    QSharedMemory shared("try");
    if(shared.attach())
    {
        //QMessageBox::warning(NULL,"Warning", "Program started");
        return 0;
    }
    shared.create(1);
    QApplication a(argc, argv);
    Widget w;
    w.setWindowIcon(QIcon(":/image/title16.ico"));
    w.setWindowTitle("XC-RemotePlayer");
    //w.setWindowFlags(w.windowFlags()|Qt::WindowStaysOnTopHint);//窗口最前端显示
    w.show();//不显示主窗口

    return a.exec();
}
