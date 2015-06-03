/****************************************************************************
** Meta object code from reading C++ file 'vkauthviewmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../congratulations0/vkauthviewmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vkauthviewmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VkAuthViewManager_t {
    QByteArrayData data[9];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VkAuthViewManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VkAuthViewManager_t qt_meta_stringdata_VkAuthViewManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VkAuthViewManager"
QT_MOC_LITERAL(1, 18, 14), // "storeAuthToken"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "redirectedUrl"
QT_MOC_LITERAL(4, 48, 11), // "authIsValid"
QT_MOC_LITERAL(5, 60, 14), // "onAuthComplete"
QT_MOC_LITERAL(6, 75, 13), // "onAuthIsValid"
QT_MOC_LITERAL(7, 89, 20), // "wasAuthenticatedFlag"
QT_MOC_LITERAL(8, 110, 17) // "authenticationUrl"

    },
    "VkAuthViewManager\0storeAuthToken\0\0"
    "redirectedUrl\0authIsValid\0onAuthComplete\0"
    "onAuthIsValid\0wasAuthenticatedFlag\0"
    "authenticationUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VkAuthViewManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,

 // properties: name, type, flags
       7, QMetaType::Bool, 0x00095001,
       8, QMetaType::QString, 0x00095001,

       0        // eod
};

void VkAuthViewManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VkAuthViewManager *_t = static_cast<VkAuthViewManager *>(_o);
        switch (_id) {
        case 0: _t->storeAuthToken((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { bool _r = _t->authIsValid((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->onAuthComplete((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { bool _r = _t->onAuthIsValid((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VkAuthViewManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VkAuthViewManager::storeAuthToken)) {
                *result = 0;
            }
        }
        {
            typedef bool (VkAuthViewManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VkAuthViewManager::authIsValid)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VkAuthViewManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VkAuthViewManager.data,
      qt_meta_data_VkAuthViewManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VkAuthViewManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VkAuthViewManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VkAuthViewManager.stringdata))
        return static_cast<void*>(const_cast< VkAuthViewManager*>(this));
    return QObject::qt_metacast(_clname);
}

int VkAuthViewManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = getAuthFlag(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getAuthUrl(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VkAuthViewManager::storeAuthToken(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
bool VkAuthViewManager::authIsValid(const QString & _t1)
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
