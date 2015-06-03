/****************************************************************************
** Meta object code from reading C++ file 'friendsmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../congratulations0/friendsmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendsmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FriendsManager_t {
    QByteArrayData data[18];
    char stringdata[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendsManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendsManager_t qt_meta_stringdata_FriendsManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FriendsManager"
QT_MOC_LITERAL(1, 15, 12), // "editTemplate"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "friendsIndex"
QT_MOC_LITERAL(4, 42, 22), // "createEditTemplateView"
QT_MOC_LITERAL(5, 65, 12), // "FriendEntry*"
QT_MOC_LITERAL(6, 78, 15), // "getTemplateById"
QT_MOC_LITERAL(7, 94, 2), // "id"
QT_MOC_LITERAL(8, 97, 14), // "onEditTemplate"
QT_MOC_LITERAL(9, 112, 15), // "onDeleteElement"
QT_MOC_LITERAL(10, 128, 5), // "index"
QT_MOC_LITERAL(11, 134, 16), // "onDeleteTemplate"
QT_MOC_LITERAL(12, 151, 20), // "deletedTemplateIndex"
QT_MOC_LITERAL(13, 172, 21), // "onDbaseInfoGetChanged"
QT_MOC_LITERAL(14, 194, 28), // "onFriendEntryChangedTemplate"
QT_MOC_LITERAL(15, 223, 18), // "AbstractListEntry*"
QT_MOC_LITERAL(16, 242, 10), // "showVkPage"
QT_MOC_LITERAL(17, 253, 21) // "firstDisplayedElement"

    },
    "FriendsManager\0editTemplate\0\0friendsIndex\0"
    "createEditTemplateView\0FriendEntry*\0"
    "getTemplateById\0id\0onEditTemplate\0"
    "onDeleteElement\0index\0onDeleteTemplate\0"
    "deletedTemplateIndex\0onDbaseInfoGetChanged\0"
    "onFriendEntryChangedTemplate\0"
    "AbstractListEntry*\0showVkPage\0"
    "firstDisplayedElement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendsManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   68,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      13,    0,   77,    2, 0x0a /* Public */,
      14,    1,   78,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    1,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::QString, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // properties: name, type, flags
      17, QMetaType::Int, 0x00095103,

       0        // eod
};

void FriendsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendsManager *_t = static_cast<FriendsManager *>(_o);
        switch (_id) {
        case 0: _t->editTemplate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->createEditTemplateView((*reinterpret_cast< FriendEntry*(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getTemplateById((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->onEditTemplate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onDeleteElement((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onDeleteTemplate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onDbaseInfoGetChanged(); break;
        case 7: _t->onFriendEntryChangedTemplate((*reinterpret_cast< AbstractListEntry*(*)>(_a[1]))); break;
        case 8: _t->showVkPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendsManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendsManager::editTemplate)) {
                *result = 0;
            }
        }
        {
            typedef void (FriendsManager::*_t)(FriendEntry * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendsManager::createEditTemplateView)) {
                *result = 1;
            }
        }
        {
            typedef QString (FriendsManager::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendsManager::getTemplateById)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject FriendsManager::staticMetaObject = {
    { &Manager::staticMetaObject, qt_meta_stringdata_FriendsManager.data,
      qt_meta_data_FriendsManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FriendsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FriendsManager.stringdata))
        return static_cast<void*>(const_cast< FriendsManager*>(this));
    return Manager::qt_metacast(_clname);
}

int FriendsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Manager::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getFirstDisplayedElement(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFirstDisplayedElement(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FriendsManager::editTemplate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FriendsManager::createEditTemplateView(FriendEntry * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
QString FriendsManager::getTemplateById(int _t1)const
{
    QString _t0 = QString();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< FriendsManager *>(this), &staticMetaObject, 2, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
