#include "mainwindow.h"
#include <QApplication>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    //自适应屏幕
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    //只允许一个实例
    QSharedMemory shared("try");
    if(shared.attach())
    {
        QMessageBox::warning(NULL,"Warning","Program Started...");
        return 0;
    }
    shared.create(1);
    //
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("image/title32.ico"));
    w.setWindowTitle("XC-RemotePlayer");
    w.show();

    return a.exec();
}
