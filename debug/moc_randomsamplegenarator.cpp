/****************************************************************************
** Meta object code from reading C++ file 'randomsamplegenarator.h'
**
** Created: Sat May 9 21:40:12 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../randomsamplegenarator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randomsamplegenarator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RandomSampleGenarator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      58,   53,   22,   22, 0x08,
     102,   22,   22,   22, 0x08,
     131,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RandomSampleGenarator[] = {
    "RandomSampleGenarator\0\0"
    "on_pushButtonNewVar_clicked()\0arg1\0"
    "on_comboBoxDistributions_activated(QString)\0"
    "on_pushButtonApply_clicked()\0"
    "on_pushButtonCancel_clicked()\0"
};

void RandomSampleGenarator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RandomSampleGenarator *_t = static_cast<RandomSampleGenarator *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonNewVar_clicked(); break;
        case 1: _t->on_comboBoxDistributions_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonApply_clicked(); break;
        case 3: _t->on_pushButtonCancel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RandomSampleGenarator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RandomSampleGenarator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RandomSampleGenarator,
      qt_meta_data_RandomSampleGenarator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RandomSampleGenarator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RandomSampleGenarator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RandomSampleGenarator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RandomSampleGenarator))
        return static_cast<void*>(const_cast< RandomSampleGenarator*>(this));
    return QDialog::qt_metacast(_clname);
}

int RandomSampleGenarator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
