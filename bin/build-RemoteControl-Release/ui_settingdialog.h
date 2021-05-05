/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QPushButton *btnSave;
    QLineEdit *lineEdit_filePath;
    QLabel *label_6;
    QTextEdit *textEdit_recv;
    QTextEdit *textEdit_send;
    QLabel *label_7;
    QLabel *label_8;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *lineEdit_UdpPort;
    QSplitter *splitter_5;
    QLabel *label_4;
    QLineEdit *lineEdit_delayTime;
    QSplitter *splitter_4;
    QLabel *label_5;
    QLineEdit *lineEdit_TcpPort;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *lineEdit_targetPort;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *lineEdit_targetIp;
    QPushButton *btnTry;
    QPushButton *btnClear;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(399, 262);
        SettingDialog->setMinimumSize(QSize(0, 0));
        SettingDialog->setMaximumSize(QSize(1024, 768));
        btnSave = new QPushButton(SettingDialog);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(310, 210, 51, 22));
        lineEdit_filePath = new QLineEdit(SettingDialog);
        lineEdit_filePath->setObjectName(QStringLiteral("lineEdit_filePath"));
        lineEdit_filePath->setGeometry(QRect(241, 178, 128, 20));
        label_6 = new QLabel(SettingDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(176, 178, 60, 16));
        textEdit_recv = new QTextEdit(SettingDialog);
        textEdit_recv->setObjectName(QStringLiteral("textEdit_recv"));
        textEdit_recv->setGeometry(QRect(10, 27, 161, 76));
        textEdit_send = new QTextEdit(SettingDialog);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));
        textEdit_send->setGeometry(QRect(10, 125, 161, 76));
        label_7 = new QLabel(SettingDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 48, 16));
        label_8 = new QLabel(SettingDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 108, 48, 16));
        splitter_3 = new QSplitter(SettingDialog);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(176, 87, 191, 20));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        lineEdit_UdpPort = new QLineEdit(splitter_3);
        lineEdit_UdpPort->setObjectName(QStringLiteral("lineEdit_UdpPort"));
        splitter_3->addWidget(lineEdit_UdpPort);
        splitter_5 = new QSplitter(SettingDialog);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(176, 143, 191, 21));
        splitter_5->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_5->addWidget(label_4);
        lineEdit_delayTime = new QLineEdit(splitter_5);
        lineEdit_delayTime->setObjectName(QStringLiteral("lineEdit_delayTime"));
        splitter_5->addWidget(lineEdit_delayTime);
        splitter_4 = new QSplitter(SettingDialog);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(176, 115, 193, 20));
        splitter_4->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_4->addWidget(label_5);
        lineEdit_TcpPort = new QLineEdit(splitter_4);
        lineEdit_TcpPort->setObjectName(QStringLiteral("lineEdit_TcpPort"));
        splitter_4->addWidget(lineEdit_TcpPort);
        splitter_2 = new QSplitter(SettingDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(176, 58, 193, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        lineEdit_targetPort = new QLineEdit(splitter_2);
        lineEdit_targetPort->setObjectName(QStringLiteral("lineEdit_targetPort"));
        splitter_2->addWidget(lineEdit_targetPort);
        splitter = new QSplitter(SettingDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(176, 30, 193, 20));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        lineEdit_targetIp = new QLineEdit(splitter);
        lineEdit_targetIp->setObjectName(QStringLiteral("lineEdit_targetIp"));
        splitter->addWidget(lineEdit_targetIp);
        btnTry = new QPushButton(SettingDialog);
        btnTry->setObjectName(QStringLiteral("btnTry"));
        btnTry->setGeometry(QRect(11, 207, 75, 23));
        btnClear = new QPushButton(SettingDialog);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(92, 207, 75, 23));

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        btnSave->setText(QApplication::translate("SettingDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        label_6->setText(QApplication::translate("SettingDialog", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("SettingDialog", "\346\216\245\346\224\266\345\214\272\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("SettingDialog", "\345\217\221\351\200\201\345\214\272\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingDialog", "\346\234\254\346\234\272UDP\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingDialog", "\345\276\252\347\216\257\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingDialog", "\346\234\254\346\234\272TCP\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingDialog", "\347\233\256\346\240\207\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("SettingDialog", "\347\233\256 \346\240\207 IP\357\274\232", Q_NULLPTR));
        lineEdit_targetIp->setText(QString());
        btnTry->setText(QApplication::translate("SettingDialog", "\346\265\213\350\257\225\351\200\232\344\277\241", Q_NULLPTR));
        btnClear->setText(QApplication::translate("SettingDialog", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
