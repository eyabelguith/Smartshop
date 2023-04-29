/****************************************************************************
** Meta object code from reading C++ file 'mailCl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Integration/mailCl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailCl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SmtpCl_t {
    QByteArrayData data[12];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SmtpCl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SmtpCl_t qt_meta_stringdata_SmtpCl = {
    {
QT_MOC_LITERAL(0, 0, 6), // "SmtpCl"
QT_MOC_LITERAL(1, 7, 6), // "status"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 12), // "stateChanged"
QT_MOC_LITERAL(4, 28, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(5, 57, 11), // "socketState"
QT_MOC_LITERAL(6, 69, 13), // "errorReceived"
QT_MOC_LITERAL(7, 83, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(8, 112, 11), // "socketError"
QT_MOC_LITERAL(9, 124, 12), // "disconnected"
QT_MOC_LITERAL(10, 137, 9), // "connected"
QT_MOC_LITERAL(11, 147, 9) // "readyRead"

    },
    "SmtpCl\0status\0\0stateChanged\0"
    "QAbstractSocket::SocketState\0socketState\0"
    "errorReceived\0QAbstractSocket::SocketError\0"
    "socketError\0disconnected\0connected\0"
    "readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SmtpCl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,
      10,    0,   54,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SmtpCl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SmtpCl *_t = static_cast<SmtpCl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->status((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 2: _t->errorReceived((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: _t->disconnected(); break;
        case 4: _t->connected(); break;
        case 5: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SmtpCl::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpCl::status)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SmtpCl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SmtpCl.data,
      qt_meta_data_SmtpCl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SmtpCl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmtpCl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SmtpCl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SmtpCl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SmtpCl::status(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
