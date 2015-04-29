/****************************************************************************
** Meta object code from reading C++ file 'computevariable.h'
**
** Created: Wed Apr 29 21:22:21 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../computevariable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'computevariable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComputeVariable[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      47,   16,   16,   16, 0x08,
      72,   16,   16,   16, 0x08,
      99,   16,   16,   16, 0x08,
     126,   16,   16,   16, 0x08,
     153,   16,   16,   16, 0x08,
     180,   16,   16,   16, 0x08,
     207,   16,   16,   16, 0x08,
     234,   16,   16,   16, 0x08,
     261,   16,   16,   16, 0x08,
     288,   16,   16,   16, 0x08,
     315,   16,   16,   16, 0x08,
     344,   16,   16,   16, 0x08,
     374,   16,   16,   16, 0x08,
     402,   16,   16,   16, 0x08,
     434,   16,   16,   16, 0x08,
     466,   16,   16,   16, 0x08,
     501,  496,   16,   16, 0x08,
     560,   16,   16,   16, 0x08,
     589,   16,   16,   16, 0x08,
     619,   16,   16,   16, 0x08,
     648,   16,   16,   16, 0x08,
     683,  677,   16,   16, 0x08,
     732,  677,   16,   16, 0x08,
     775,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ComputeVariable[] = {
    "ComputeVariable\0\0on_pushButtonNewVar_clicked()\0"
    "on_pushButton1_clicked()\0"
    "on_pushButton1_2_clicked()\0"
    "on_pushButton1_3_clicked()\0"
    "on_pushButton1_4_clicked()\0"
    "on_pushButton1_5_clicked()\0"
    "on_pushButton1_6_clicked()\0"
    "on_pushButton1_7_clicked()\0"
    "on_pushButton1_8_clicked()\0"
    "on_pushButton1_9_clicked()\0"
    "on_pushButton1_0_clicked()\0"
    "on_pushButtonPoint_clicked()\0"
    "on_pushButtondelete_clicked()\0"
    "on_pushButtonplus_clicked()\0"
    "on_pushButtonsubtract_clicked()\0"
    "on_pushButtonMultiply_clicked()\0"
    "on_pushButtonDevide_clicked()\0item\0"
    "on_listWidgetVariables_itemDoubleClicked(QListWidgetItem*)\0"
    "on_pushButtonApply_clicked()\0"
    "on_pushButtonCancel_clicked()\0"
    "on_pushButtonlbrac_clicked()\0"
    "on_pushButtonrbrac_clicked()\0index\0"
    "on_listWidgetfunction_doubleClicked(QModelIndex)\0"
    "on_comboBoxFGroup_currentIndexChanged(int)\0"
    "on_pushButtondelete_2_clicked()\0"
};

void ComputeVariable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ComputeVariable *_t = static_cast<ComputeVariable *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonNewVar_clicked(); break;
        case 1: _t->on_pushButton1_clicked(); break;
        case 2: _t->on_pushButton1_2_clicked(); break;
        case 3: _t->on_pushButton1_3_clicked(); break;
        case 4: _t->on_pushButton1_4_clicked(); break;
        case 5: _t->on_pushButton1_5_clicked(); break;
        case 6: _t->on_pushButton1_6_clicked(); break;
        case 7: _t->on_pushButton1_7_clicked(); break;
        case 8: _t->on_pushButton1_8_clicked(); break;
        case 9: _t->on_pushButton1_9_clicked(); break;
        case 10: _t->on_pushButton1_0_clicked(); break;
        case 11: _t->on_pushButtonPoint_clicked(); break;
        case 12: _t->on_pushButtondelete_clicked(); break;
        case 13: _t->on_pushButtonplus_clicked(); break;
        case 14: _t->on_pushButtonsubtract_clicked(); break;
        case 15: _t->on_pushButtonMultiply_clicked(); break;
        case 16: _t->on_pushButtonDevide_clicked(); break;
        case 17: _t->on_listWidgetVariables_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonApply_clicked(); break;
        case 19: _t->on_pushButtonCancel_clicked(); break;
        case 20: _t->on_pushButtonlbrac_clicked(); break;
        case 21: _t->on_pushButtonrbrac_clicked(); break;
        case 22: _t->on_listWidgetfunction_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 23: _t->on_comboBoxFGroup_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_pushButtondelete_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ComputeVariable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComputeVariable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ComputeVariable,
      qt_meta_data_ComputeVariable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComputeVariable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComputeVariable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComputeVariable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComputeVariable))
        return static_cast<void*>(const_cast< ComputeVariable*>(this));
    return QDialog::qt_metacast(_clname);
}

int ComputeVariable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
