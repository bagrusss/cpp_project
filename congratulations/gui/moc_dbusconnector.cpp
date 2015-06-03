/****************************************************************************
** Meta object code from reading C++ file 'dbusconnector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../congratulations0/dbusconnector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbusconnector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DBusConnector_t {
    QByteArrayData data[13];
    char stringdata[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DBusConnector_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DBusConnector_t qt_meta_stringdata_DBusConnector = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 15),
QT_MOC_LITERAL(2, 30, 18),
QT_MOC_LITERAL(3, 49, 21),
QT_MOC_LITERAL(4, 71, 0),
QT_MOC_LITERAL(5, 72, 19),
QT_MOC_LITERAL(6, 92, 22),
QT_MOC_LITERAL(7, 115, 23),
QT_MOC_LITERAL(8, 139, 22),
QT_MOC_LITERAL(9, 162, 20),
QT_MOC_LITERAL(10, 183, 23),
QT_MOC_LITERAL(11, 207, 24),
QT_MOC_LITERAL(12, 232, 18)
    },
    "DBusConnector\0D-Bus Interface\0"
    "congratulator.dbus\0friendsInfoHasChanged\0"
    "\0bdaysInfoHasChanged\0settingsInfoHasChanged\0"
    "templatesInfoHasChanged\0announceFriendsChanges\0"
    "announceBdaysChanges\0announceSettingsChanges\0"
    "announceTemplatesChanges\0connectAndAnnounce\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusConnector[] = {

 // content:
       7,       // revision
       0,       // classname
       1,   14, // classinfo
       9,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   61,    4, 0x05,
       5,    0,   62,    4, 0x05,
       6,    0,   63,    4, 0x05,
       7,    0,   64,    4, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    4, 0x4a,
       9,    0,   66,    4, 0x4a,
      10,    0,   67,    4, 0x4a,
      11,    0,   68,    4, 0x4a,
      12,    1,   69,    4, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void DBusConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBusConnector *_t = static_cast<DBusConnector *>(_o);
        switch (_id) {
        case 0: _t->friendsInfoHasChanged(); break;
        case 1: _t->bdaysInfoHasChanged(); break;
        case 2: _t->settingsInfoHasChanged(); break;
        case 3: _t->templatesInfoHasChanged(); break;
        case 4: _t->announceFriendsChanges(); break;
        case 5: _t->announceBdaysChanges(); break;
        case 6: _t->announceSettingsChanges(); break;
        case 7: _t->announceTemplatesChanges(); break;
        case 8: _t->connectAndAnnounce((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DBusConnector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBusConnector::friendsInfoHasChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DBusConnector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBusConnector::bdaysInfoHasChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DBusConnector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBusConnector::settingsInfoHasChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (DBusConnector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DBusConnector::templatesInfoHasChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DBusConnector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBusConnector.data,
      qt_meta_data_DBusConnector,  qt_static_metacall, 0, 0}
};


const QMetaObject *DBusConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DBusConnector.stringdata))
        return static_cast<void*>(const_cast< DBusConnector*>(this));
    return QObject::qt_metacast(_clname);
}

int DBusConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DBusConnector::friendsInfoHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DBusConnector::bdaysInfoHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DBusConnector::settingsInfoHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void DBusConnector::templatesInfoHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
