/****************************************************************************
** Meta object code from reading C++ file 'broadcasterstub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawingChat001/BroadcastLib002/broadcasterstub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'broadcasterstub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BroadcasterStub_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BroadcasterStub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BroadcasterStub_t qt_meta_stringdata_BroadcasterStub = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BroadcasterStub"
QT_MOC_LITERAL(1, 16, 9), // "readyRead"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "BroadcasterStub\0readyRead\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BroadcasterStub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void BroadcasterStub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BroadcasterStub *_t = static_cast<BroadcasterStub *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyRead(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BroadcasterStub::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BroadcasterStub.data,
      qt_meta_data_BroadcasterStub,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BroadcasterStub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BroadcasterStub::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BroadcasterStub.stringdata0))
        return static_cast<void*>(const_cast< BroadcasterStub*>(this));
    if (!strcmp(_clname, "Subscriber"))
        return static_cast< Subscriber*>(const_cast< BroadcasterStub*>(this));
    return QObject::qt_metacast(_clname);
}

int BroadcasterStub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
