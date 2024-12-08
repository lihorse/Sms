/****************************************************************************
** Meta object code from reading C++ file 'barvolume.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../barvolume/barvolume.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barvolume.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BarVolume_t {
    QByteArrayData data[24];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BarVolume_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BarVolume_t qt_meta_stringdata_BarVolume = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BarVolume"
QT_MOC_LITERAL(1, 10, 8), // "setValue"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "value"
QT_MOC_LITERAL(4, 26, 7), // "setStep"
QT_MOC_LITERAL(5, 34, 4), // "step"
QT_MOC_LITERAL(6, 39, 8), // "setSpace"
QT_MOC_LITERAL(7, 48, 5), // "space"
QT_MOC_LITERAL(8, 54, 10), // "setPadding"
QT_MOC_LITERAL(9, 65, 7), // "padding"
QT_MOC_LITERAL(10, 73, 9), // "setRadius"
QT_MOC_LITERAL(11, 83, 6), // "radius"
QT_MOC_LITERAL(12, 90, 15), // "setBgColorStart"
QT_MOC_LITERAL(13, 106, 12), // "bgColorStart"
QT_MOC_LITERAL(14, 119, 13), // "setBgColorEnd"
QT_MOC_LITERAL(15, 133, 10), // "bgColorEnd"
QT_MOC_LITERAL(16, 144, 13), // "setBarBgColor"
QT_MOC_LITERAL(17, 158, 10), // "barBgColor"
QT_MOC_LITERAL(18, 169, 16), // "setBarColorStart"
QT_MOC_LITERAL(19, 186, 13), // "barColorStart"
QT_MOC_LITERAL(20, 200, 14), // "setBarColorMid"
QT_MOC_LITERAL(21, 215, 11), // "barColorMid"
QT_MOC_LITERAL(22, 227, 14), // "setBarColorEnd"
QT_MOC_LITERAL(23, 242, 11) // "barColorEnd"

    },
    "BarVolume\0setValue\0\0value\0setStep\0"
    "step\0setSpace\0space\0setPadding\0padding\0"
    "setRadius\0radius\0setBgColorStart\0"
    "bgColorStart\0setBgColorEnd\0bgColorEnd\0"
    "setBarBgColor\0barBgColor\0setBarColorStart\0"
    "barColorStart\0setBarColorMid\0barColorMid\0"
    "setBarColorEnd\0barColorEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BarVolume[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      11,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    1,   72,    2, 0x0a /* Public */,
       6,    1,   75,    2, 0x0a /* Public */,
       8,    1,   78,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      16,    1,   90,    2, 0x0a /* Public */,
      18,    1,   93,    2, 0x0a /* Public */,
      20,    1,   96,    2, 0x0a /* Public */,
      22,    1,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::QColor,   19,
    QMetaType::Void, QMetaType::QColor,   21,
    QMetaType::Void, QMetaType::QColor,   23,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00095103,
       5, QMetaType::Int, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,
      11, QMetaType::Int, 0x00095103,
      13, QMetaType::QColor, 0x00095103,
      15, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      19, QMetaType::QColor, 0x00095103,
      21, QMetaType::QColor, 0x00095103,
      23, QMetaType::QColor, 0x00095103,

       0        // eod
};

void BarVolume::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BarVolume *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setPadding((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setBgColorStart((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: _t->setBgColorEnd((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->setBarBgColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->setBarColorStart((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 9: _t->setBarColorMid((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 10: _t->setBarColorEnd((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BarVolume *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getStep(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getSpace(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getPadding(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getRadius(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getBgColorStart(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getBgColorEnd(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getBarBgColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getBarColorStart(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getBarColorMid(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getBarColorEnd(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BarVolume *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setStep(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setSpace(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setPadding(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setRadius(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setBgColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setBgColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setBarBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setBarColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setBarColorMid(*reinterpret_cast< QColor*>(_v)); break;
        case 10: _t->setBarColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BarVolume::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BarVolume.data,
    qt_meta_data_BarVolume,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BarVolume::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BarVolume::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BarVolume.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BarVolume::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
