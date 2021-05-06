#-------------------------------------------------
#
# Project created by QtCreator 2020-12-08T22:21:23
#
#-------------------------------------------------

QT       += core gui
QT       += network sql serialport
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RemoteControl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#版本
VERSION =1.1.0.2
#程序信息
QMAKE_TARGET_PRODUCT=XC-RemotePlayer
QMAKE_TARGET_COMPANY = JiangsuXuechuangIntelligentTechnology Co.,Ltd.
QMAKE_TARGET_DESCRIPTION = RemoteControl
QMAKE_TARGET_COPYRIGHT =Copyright xczn.inc.

DEFINES +=APP_VERSION=\\\"$$VERSION\\\"

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ini_config.cpp \
    settingdialog.cpp

HEADERS += \
        mainwindow.h \
    ini_config.h \
    settingdialog.h

FORMS += \
        mainwindow.ui \
    settingdialog.ui

#ICON
#RC_ICONS = "image/app48.ico"
#DISTFILES += \
#    image/bf.png \
 #   image/advance.png \
  #  image/bf1.png \
   # image/exit.png \
    #image/last.png \
#    image/music.png \
 #   image/mute.png \
  #  image/mute1.png \
   # image/next.png \
    #image/open.png \
#    image/rewind.png \
 #   image/setting.png \
  #  image/shutdown.png \
   # image/stop.png \
    #image/video.png
