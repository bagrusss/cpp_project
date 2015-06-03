/****************************************************************************
** Meta object code from reading C++ file 'personaltemplatemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../congratulations0/personaltemplatemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personaltemplatemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PersonalTemplateManager_t {
    QByteArrayData data[10];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PersonalTemplateManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PersonalTemplateManager_t qt_meta_stringdata_PersonalTemplateManager = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 26),
QT_MOC_LITERAL(2, 51, 0),
QT_MOC_LITERAL(3, 52, 18),
QT_MOC_LITERAL(4, 71, 20),
QT_MOC_LITERAL(5, 92, 12),
QT_MOC_LITERAL(6, 105, 11),
QT_MOC_LITERAL(7, 117, 12),
QT_MOC_LITERAL(8, 130, 12),
QT_MOC_LITERAL(9, 143, 10)
    },
    "PersonalTemplateManager\0"
    "friendEntryChangedTemplate\0\0"
    "AbstractListEntry*\0onCreateTemplateView\0"
    "FriendEntry*\0addTemplate\0editTemplate\0"
    "checkElement\0personName\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonalTemplateManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a,

 // methods: name, argc, parameters, tag, flags
       6,    2,   45,    2, 0x02,
       7,    3,   50,    2, 0x02,
       8,    1,   57,    2, 0x02,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00095001,

       0        // eod
};

void PersonalTemplateManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonalTemplateManager *_t = static_cast<PersonalTemplateManager *>(_o);
        switch (_id) {
        case 0: _t->friendEntryChangedTemplate((*reinterpret_cast< AbstractListEntry*(*)>(_a[1]))); break;
        case 1: _t->onCreateTemplateView((*reinterpret_cast< FriendEntry*(*)>(_a[1]))); break;
        case 2: _t->addTemplate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->editTemplate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->checkElement((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PersonalTemplateManager::*_t)(AbstractListEntry * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PersonalTemplateManager::friendEntryChangedTemplate)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PersonalTemplateManager::staticMetaObject = {
    { &TemplateManager::staticMetaObject, qt_meta_stringdata_PersonalTemplateManager.data,
      qt_meta_data_PersonalTemplateManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *PersonalTemplateManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonalTemplateManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PersonalTemplateManager.stringdata))
        return static_cast<void*>(const_cast< PersonalTemplateManager*>(this));
    return TemplateManager::qt_metacast(_clname);
}

int PersonalTemplateManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TemplateManager::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getPersonName(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
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
void PersonalTemplateManager::friendEntryChangedTemplate(AbstractListEntry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
