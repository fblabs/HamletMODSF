/****************************************************************************
** Meta object code from reading C++ file 'hmodifylot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hmodifylot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hmodifylot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HModifyLot_t {
    QByteArrayData data[10];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HModifyLot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HModifyLot_t qt_meta_stringdata_HModifyLot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HModifyLot"
QT_MOC_LITERAL(1, 11, 10), // "updatedLot"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "updateLot"
QT_MOC_LITERAL(4, 33, 17), // "on_cbScad_toggled"
QT_MOC_LITERAL(5, 51, 7), // "checked"
QT_MOC_LITERAL(6, 59, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 81, 25), // "on_pbComposizione_clicked"
QT_MOC_LITERAL(8, 107, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(9, 126, 26) // "on_pbLotOperations_clicked"

    },
    "HModifyLot\0updatedLot\0\0updateLot\0"
    "on_cbScad_toggled\0checked\0"
    "on_pushButton_clicked\0on_pbComposizione_clicked\0"
    "on_pbClose_clicked\0on_pbLotOperations_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HModifyLot[] = {

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
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HModifyLot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HModifyLot *_t = static_cast<HModifyLot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatedLot(); break;
        case 1: _t->updateLot(); break;
        case 2: _t->on_cbScad_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pbComposizione_clicked(); break;
        case 5: _t->on_pbClose_clicked(); break;
        case 6: _t->on_pbLotOperations_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HModifyLot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HModifyLot::updatedLot)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HModifyLot::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HModifyLot.data,
      qt_meta_data_HModifyLot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HModifyLot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HModifyLot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HModifyLot.stringdata0))
        return static_cast<void*>(const_cast< HModifyLot*>(this));
    return QWidget::qt_metacast(_clname);
}

int HModifyLot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HModifyLot::updatedLot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
