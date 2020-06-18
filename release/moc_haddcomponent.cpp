/****************************************************************************
** Meta object code from reading C++ file 'haddcomponent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../haddcomponent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'haddcomponent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HAddComponent_t {
    QByteArrayData data[19];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HAddComponent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HAddComponent_t qt_meta_stringdata_HAddComponent = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HAddComponent"
QT_MOC_LITERAL(1, 14, 4), // "done"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 18), // "on_rbTutti_toggled"
QT_MOC_LITERAL(4, 39, 7), // "checked"
QT_MOC_LITERAL(5, 47, 22), // "on_rbMateriali_toggled"
QT_MOC_LITERAL(6, 70, 21), // "on_rbProdotti_toggled"
QT_MOC_LITERAL(7, 92, 20), // "on_rbRipieni_toggled"
QT_MOC_LITERAL(8, 113, 23), // "on_rbConfezioni_toggled"
QT_MOC_LITERAL(9, 137, 20), // "on_rbImpasti_toggled"
QT_MOC_LITERAL(10, 158, 33), // "on_cbProdotto_currentIndexCha..."
QT_MOC_LITERAL(11, 192, 5), // "index"
QT_MOC_LITERAL(12, 198, 21), // "addComponentOperation"
QT_MOC_LITERAL(13, 220, 21), // "updateComposizioneLot"
QT_MOC_LITERAL(14, 242, 12), // "idoperazione"
QT_MOC_LITERAL(15, 255, 12), // "refreshModel"
QT_MOC_LITERAL(16, 268, 20), // "on_pbConfirm_clicked"
QT_MOC_LITERAL(17, 289, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(18, 308, 23) // "on_leCode_returnPressed"

    },
    "HAddComponent\0done\0\0on_rbTutti_toggled\0"
    "checked\0on_rbMateriali_toggled\0"
    "on_rbProdotti_toggled\0on_rbRipieni_toggled\0"
    "on_rbConfezioni_toggled\0on_rbImpasti_toggled\0"
    "on_cbProdotto_currentIndexChanged\0"
    "index\0addComponentOperation\0"
    "updateComposizioneLot\0idoperazione\0"
    "refreshModel\0on_pbConfirm_clicked\0"
    "on_pbClose_clicked\0on_leCode_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HAddComponent[] = {

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
       3,    1,   90,    2, 0x08 /* Private */,
       5,    1,   93,    2, 0x08 /* Private */,
       6,    1,   96,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       8,    1,  102,    2, 0x08 /* Private */,
       9,    1,  105,    2, 0x08 /* Private */,
      10,    1,  108,    2, 0x08 /* Private */,
      12,    0,  111,    2, 0x08 /* Private */,
      13,    1,  112,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x28 /* Private | MethodCloned */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HAddComponent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HAddComponent *_t = static_cast<HAddComponent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->on_rbTutti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_rbMateriali_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_rbProdotti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_rbRipieni_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_rbConfezioni_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_rbImpasti_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_cbProdotto_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->addComponentOperation(); break;
        case 9: _t->updateComposizioneLot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateComposizioneLot(); break;
        case 11: _t->refreshModel(); break;
        case 12: _t->on_pbConfirm_clicked(); break;
        case 13: _t->on_pbClose_clicked(); break;
        case 14: _t->on_leCode_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HAddComponent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HAddComponent::done)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HAddComponent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HAddComponent.data,
      qt_meta_data_HAddComponent,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HAddComponent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HAddComponent::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HAddComponent.stringdata0))
        return static_cast<void*>(const_cast< HAddComponent*>(this));
    return QWidget::qt_metacast(_clname);
}

int HAddComponent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HAddComponent::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
