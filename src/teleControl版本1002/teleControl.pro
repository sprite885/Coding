#-------------------------------------------------
#
# Project created by QtCreator 2020-11-12T21:47:37
#
#-------------------------------------------------

QT       += core gui network
QT       +=multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XC-RemotePlayer
TEMPLATE = app

VERSION =1.0.0.2
QMAKE_TARGET_PRODUCT=XC-RemotePlayer
QMAKE_TARGET_COMPANY = Jiangsu Xuechuang IntelligentTechnology Co.,Ltd.
QMAKE_TARGET_DESCRIPTION = RemoteControl
QMAKE_TARGET_COPYRIGHT = XCZN.inc.

DEFINES +=APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

RC_ICONS = "image/app32.ico"


