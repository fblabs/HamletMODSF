/****************************************************************************
** Meta object code from reading C++ file 'hnewproduct.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hnewproduct.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hnewproduct.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HNewProduct_t {
    QByteArrayData data[7];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HNewProduct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HNewProduct_t qt_meta_stringdata_HNewProduct = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HNewProduct"
QT_MOC_LITERAL(1, 12, 4), // "done"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 42, 13), // "addNewProduct"
QT_MOC_LITERAL(5, 56, 17), // "on_pbSave_clicked"
QT_MOC_LITERAL(6, 74, 19) // "on_pbCancel_clicked"

    },
    "HNewProduct\0done\0\0on_pushButton_2_clicked\0"
    "addNewProduct\0on_pbSave_clicked\0"
    "on_pbCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HNewProduct[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HNewProduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HNewProduct *_t = static_cast<HNewProduct *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->addNewProduct(); break;
        case 3: _t->on_pbSave_clicked(); break;
        case 4: _t->on_pbCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HNewProduct::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HNewProduct::done)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HNewProduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HNewProduct.data,
      qt_meta_data_HNewProduct,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HNewProduct::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HNewProduct::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HNewProduct.stringdata0))
        return static_cast<void*>(const_cast< HNewProduct*>(this));
    return QWidget::qt_metacast(_clname);
}

int HNewProduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void HNewProduct::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
