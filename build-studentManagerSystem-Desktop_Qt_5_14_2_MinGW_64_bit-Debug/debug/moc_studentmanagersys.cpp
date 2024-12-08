/****************************************************************************
** Meta object code from reading C++ file 'studentmanagersys.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../studentManagerSystem/studentmanagersys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentmanagersys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StudentManagerSys_t {
    QByteArrayData data[19];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudentManagerSys_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudentManagerSys_t qt_meta_stringdata_StudentManagerSys = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StudentManagerSys"
QT_MOC_LITERAL(1, 18, 12), // "onlogincheck"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "username"
QT_MOC_LITERAL(4, 41, 8), // "password"
QT_MOC_LITERAL(5, 50, 5), // "level"
QT_MOC_LITERAL(6, 56, 15), // "on_btn1_clicked"
QT_MOC_LITERAL(7, 72, 15), // "on_btn2_clicked"
QT_MOC_LITERAL(8, 88, 15), // "on_btn3_clicked"
QT_MOC_LITERAL(9, 104, 15), // "on_btn4_clicked"
QT_MOC_LITERAL(10, 120, 15), // "on_btn5_clicked"
QT_MOC_LITERAL(11, 136, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 158, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(13, 182, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 206, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(15, 230, 22), // "on_btnClassAdd_clicked"
QT_MOC_LITERAL(16, 253, 22), // "on_btnClassDel_clicked"
QT_MOC_LITERAL(17, 276, 25), // "on_btnClassUpdate_clicked"
QT_MOC_LITERAL(18, 302, 22) // "on_btnClassGet_clicked"

    },
    "StudentManagerSys\0onlogincheck\0\0"
    "username\0password\0level\0on_btn1_clicked\0"
    "on_btn2_clicked\0on_btn3_clicked\0"
    "on_btn4_clicked\0on_btn5_clicked\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_4_clicked\0"
    "on_btnClassAdd_clicked\0on_btnClassDel_clicked\0"
    "on_btnClassUpdate_clicked\0"
    "on_btnClassGet_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudentManagerSys[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
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

void StudentManagerSys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StudentManagerSys *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onlogincheck((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->on_btn1_clicked(); break;
        case 2: _t->on_btn2_clicked(); break;
        case 3: _t->on_btn3_clicked(); break;
        case 4: _t->on_btn4_clicked(); break;
        case 5: _t->on_btn5_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->on_btnClassAdd_clicked(); break;
        case 11: _t->on_btnClassDel_clicked(); break;
        case 12: _t->on_btnClassUpdate_clicked(); break;
        case 13: _t->on_btnClassGet_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StudentManagerSys::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_StudentManagerSys.data,
    qt_meta_data_StudentManagerSys,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StudentManagerSys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentManagerSys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StudentManagerSys.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int StudentManagerSys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
