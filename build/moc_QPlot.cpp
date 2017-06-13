/****************************************************************************
** Meta object code from reading C++ file 'QPlot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qplot/QPlot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlot__GenericPlot_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlot__GenericPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlot__GenericPlot_t qt_meta_stringdata_QPlot__GenericPlot = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QPlot::GenericPlot"
QT_MOC_LITERAL(1, 19, 10), // "mouseHover"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "x"
QT_MOC_LITERAL(4, 33, 1), // "y"
QT_MOC_LITERAL(5, 35, 17), // "shiftStateChanged"
QT_MOC_LITERAL(6, 53, 7), // "zoomOut"
QT_MOC_LITERAL(7, 61, 10), // "exportPlot"
QT_MOC_LITERAL(8, 72, 8), // "QAction*"
QT_MOC_LITERAL(9, 81, 14) // "optionsChanged"

    },
    "QPlot::GenericPlot\0mouseHover\0\0x\0y\0"
    "shiftStateChanged\0zoomOut\0exportPlot\0"
    "QAction*\0optionsChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlot__GenericPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   47,    2, 0x0a /* Public */,
       7,    1,   48,    2, 0x09 /* Protected */,
       9,    1,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void QPlot::GenericPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenericPlot *_t = static_cast<GenericPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseHover((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->shiftStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->exportPlot((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->optionsChanged((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenericPlot::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericPlot::mouseHover)) {
                *result = 0;
            }
        }
        {
            typedef void (GenericPlot::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericPlot::shiftStateChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QPlot::GenericPlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_QPlot__GenericPlot.data,
      qt_meta_data_QPlot__GenericPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlot::GenericPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlot::GenericPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlot__GenericPlot.stringdata0))
        return static_cast<void*>(const_cast< GenericPlot*>(this));
    return QCustomPlot::qt_metacast(_clname);
}

int QPlot::GenericPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QPlot::GenericPlot::mouseHover(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QPlot::GenericPlot::shiftStateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
