/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qvideowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelectFile;
    QAction *actionPlayList;
    QAction *actionTCP;
    QAction *actionUDP;
    QAction *actionListLoop;
    QAction *actionNoLoop;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QPushButton *btnPlayer;
    QVideoWidget *videoWidget;
    QLabel *imglabel;
    QSlider *Slider_positon;
    QSlider *Slider_audio;
    QPushButton *btnStop;
    QPushButton *btnAdvance;
    QPushButton *btnNext;
    QPushButton *btnMute;
    QPushButton *btnLast;
    QPushButton *btnRewind;
    QPushButton *btnSetting;
    QLineEdit *lineEdit_videoTime;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFiles;
    QMenu *menuTeleSet;
    QMenu *menuPlaySet;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(641, 447);
        MainWindow->setMinimumSize(QSize(641, 447));
        MainWindow->setMaximumSize(QSize(641, 447));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(194, 209, 214, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(224, 232, 234, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(97, 104, 107, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(129, 139, 143, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setContextMenuPolicy(Qt::ActionsContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral("image/title16.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral("image/app48.ico"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionSelectFile = new QAction(MainWindow);
        actionSelectFile->setObjectName(QStringLiteral("actionSelectFile"));
        actionPlayList = new QAction(MainWindow);
        actionPlayList->setObjectName(QStringLiteral("actionPlayList"));
        actionTCP = new QAction(MainWindow);
        actionTCP->setObjectName(QStringLiteral("actionTCP"));
        actionTCP->setCheckable(true);
        actionUDP = new QAction(MainWindow);
        actionUDP->setObjectName(QStringLiteral("actionUDP"));
        actionUDP->setCheckable(true);
        actionListLoop = new QAction(MainWindow);
        actionListLoop->setObjectName(QStringLiteral("actionListLoop"));
        actionListLoop->setCheckable(true);
        actionNoLoop = new QAction(MainWindow);
        actionNoLoop->setObjectName(QStringLiteral("actionNoLoop"));
        actionNoLoop->setCheckable(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnPlayer = new QPushButton(centralWidget);
        btnPlayer->setObjectName(QStringLiteral("btnPlayer"));
        btnPlayer->setGeometry(QRect(10, 370, 31, 31));
        btnPlayer->setAutoFillBackground(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral("image/bf.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("image/bf1.png"), QSize(), QIcon::Normal, QIcon::On);
        btnPlayer->setIcon(icon1);
        btnPlayer->setIconSize(QSize(24, 24));
        videoWidget = new QVideoWidget(centralWidget);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->setGeometry(QRect(0, 0, 641, 350));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        videoWidget->setPalette(palette1);
        videoWidget->setAutoFillBackground(true);
        imglabel = new QLabel(videoWidget);
        imglabel->setObjectName(QStringLiteral("imglabel"));
        imglabel->setGeometry(QRect(270, 110, 151, 71));
        Slider_positon = new QSlider(centralWidget);
        Slider_positon->setObjectName(QStringLiteral("Slider_positon"));
        Slider_positon->setGeometry(QRect(0, 350, 641, 20));
        Slider_positon->setOrientation(Qt::Horizontal);
        Slider_audio = new QSlider(centralWidget);
        Slider_audio->setObjectName(QStringLiteral("Slider_audio"));
        Slider_audio->setGeometry(QRect(550, 375, 91, 21));
        Slider_audio->setOrientation(Qt::Horizontal);
        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(290, 370, 31, 31));
        btnStop->setAutoFillBackground(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral("image/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon2);
        btnStop->setIconSize(QSize(16, 16));
        btnAdvance = new QPushButton(centralWidget);
        btnAdvance->setObjectName(QStringLiteral("btnAdvance"));
        btnAdvance->setGeometry(QRect(340, 370, 31, 31));
        btnAdvance->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral("image/advance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvance->setIcon(icon3);
        btnAdvance->setIconSize(QSize(24, 24));
        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(390, 370, 31, 31));
        btnNext->setAutoFillBackground(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral("image/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon4);
        btnNext->setIconSize(QSize(24, 24));
        btnMute = new QPushButton(centralWidget);
        btnMute->setObjectName(QStringLiteral("btnMute"));
        btnMute->setGeometry(QRect(515, 370, 31, 31));
        btnMute->setAutoFillBackground(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral("image/mute1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral("image/mute.png"), QSize(), QIcon::Selected, QIcon::On);
        btnMute->setIcon(icon5);
        btnMute->setCheckable(false);
        btnMute->setChecked(false);
        btnLast = new QPushButton(centralWidget);
        btnLast->setObjectName(QStringLiteral("btnLast"));
        btnLast->setGeometry(QRect(190, 370, 31, 31));
        btnLast->setAutoFillBackground(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral("image/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLast->setIcon(icon6);
        btnLast->setIconSize(QSize(24, 24));
        btnRewind = new QPushButton(centralWidget);
        btnRewind->setObjectName(QStringLiteral("btnRewind"));
        btnRewind->setGeometry(QRect(240, 370, 31, 31));
        btnRewind->setAutoFillBackground(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral("image/rewind.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRewind->setIcon(icon7);
        btnRewind->setIconSize(QSize(24, 24));
        btnSetting = new QPushButton(centralWidget);
        btnSetting->setObjectName(QStringLiteral("btnSetting"));
        btnSetting->setGeometry(QRect(480, 370, 31, 31));
        btnSetting->setAutoFillBackground(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral("image/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetting->setIcon(icon8);
        btnSetting->setCheckable(false);
        btnSetting->setChecked(false);
        lineEdit_videoTime = new QLineEdit(centralWidget);
        lineEdit_videoTime->setObjectName(QStringLiteral("lineEdit_videoTime"));
        lineEdit_videoTime->setGeometry(QRect(55, 375, 113, 20));
        lineEdit_videoTime->setFrame(false);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 19));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        menuFiles->setFocusPolicy(Qt::NoFocus);
        menuFiles->setAcceptDrops(true);
        menuFiles->setSeparatorsCollapsible(false);
        menuFiles->setToolTipsVisible(false);
        menuTeleSet = new QMenu(menuBar);
        menuTeleSet->setObjectName(QStringLiteral("menuTeleSet"));
        menuPlaySet = new QMenu(menuBar);
        menuPlaySet->setObjectName(QStringLiteral("menuPlaySet"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuPlaySet->menuAction());
        menuBar->addAction(menuTeleSet->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFiles->addAction(actionSelectFile);
        menuFiles->addAction(actionPlayList);
        menuFiles->addSeparator();
        menuFiles->addAction(actionExit);
        menuTeleSet->addAction(actionTCP);
        menuTeleSet->addAction(actionUDP);
        menuPlaySet->addAction(actionListLoop);
        menuPlaySet->addAction(actionNoLoop);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSelectFile->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSelectFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPlayList->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPlayList->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionPlayList->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionTCP->setText(QApplication::translate("MainWindow", "TCP \351\200\232\344\277\241", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionTCP->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUDP->setText(QApplication::translate("MainWindow", "UDP\351\200\232\344\277\241", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUDP->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionListLoop->setText(QApplication::translate("MainWindow", "\345\210\227\350\241\250\345\276\252\347\216\257", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionListLoop->setShortcut(QApplication::translate("MainWindow", "Alt+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNoLoop->setText(QApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionNoLoop->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionNoLoop->setShortcut(QApplication::translate("MainWindow", "Shift+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "about", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnPlayer->setToolTip(QApplication::translate("MainWindow", "\346\222\255\346\224\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnPlayer->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnPlayer->setText(QString());
#ifndef QT_NO_SHORTCUT
        btnPlayer->setShortcut(QApplication::translate("MainWindow", "Space", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        imglabel->setText(QApplication::translate("MainWindow", "Xc-RemotePlayer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Slider_audio->setToolTip(QApplication::translate("MainWindow", "\351\237\263\351\207\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Slider_audio->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        btnStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnStop->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnStop->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAdvance->setToolTip(QApplication::translate("MainWindow", "\345\277\253\350\277\233", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnAdvance->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnAdvance->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnNext->setToolTip(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\233\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnNext->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnNext->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMute->setToolTip(QApplication::translate("MainWindow", "\351\235\231\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnMute->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnMute->setText(QString());
#ifndef QT_NO_SHORTCUT
        btnMute->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        btnLast->setToolTip(QApplication::translate("MainWindow", "\344\270\212\344\270\200\346\233\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnLast->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnLast->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnRewind->setToolTip(QApplication::translate("MainWindow", "\345\277\253\351\200\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnRewind->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnRewind->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSetting->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\222\255\346\224\276\345\217\202\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnSetting->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnSetting->setText(QString());
#ifndef QT_NO_SHORTCUT
        btnSetting->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        lineEdit_videoTime->setText(QApplication::translate("MainWindow", " 00.00.00/00.00.00", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QApplication::translate("MainWindow", "\346\234\254\346\234\272IP\357\274\232", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        menuFiles->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        menuFiles->setStatusTip(QApplication::translate("MainWindow", "gch", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        menuFiles->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        menuFiles->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menuTeleSet->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241\350\256\276\347\275\256(&T)", Q_NULLPTR));
        menuPlaySet->setTitle(QApplication::translate("MainWindow", "\346\222\255\346\224\276\350\256\276\347\275\256(&P)", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&A)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
