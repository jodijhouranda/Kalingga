/****************************************************************************
** Meta object code from reading C++ file 'histogramconfig.h'
**
** Created: Sun May 10 21:09:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../histogramconfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'histogramconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HistogramConfig[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,
      65,   60,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HistogramConfig[] = {
    "HistogramConfig\0\0index\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "arg1\0on_spinBoxBinwidth_valueChanged(QString)\0"
};

void HistogramConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HistogramConfig *_t = static_cast<HistogramConfig *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_spinBoxBinwidth_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HistogramConfig::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HistogramConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HistogramConfig,
      qt_meta_data_HistogramConfig, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HistogramConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HistogramConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HistogramConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HistogramConfig))
        return static_cast<void*>(const_cast< HistogramConfig*>(this));
    if (!strcmp(_clname, "ChartConfig"))
        return static_cast< ChartConfig*>(const_cast< HistogramConfig*>(this));
    return QWidget::qt_metacast(_clname);
}

int HistogramConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
