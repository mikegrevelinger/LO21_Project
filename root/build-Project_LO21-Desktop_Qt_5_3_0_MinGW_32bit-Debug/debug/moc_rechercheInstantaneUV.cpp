/****************************************************************************
** Meta object code from reading C++ file 'rechercheInstantaneUV.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/rechercheInstantaneUV.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rechercheInstantaneUV.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rechercheInstantaneUV_t {
    QByteArrayData data[8];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rechercheInstantaneUV_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rechercheInstantaneUV_t qt_meta_stringdata_rechercheInstantaneUV = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 16),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 1),
QT_MOC_LITERAL(4, 42, 12),
QT_MOC_LITERAL(5, 55, 4),
QT_MOC_LITERAL(6, 60, 4),
QT_MOC_LITERAL(7, 65, 21)
    },
    "rechercheInstantaneUV\0slotRechercherUV\0"
    "\0p\0cellSelected\0nRow\0nCol\0"
    "ouvrirDialogAjouterUV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rechercheInstantaneUV[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    2,   32,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,

       0        // eod
};

void rechercheInstantaneUV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rechercheInstantaneUV *_t = static_cast<rechercheInstantaneUV *>(_o);
        switch (_id) {
        case 0: _t->slotRechercherUV((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cellSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ouvrirDialogAjouterUV(); break;
        default: ;
        }
    }
}

const QMetaObject rechercheInstantaneUV::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rechercheInstantaneUV.data,
      qt_meta_data_rechercheInstantaneUV,  qt_static_metacall, 0, 0}
};


const QMetaObject *rechercheInstantaneUV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rechercheInstantaneUV::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rechercheInstantaneUV.stringdata))
        return static_cast<void*>(const_cast< rechercheInstantaneUV*>(this));
    return QWidget::qt_metacast(_clname);
}

int rechercheInstantaneUV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
