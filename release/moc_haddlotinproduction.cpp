/****************************************************************************
** Meta object code from reading C++ file 'haddlotinproduction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../haddlotinproduction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'haddlotinproduction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HAddLotInProduction_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HAddLotInProduction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HAddLotInProduction_t qt_meta_stringdata_HAddLotInProduction = {
    {
QT_MOC_LITERAL(0, 0, 19), // "HAddLotInProduction"
QT_MOC_LITERAL(1, 20, 8), // "lastLots"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "addLot"
QT_MOC_LITERAL(4, 37, 18), // "on_pdClose_clicked"
QT_MOC_LITERAL(5, 56, 16), // "on_pbAdd_clicked"
QT_MOC_LITERAL(6, 73, 27), // "on_lvLastLots_doubleClicked"
QT_MOC_LITERAL(7, 101, 5), // "index"
QT_MOC_LITERAL(8, 107, 21) // "on_lvLastLots_clicked"

    },
    "HAddLotInProduction\0lastLots\0\0addLot\0"
    "on_pdClose_clicked\0on_pbAdd_clicked\0"
    "on_lvLastLots_doubleClicked\0index\0"
    "on_lvLastLots_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HAddLotInProduction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void HAddLotInProduction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HAddLotInProduction *_t = static_cast<HAddLotInProduction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lastLots(); break;
        case 1: _t->addLot(); break;
        case 2: _t->on_pdClose_clicked(); break;
        case 3: _t->on_pbAdd_clicked(); break;
        case 4: _t->on_lvLastLots_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_lvLastLots_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject HAddLotInProduction::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HAddLotInProduction.data,
      qt_meta_data_HAddLotInProduction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HAddLotInProduction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HAddLotInProduction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HAddLotInProduction.stringdata0))
        return static_cast<void*>(const_cast< HAddLotInProduction*>(this));
    return QWidget::qt_metacast(_clname);
}

int HAddLotInProduction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
