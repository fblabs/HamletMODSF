/****************************************************************************
** Meta object code from reading C++ file 'hcomposizionelotto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hcomposizionelotto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hcomposizionelotto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HComposizioneLotto_t {
    QByteArrayData data[19];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HComposizioneLotto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HComposizioneLotto_t qt_meta_stringdata_HComposizioneLotto = {
    {
QT_MOC_LITERAL(0, 0, 18), // "HComposizioneLotto"
QT_MOC_LITERAL(1, 19, 6), // "wclose"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "getLotComposition"
QT_MOC_LITERAL(4, 45, 9), // "getLotUse"
QT_MOC_LITERAL(5, 55, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(6, 82, 5), // "index"
QT_MOC_LITERAL(7, 88, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(8, 112, 5), // "print"
QT_MOC_LITERAL(9, 118, 8), // "printUse"
QT_MOC_LITERAL(10, 127, 16), // "printComposition"
QT_MOC_LITERAL(11, 144, 7), // "getTipo"
QT_MOC_LITERAL(12, 152, 3), // "idl"
QT_MOC_LITERAL(13, 156, 10), // "getDetails"
QT_MOC_LITERAL(14, 167, 15), // "removeComponent"
QT_MOC_LITERAL(15, 183, 19), // "on_pbRemove_clicked"
QT_MOC_LITERAL(16, 203, 16), // "on_pbAdd_clicked"
QT_MOC_LITERAL(17, 220, 7), // "refresh"
QT_MOC_LITERAL(18, 228, 18) // "on_pbPrint_clicked"

    },
    "HComposizioneLotto\0wclose\0\0getLotComposition\0"
    "getLotUse\0on_tableView_doubleClicked\0"
    "index\0on_pushButton_3_clicked\0print\0"
    "printUse\0printComposition\0getTipo\0idl\0"
    "getDetails\0removeComponent\0"
    "on_pbRemove_clicked\0on_pbAdd_clicked\0"
    "refresh\0on_pbPrint_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HComposizioneLotto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HComposizioneLotto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HComposizioneLotto *_t = static_cast<HComposizioneLotto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->wclose();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->getLotComposition(); break;
        case 2: _t->getLotUse(); break;
        case 3: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->print(); break;
        case 6: _t->printUse(); break;
        case 7: _t->printComposition(); break;
        case 8: { int _r = _t->getTipo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->getDetails(); break;
        case 10: _t->removeComponent(); break;
        case 11: _t->on_pbRemove_clicked(); break;
        case 12: _t->on_pbAdd_clicked(); break;
        case 13: _t->refresh(); break;
        case 14: _t->on_pbPrint_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (HComposizioneLotto::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HComposizioneLotto::wclose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HComposizioneLotto::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HComposizioneLotto.data,
      qt_meta_data_HComposizioneLotto,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HComposizioneLotto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HComposizioneLotto::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HComposizioneLotto.stringdata0))
        return static_cast<void*>(const_cast< HComposizioneLotto*>(this));
    return QWidget::qt_metacast(_clname);
}

int HComposizioneLotto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
int HComposizioneLotto::wclose()
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
