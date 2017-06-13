/****************************************************************************
** Meta object code from reading C++ file 'QPlot1D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qplot/QPlot1D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlot1D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlot__Multi1D_t {
    QByteArrayData data[12];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlot__Multi1D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlot__Multi1D_t qt_meta_stringdata_QPlot__Multi1D = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QPlot::Multi1D"
QT_MOC_LITERAL(1, 15, 11), // "clickedPlot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "x"
QT_MOC_LITERAL(4, 30, 1), // "y"
QT_MOC_LITERAL(5, 32, 15), // "Qt::MouseButton"
QT_MOC_LITERAL(6, 48, 6), // "button"
QT_MOC_LITERAL(7, 55, 7), // "zoomOut"
QT_MOC_LITERAL(8, 63, 12), // "mousePressed"
QT_MOC_LITERAL(9, 76, 12), // "QMouseEvent*"
QT_MOC_LITERAL(10, 89, 13), // "mouseReleased"
QT_MOC_LITERAL(11, 103, 7) // "adjustY"

    },
    "QPlot::Multi1D\0clickedPlot\0\0x\0y\0"
    "Qt::MouseButton\0button\0zoomOut\0"
    "mousePressed\0QMouseEvent*\0mouseReleased\0"
    "adjustY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlot__Multi1D[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x09 /* Protected */,
      10,    1,   50,    2, 0x09 /* Protected */,
      11,    0,   53,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 5,    3,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,

       0        // eod
};

void QPlot::Multi1D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Multi1D *_t = static_cast<Multi1D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedPlot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< Qt::MouseButton(*)>(_a[3]))); break;
        case 1: _t->zoomOut(); break;
        case 2: _t->mousePressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->adjustY(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Multi1D::*_t)(double , double , Qt::MouseButton );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Multi1D::clickedPlot)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPlot::Multi1D::staticMetaObject = {
    { &GenericPlot::staticMetaObject, qt_meta_stringdata_QPlot__Multi1D.data,
      qt_meta_data_QPlot__Multi1D,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlot::Multi1D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlot::Multi1D::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlot__Multi1D.stringdata0))
        return static_cast<void*>(const_cast< Multi1D*>(this));
    return GenericPlot::qt_metacast(_clname);
}

int QPlot::Multi1D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QPlot::Multi1D::clickedPlot(double _t1, double _t2, Qt::MouseButton _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
