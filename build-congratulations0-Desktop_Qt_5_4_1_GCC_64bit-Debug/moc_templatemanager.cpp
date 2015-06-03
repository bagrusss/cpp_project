/****************************************************************************
** Meta object code from reading C++ file 'templatemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../congratulations0/templatemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'templatemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TemplateManager_t {
    QByteArrayData data[10];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TemplateManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TemplateManager_t qt_meta_stringdata_TemplateManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TemplateManager"
QT_MOC_LITERAL(1, 16, 14), // "deleteTemplate"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "index"
QT_MOC_LITERAL(4, 38, 22), // "templateListHasChanged"
QT_MOC_LITERAL(5, 61, 15), // "onDeleteElement"
QT_MOC_LITERAL(6, 77, 17), // "onGetTemplateById"
QT_MOC_LITERAL(7, 95, 24), // "onTemplateListHasChanged"
QT_MOC_LITERAL(8, 120, 11), // "addTemplate"
QT_MOC_LITERAL(9, 132, 12) // "editTemplate"

    },
    "TemplateManager\0deleteTemplate\0\0index\0"
    "templateListHasChanged\0onDeleteElement\0"
    "onGetTemplateById\0onTemplateListHasChanged\0"
    "addTemplate\0editTemplate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TemplateManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   53,    2, 0x0a /* Public */,
       6,    1,   56,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    2,   60,    2, 0x02 /* Public */,
       9,    3,   65,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::QString, QMetaType::Int,    3,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,

       0        // eod
};

void TemplateManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TemplateManager *_t = static_cast<TemplateManager *>(_o);
        switch (_id) {
        case 0: _t->deleteTemplate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->templateListHasChanged(); break;
        case 2: _t->onDeleteElement((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { QString _r = _t->onGetTemplateById((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: _t->onTemplateListHasChanged(); break;
        case 5: _t->addTemplate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->editTemplate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TemplateManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TemplateManager::deleteTemplate)) {
                *result = 0;
            }
        }
        {
            typedef void (TemplateManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TemplateManager::templateListHasChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TemplateManager::staticMetaObject = {
    { &Manager::staticMetaObject, qt_meta_stringdata_TemplateManager.data,
      qt_meta_data_TemplateManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TemplateManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemplateManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TemplateManager.stringdata))
        return static_cast<void*>(const_cast< TemplateManager*>(this));
    return Manager::qt_metacast(_clname);
}

int TemplateManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Manager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TemplateManager::deleteTemplate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TemplateManager::templateListHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
