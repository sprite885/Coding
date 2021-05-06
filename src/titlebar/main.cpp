#include "titlebar.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TitleBar *titlebar = new TitleBar();
    titlebar w;
    w.show();

    return a.exec();
}
