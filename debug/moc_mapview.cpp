/****************************************************************************
** Meta object code from reading C++ file 'mapview.h'
**
** Created: Wed May 6 22:25:51 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mapview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mapview[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,    9,    8,    8, 0x09,
      40,   34,    8,    8, 0x09,
      65,   34,    8,    8, 0x09,
      91,    8,    8,    8, 0x09,
     114,    8,    8,    8, 0x08,
     135,  129,    8,    8, 0x08,
     157,  129,    8,    8, 0x08,
     182,  129,    8,    8, 0x08,
     214,  206,    8,    8, 0x08,
     238,    8,    8,    8, 0x08,
     250,    8,    8,    8, 0x08,
     257,    8,    8,    8, 0x08,
     266,    8,    8,    8, 0x08,
     281,  276,    8,    8, 0x08,
     316,    8,    8,    8, 0x08,
     336,    8,    8,    8, 0x08,
     348,  276,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mapview[] = {
    "mapview\0\0painter\0paint(QPainter&)\0"
    "event\0mapClicked(QMouseEvent*)\0"
    "mapReleased(QMouseEvent*)\0"
    "mapMoved(QMouseEvent*)\0addShapeFile()\0"
    "layer\0addPointLayer(Layer*)\0"
    "addPolylineLayer(Layer*)\0"
    "addPolygonLayer(Layer*)\0checked\0"
    "addPointTriggered(bool)\0saveLayer()\0"
    "zoom()\0zoomIn()\0zoomOut()\0item\0"
    "layerListChanged(QListWidgetItem*)\0"
    "layerListSelected()\0shapeInfo()\0"
    "layerPropertiesChanged(QListWidgetItem*)\0"
};

void mapview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mapview *_t = static_cast<mapview *>(_o);
        switch (_id) {
        case 0: _t->paint((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 1: _t->mapClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mapReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mapMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->addShapeFile(); break;
        case 5: _t->addPointLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 6: _t->addPolylineLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 7: _t->addPolygonLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 8: _t->addPointTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->saveLayer(); break;
        case 10: _t->zoom(); break;
        case 11: _t->zoomIn(); break;
        case 12: _t->zoomOut(); break;
        case 13: _t->layerListChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->layerListSelected(); break;
        case 15: _t->shapeInfo(); break;
        case 16: _t->layerPropertiesChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mapview::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mapview::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mapview,
      qt_meta_data_mapview, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mapview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mapview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mapview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mapview))
        return static_cast<void*>(const_cast< mapview*>(this));
    return QWidget::qt_metacast(_clname);
}

int mapview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
