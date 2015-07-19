/****************************************************************************
** Meta object code from reading C++ file 'netshapespace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawingChat001/NetDraw001/model/netshapespace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netshapespace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetShapeSpace_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetShapeSpace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetShapeSpace_t qt_meta_stringdata_NetShapeSpace = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetShapeSpace"
QT_MOC_LITERAL(1, 14, 16), // "netStatusChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "NetStatus"
QT_MOC_LITERAL(4, 42, 11), // "startListen"
QT_MOC_LITERAL(5, 54, 10), // "stopListen"
QT_MOC_LITERAL(6, 65, 13), // "connectToHost"
QT_MOC_LITERAL(7, 79, 18) // "disconnectFromHost"

    },
    "NetShapeSpace\0netStatusChanged\0\0"
    "NetStatus\0startListen\0stopListen\0"
    "connectToHost\0disconnectFromHost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetShapeSpace[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NetShapeSpace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetShapeSpace *_t = static_cast<NetShapeSpace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->netStatusChanged((*reinterpret_cast< NetStatus(*)>(_a[1]))); break;
        case 1: _t->startListen(); break;
        case 2: _t->stopListen(); break;
        case 3: _t->connectToHost(); break;
        case 4: _t->disconnectFromHost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetShapeSpace::*_t)(NetStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetShapeSpace::netStatusChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NetShapeSpace::staticMetaObject = {
    { &ShapeSpace::staticMetaObject, qt_meta_stringdata_NetShapeSpace.data,
      qt_meta_data_NetShapeSpace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetShapeSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetShapeSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetShapeSpace.stringdata0))
        return static_cast<void*>(const_cast< NetShapeSpace*>(this));
    if (!strcmp(_clname, "Subscriber"))
        return static_cast< Subscriber*>(const_cast< NetShapeSpace*>(this));
    return ShapeSpace::qt_metacast(_clname);
}

int NetShapeSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ShapeSpace::qt_metacall(_c, _id, _a);
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
void NetShapeSpace::netStatusChanged(NetStatus _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
