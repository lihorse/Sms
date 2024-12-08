/****************************************************************************
** Meta object code from reading C++ file 'barvumeter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../barvumeter/barvumeter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barvumeter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BarVUMeter_t {
    QByteArrayData data[20];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BarVUMeter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BarVUMeter_t qt_meta_stringdata_BarVUMeter = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BarVUMeter"
QT_MOC_LITERAL(1, 11, 13), // "valueLChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "valueRChanged"
QT_MOC_LITERAL(4, 40, 11), // "setMinValue"
QT_MOC_LITERAL(5, 52, 8), // "minValue"
QT_MOC_LITERAL(6, 61, 11), // "setMaxValue"
QT_MOC_LITERAL(7, 73, 8), // "maxValue"
QT_MOC_LITERAL(8, 82, 12), // "setLeftValue"
QT_MOC_LITERAL(9, 95, 9), // "leftValue"
QT_MOC_LITERAL(10, 105, 13), // "setRightValue"
QT_MOC_LITERAL(11, 119, 10), // "rightValue"
QT_MOC_LITERAL(12, 130, 10), // "setColorBg"
QT_MOC_LITERAL(13, 141, 7), // "colorBg"
QT_MOC_LITERAL(14, 149, 13), // "setColorValue"
QT_MOC_LITERAL(15, 163, 10), // "colorValue"
QT_MOC_LITERAL(16, 174, 12), // "setColorHigh"
QT_MOC_LITERAL(17, 187, 9), // "colorHigh"
QT_MOC_LITERAL(18, 197, 11), // "setColorLow"
QT_MOC_LITERAL(19, 209, 8) // "colorLow"

    },
    "BarVUMeter\0valueLChanged\0\0valueRChanged\0"
    "setMinValue\0minValue\0setMaxValue\0"
    "maxValue\0setLeftValue\0leftValue\0"
    "setRightValue\0rightValue\0setColorBg\0"
    "colorBg\0setColorValue\0colorValue\0"
    "setColorHigh\0colorHigh\0setColorLow\0"
    "colorLow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BarVUMeter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       8,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   70,    2, 0x0a /* Public */,
       6,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      12,    1,   82,    2, 0x0a /* Public */,
      14,    1,   85,    2, 0x0a /* Public */,
      16,    1,   88,    2, 0x0a /* Public */,
      18,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::QColor,   19,

 // properties: name, type, flags
       5, QMetaType::Double, 0x00095103,
       7, QMetaType::Double, 0x00095103,
       9, QMetaType::Double, 0x00095103,
      11, QMetaType::Double, 0x00095103,
      13, QMetaType::QColor, 0x00095103,
      15, QMetaType::QColor, 0x00095103,
      19, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,

       0        // eod
};

void BarVUMeter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BarVUMeter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueLChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->valueRChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setMinValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setMaxValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setLeftValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setRightValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setColorBg((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setColorValue((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->setColorHigh((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 9: _t->setColorLow((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BarVUMeter::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarVUMeter::valueLChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BarVUMeter::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BarVUMeter::valueRChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BarVUMeter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getMinValue(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->getMaxValue(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getLeftValue(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getRightValue(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getColorBg(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getColorValue(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getColorLow(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getColorHigh(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BarVUMeter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMinValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setMaxValue(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setLeftValue(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setRightValue(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setColorBg(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setColorValue(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setColorLow(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setColorHigh(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BarVUMeter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BarVUMeter.data,
    qt_meta_data_BarVUMeter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BarVUMeter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BarVUMeter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BarVUMeter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BarVUMeter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BarVUMeter::valueLChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BarVUMeter::valueRChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
