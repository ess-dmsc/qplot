/****************************************************************************
** Meta object code from reading C++ file 'QPlotDraggable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qplot/QPlotDraggable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPlotDraggable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlot__Draggable_t {
    QByteArrayData data[16];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlot__Draggable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlot__Draggable_t qt_meta_stringdata_QPlot__Draggable = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QPlot::Draggable"
QT_MOC_LITERAL(1, 17, 5), // "moved"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "pos"
QT_MOC_LITERAL(4, 28, 13), // "stoppedMoving"
QT_MOC_LITERAL(5, 42, 4), // "move"
QT_MOC_LITERAL(6, 47, 1), // "x"
QT_MOC_LITERAL(7, 49, 1), // "y"
QT_MOC_LITERAL(8, 51, 12), // "signalNeeded"
QT_MOC_LITERAL(9, 64, 6), // "movePx"
QT_MOC_LITERAL(10, 71, 7), // "stopMov"
QT_MOC_LITERAL(11, 79, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 92, 3), // "evt"
QT_MOC_LITERAL(13, 96, 11), // "onMouseMove"
QT_MOC_LITERAL(14, 108, 5), // "event"
QT_MOC_LITERAL(15, 114, 15) // "moveToWantedPos"

    },
    "QPlot::Draggable\0moved\0\0pos\0stoppedMoving\0"
    "move\0x\0y\0signalNeeded\0movePx\0stopMov\0"
    "QMouseEvent*\0evt\0onMouseMove\0event\0"
    "moveToWantedPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlot__Draggable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   58,    2, 0x0a /* Public */,
       5,    2,   65,    2, 0x2a /* Public | MethodCloned */,
       9,    2,   70,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   14,
    QMetaType::Void,

       0        // eod
};

void QPlot::Draggable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Draggable *_t = static_cast<Draggable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moved((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->stoppedMoving(); break;
        case 2: _t->move((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->move((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->movePx((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->stopMov((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->onMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->moveToWantedPos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Draggable::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Draggable::moved)) {
                *result = 0;
            }
        }
        {
            typedef void (Draggable::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Draggable::stoppedMoving)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QPlot::Draggable::staticMetaObject = {
    { &QCPItemLine::staticMetaObject, qt_meta_stringdata_QPlot__Draggable.data,
      qt_meta_data_QPlot__Draggable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlot::Draggable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlot::Draggable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlot__Draggable.stringdata0))
        return static_cast<void*>(const_cast< Draggable*>(this));
    return QCPItemLine::qt_metacast(_clname);
}

int QPlot::Draggable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCPItemLine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QPlot::Draggable::moved(const QPointF & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QPlot::Draggable::stoppedMoving()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
