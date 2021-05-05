/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/RemoteControl/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[496];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "RecvData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "CompareData"
QT_MOC_LITERAL(4, 33, 3), // "str"
QT_MOC_LITERAL(5, 37, 20), // "ActivatedSysTrayIcon"
QT_MOC_LITERAL(6, 58, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(7, 92, 6), // "reason"
QT_MOC_LITERAL(8, 99, 9), // "ReadFiles"
QT_MOC_LITERAL(9, 109, 5), // "count"
QT_MOC_LITERAL(10, 115, 11), // "ShowContent"
QT_MOC_LITERAL(11, 127, 29), // "on_actionSelectFile_triggered"
QT_MOC_LITERAL(12, 157, 27), // "on_actionPlayList_triggered"
QT_MOC_LITERAL(13, 185, 22), // "on_actionTCP_triggered"
QT_MOC_LITERAL(14, 208, 22), // "on_actionUDP_triggered"
QT_MOC_LITERAL(15, 231, 27), // "on_actionListLoop_triggered"
QT_MOC_LITERAL(16, 259, 25), // "on_actionNoLoop_triggered"
QT_MOC_LITERAL(17, 285, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(18, 309, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(19, 334, 20), // "on_btnPlayer_clicked"
QT_MOC_LITERAL(20, 355, 18), // "on_btnLast_clicked"
QT_MOC_LITERAL(21, 374, 20), // "on_btnRewind_clicked"
QT_MOC_LITERAL(22, 395, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(23, 414, 21), // "on_btnAdvance_clicked"
QT_MOC_LITERAL(24, 436, 18), // "on_btnNext_clicked"
QT_MOC_LITERAL(25, 455, 18), // "on_btnMute_clicked"
QT_MOC_LITERAL(26, 474, 21) // "on_btnSetting_clicked"

    },
    "MainWindow\0RecvData\0\0CompareData\0str\0"
    "ActivatedSysTrayIcon\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0ReadFiles\0count\0ShowContent\0"
    "on_actionSelectFile_triggered\0"
    "on_actionPlayList_triggered\0"
    "on_actionTCP_triggered\0on_actionUDP_triggered\0"
    "on_actionListLoop_triggered\0"
    "on_actionNoLoop_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0on_btnPlayer_clicked\0"
    "on_btnLast_clicked\0on_btnRewind_clicked\0"
    "on_btnStop_clicked\0on_btnAdvance_clicked\0"
    "on_btnNext_clicked\0on_btnMute_clicked\0"
    "on_btnSetting_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08 /* Private */,
       3,    1,  120,    2, 0x08 /* Private */,
       5,    1,  123,    2, 0x08 /* Private */,
       8,    1,  126,    2, 0x08 /* Private */,
      10,    0,  129,    2, 0x08 /* Private */,
      11,    0,  130,    2, 0x08 /* Private */,
      12,    0,  131,    2, 0x08 /* Private */,
      13,    0,  132,    2, 0x08 /* Private */,
      14,    0,  133,    2, 0x08 /* Private */,
      15,    0,  134,    2, 0x08 /* Private */,
      16,    0,  135,    2, 0x08 /* Private */,
      17,    0,  136,    2, 0x08 /* Private */,
      18,    0,  137,    2, 0x08 /* Private */,
      19,    0,  138,    2, 0x08 /* Private */,
      20,    0,  139,    2, 0x08 /* Private */,
      21,    0,  140,    2, 0x08 /* Private */,
      22,    0,  141,    2, 0x08 /* Private */,
      23,    0,  142,    2, 0x08 /* Private */,
      24,    0,  143,    2, 0x08 /* Private */,
      25,    0,  144,    2, 0x08 /* Private */,
      26,    0,  145,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RecvData(); break;
        case 1: _t->CompareData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ActivatedSysTrayIcon((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 3: _t->ReadFiles((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ShowContent(); break;
        case 5: _t->on_actionSelectFile_triggered(); break;
        case 6: _t->on_actionPlayList_triggered(); break;
        case 7: _t->on_actionTCP_triggered(); break;
        case 8: _t->on_actionUDP_triggered(); break;
        case 9: _t->on_actionListLoop_triggered(); break;
        case 10: _t->on_actionNoLoop_triggered(); break;
        case 11: _t->on_actionExit_triggered(); break;
        case 12: _t->on_actionAbout_triggered(); break;
        case 13: _t->on_btnPlayer_clicked(); break;
        case 14: _t->on_btnLast_clicked(); break;
        case 15: _t->on_btnRewind_clicked(); break;
        case 16: _t->on_btnStop_clicked(); break;
        case 17: _t->on_btnAdvance_clicked(); break;
        case 18: _t->on_btnNext_clicked(); break;
        case 19: _t->on_btnMute_clicked(); break;
        case 20: _t->on_btnSetting_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
