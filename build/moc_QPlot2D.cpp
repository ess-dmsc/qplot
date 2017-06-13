/****************************************************************************
** Meta object code from reading C++ file 'QPlot2D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qplot/QPlot2D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlot2D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlot__Plot2D_t {
    QByteArrayData data[8];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlot__Plot2D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlot__Plot2D_t qt_meta_stringdata_QPlot__Plot2D = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QPlot::Plot2D"
QT_MOC_LITERAL(1, 14, 11), // "clickedPlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1), // "x"
QT_MOC_LITERAL(4, 29, 1), // "y"
QT_MOC_LITERAL(5, 31, 15), // "Qt::MouseButton"
QT_MOC_LITERAL(6, 47, 6), // "button"
QT_MOC_LITERAL(7, 54, 7) // "zoomOut"

    },
    "QPlot::Plot2D\0clickedPlot\0\0x\0y\0"
    "Qt::MouseButton\0button\0zoomOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlot__Plot2D[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 5,    3,    4,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QPlot::Plot2D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plot2D *_t = static_cast<Plot2D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedPlot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< Qt::MouseButton(*)>(_a[3]))); break;
        case 1: _t->zoomOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Plot2D::*_t)(double , double , Qt::MouseButton );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Plot2D::clickedPlot)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPlot::Plot2D::staticMetaObject = {
    { &GenericPlot::staticMetaObject, qt_meta_stringdata_QPlot__Plot2D.data,
      qt_meta_data_QPlot__Plot2D,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlot::Plot2D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlot::Plot2D::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlot__Plot2D.stringdata0))
        return static_cast<void*>(const_cast< Plot2D*>(this));
    return GenericPlot::qt_metacast(_clname);
}

int QPlot::Plot2D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPlot::Plot2D::clickedPlot(double _t1, double _t2, Qt::MouseButton _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
