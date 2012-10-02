/****************************************************************************
** Meta object code from reading C++ file 'my_q_graphics_scene.h'
**
** Created: Thu Sep 8 10:01:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "my_q_graphics_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_q_graphics_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TOWERDEFENSE__MyQGraphicsScene[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x05,
      65,   55,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   31,   31,   31, 0x0a,
     127,   31,   31,   31, 0x0a,
     148,   31,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TOWERDEFENSE__MyQGraphicsScene[] = {
    "TOWERDEFENSE::MyQGraphicsScene\0\0"
    "mauvaisEndroitClique()\0defenseur\0"
    "signalAfficherInfosDefenseur(Defenseur*)\0"
    "ameliorerDefenseur()\0supprimerDefenseur()\0"
    "creditChanged()\0"
};

const QMetaObject TOWERDEFENSE::MyQGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_TOWERDEFENSE__MyQGraphicsScene,
      qt_meta_data_TOWERDEFENSE__MyQGraphicsScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TOWERDEFENSE::MyQGraphicsScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TOWERDEFENSE::MyQGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TOWERDEFENSE::MyQGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TOWERDEFENSE__MyQGraphicsScene))
        return static_cast<void*>(const_cast< MyQGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int TOWERDEFENSE::MyQGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mauvaisEndroitClique(); break;
        case 1: signalAfficherInfosDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 2: ameliorerDefenseur(); break;
        case 3: supprimerDefenseur(); break;
        case 4: creditChanged(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TOWERDEFENSE::MyQGraphicsScene::mauvaisEndroitClique()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TOWERDEFENSE::MyQGraphicsScene::signalAfficherInfosDefenseur(Defenseur * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
