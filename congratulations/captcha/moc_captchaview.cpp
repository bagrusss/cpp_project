/****************************************************************************
** Meta object code from reading C++ file 'captchaview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../congratulations_captcha/captchaview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'captchaview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CaptchaView_t {
    QByteArrayData data[9];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CaptchaView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CaptchaView_t qt_meta_stringdata_CaptchaView = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 6),
QT_MOC_LITERAL(4, 32, 12),
QT_MOC_LITERAL(5, 45, 5),
QT_MOC_LITERAL(6, 51, 15),
QT_MOC_LITERAL(7, 67, 13),
QT_MOC_LITERAL(8, 81, 12)
    },
    "CaptchaView\0writeResult\0\0result\0"
    "imageChanged\0image\0exitApplication\0"
    "onWriteResult\0captchaImage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptchaView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       4,    1,   37,    2, 0x05,
       6,    0,   40,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       1,

       0        // eod
};

void CaptchaView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CaptchaView *_t = static_cast<CaptchaView *>(_o);
        switch (_id) {
        case 0: _t->writeResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->imageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->exitApplication(); break;
        case 3: _t->onWriteResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CaptchaView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaptchaView::writeResult)) {
                *result = 0;
            }
        }
        {
            typedef void (CaptchaView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaptchaView::imageChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CaptchaView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CaptchaView::exitApplication)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CaptchaView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CaptchaView.data,
      qt_meta_data_CaptchaView,  qt_static_metacall, 0, 0}
};


const QMetaObject *CaptchaView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptchaView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CaptchaView.stringdata))
        return static_cast<void*>(const_cast< CaptchaView*>(this));
    return QObject::qt_metacast(_clname);
}

int CaptchaView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QString*>(_v) = getCaptchaImage(); break;
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
void CaptchaView::writeResult(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CaptchaView::imageChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CaptchaView::exitApplication()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
