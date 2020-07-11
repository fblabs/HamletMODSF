/****************************************************************************
** Meta object code from reading C++ file 'hpackview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hpackview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hpackview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HPackView_t {
    QByteArrayData data[14];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HPackView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HPackView_t qt_meta_stringdata_HPackView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HPackView"
QT_MOC_LITERAL(1, 10, 9), // "setFilter"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 20), // "on_deDal_dateChanged"
QT_MOC_LITERAL(4, 42, 4), // "date"
QT_MOC_LITERAL(5, 47, 19), // "on_deAl_dateChanged"
QT_MOC_LITERAL(6, 67, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(7, 86, 14), // "modifySelected"
QT_MOC_LITERAL(8, 101, 8), // "pidlotto"
QT_MOC_LITERAL(9, 110, 16), // "on_pbMod_clicked"
QT_MOC_LITERAL(10, 127, 24), // "on_tvPacks_doubleClicked"
QT_MOC_LITERAL(11, 152, 5), // "index"
QT_MOC_LITERAL(12, 158, 17), // "on_pbInfo_clicked"
QT_MOC_LITERAL(13, 176, 12) // "refreshModel"

    },
    "HPackView\0setFilter\0\0on_deDal_dateChanged\0"
    "date\0on_deAl_dateChanged\0on_pbClose_clicked\0"
    "modifySelected\0pidlotto\0on_pbMod_clicked\0"
    "on_tvPacks_doubleClicked\0index\0"
    "on_pbInfo_clicked\0refreshModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HPackView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x28 /* Private | MethodCloned */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    4,
    QMetaType::Void, QMetaType::QDate,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HPackView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HPackView *_t = static_cast<HPackView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFilter(); break;
        case 1: _t->on_deDal_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->on_deAl_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 3: _t->on_pbClose_clicked(); break;
        case 4: _t->modifySelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->modifySelected(); break;
        case 6: _t->on_pbMod_clicked(); break;
        case 7: _t->on_tvPacks_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_pbInfo_clicked(); break;
        case 9: _t->refreshModel(); break;
        default: ;
        }
    }
}

const QMetaObject HPackView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HPackView.data,
      qt_meta_data_HPackView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HPackView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HPackView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HPackView.stringdata0))
        return static_cast<void*>(const_cast< HPackView*>(this));
    return QWidget::qt_metacast(_clname);
}

int HPackView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
