/****************************************************************************
** Meta object code from reading C++ file 'mapframe.h'
**
** Created: Wed Apr 29 21:22:28 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qsimplespatial/mapframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MapFrame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      41,   35,    9,    9, 0x05,
      63,   35,    9,    9, 0x05,
      86,   35,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MapFrame[] = {
    "MapFrame\0\0painter\0paint(QPainter&)\0"
    "event\0clicked(QMouseEvent*)\0"
    "released(QMouseEvent*)\0moved(QMouseEvent*)\0"
    "updateMap()\0"
};

void MapFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapFrame *_t = static_cast<MapFrame *>(_o);
        switch (_id) {
        case 0: _t->paint((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 1: _t->clicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->released((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->moved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->updateMap(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MapFrame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MapFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapFrame,
      qt_meta_data_MapFrame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MapFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MapFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MapFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapFrame))
        return static_cast<void*>(const_cast< MapFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MapFrame::paint(QPainter & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapFrame::clicked(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MapFrame::released(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MapFrame::moved(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
