/****************************************************************************
** Meta object code from reading C++ file 'hnewrecipe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hnewrecipe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hnewrecipe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HNewRecipe_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HNewRecipe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HNewRecipe_t qt_meta_stringdata_HNewRecipe = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HNewRecipe"
QT_MOC_LITERAL(1, 11, 2), // "OK"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 4), // "nome"
QT_MOC_LITERAL(4, 20, 4), // "tipo"
QT_MOC_LITERAL(5, 25, 20), // "on_rbImpasti_toggled"
QT_MOC_LITERAL(6, 46, 7), // "checked"
QT_MOC_LITERAL(7, 54, 20), // "on_rbRipieni_toggled"
QT_MOC_LITERAL(8, 75, 21), // "on_rbProdotti_toggled"
QT_MOC_LITERAL(9, 97, 18), // "on_pbAbort_clicked"
QT_MOC_LITERAL(10, 116, 15), // "on_pbOK_clicked"
QT_MOC_LITERAL(11, 132, 28) // "on_rbConfezionamenti_toggled"

    },
    "HNewRecipe\0OK\0\0nome\0tipo\0on_rbImpasti_toggled\0"
    "checked\0on_rbRipieni_toggled\0"
    "on_rbProdotti_toggled\0on_pbAbort_clicked\0"
    "on_pbOK_clicked\0on_rbConfezionamenti_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HNewRecipe[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void HNewRecipe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HNewRecipe *_t = static_cast<HNewRecipe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OK((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_rbImpasti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_rbRipieni_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_rbProdotti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pbAbort_clicked(); break;
        case 5: _t->on_pbOK_clicked(); break;
        case 6: _t->on_rbConfezionamenti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HNewRecipe::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HNewRecipe::OK)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HNewRecipe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HNewRecipe.data,
      qt_meta_data_HNewRecipe,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HNewRecipe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HNewRecipe::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HNewRecipe.stringdata0))
        return static_cast<void*>(const_cast< HNewRecipe*>(this));
    return QWidget::qt_metacast(_clname);
}

int HNewRecipe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HNewRecipe::OK(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
