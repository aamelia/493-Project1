/****************************************************************************
** Meta object code from reading C++ file 'imagecollector.h'
**
** Created: Fri Mar 1 19:15:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Project1/imagecollector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagecollector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageCollector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   41,   15,   15, 0x0a,
      70,   64,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ImageCollector[] = {
    "ImageCollector\0\0pixmapAvailable(QPixmap)\0"
    "url\0loadImage(QString)\0reply\0"
    "imageFinishedLoading(QNetworkReply*)\0"
};

void ImageCollector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageCollector *_t = static_cast<ImageCollector *>(_o);
        switch (_id) {
        case 0: _t->pixmapAvailable((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->loadImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->imageFinishedLoading((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageCollector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageCollector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageCollector,
      qt_meta_data_ImageCollector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageCollector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageCollector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageCollector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageCollector))
        return static_cast<void*>(const_cast< ImageCollector*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageCollector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ImageCollector::pixmapAvailable(QPixmap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
