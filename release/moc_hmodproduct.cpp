/****************************************************************************
** Meta object code from reading C++ file 'hmodproduct.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hmodproduct.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hmodproduct.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HModProduct_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HModProduct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HModProduct_t qt_meta_stringdata_HModProduct = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HModProduct"
QT_MOC_LITERAL(1, 12, 4), // "done"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "getProductData"
QT_MOC_LITERAL(4, 33, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(5, 52, 17), // "on_pbSave_clicked"
QT_MOC_LITERAL(6, 70, 16), // "setModifyEnabled"
QT_MOC_LITERAL(7, 87, 6), // "enable"
QT_MOC_LITERAL(8, 94, 21) // "on_pushButton_clicked"

    },
    "HModProduct\0done\0\0getProductData\0"
    "on_pbClose_clicked\0on_pbSave_clicked\0"
    "setModifyEnabled\0enable\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HModProduct[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x28 /* Private | MethodCloned */,
       8,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HModProduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HModProduct *_t = static_cast<HModProduct *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done(); break;
        case 1: { bool _r = _t->getProductData();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->on_pbClose_clicked(); break;
        case 3: _t->on_pbSave_clicked(); break;
        case 4: _t->setModifyEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setModifyEnabled(); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HModProduct::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HModProduct::done)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HModProduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HModProduct.data,
      qt_meta_data_HModProduct,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HModProduct::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HModProduct::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HModProduct.stringdata0))
        return static_cast<void*>(const_cast< HModProduct*>(this));
    return QWidget::qt_metacast(_clname);
}

int HModProduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void HModProduct::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
