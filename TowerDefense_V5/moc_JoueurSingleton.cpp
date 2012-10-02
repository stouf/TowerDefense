/****************************************************************************
** Meta object code from reading C++ file 'JoueurSingleton.h'
**
** Created: Thu Sep 8 10:01:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "JoueurSingleton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JoueurSingleton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TOWERDEFENSE__JoueurSingleton[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,
      47,   30,   30,   30, 0x05,
      61,   30,   30,   30, 0x05,
      87,   80,   30,   30, 0x05,
     126,  116,   30,   30, 0x05,
     172,  161,   30,   30, 0x05,
     209,   80,   30,   30, 0x05,
     235,   80,   30,   30, 0x05,
     260,  116,   30,   30, 0x05,
     297,  161,   30,   30, 0x05,
     336,   30,   30,   30, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_TOWERDEFENSE__JoueurSingleton[] = {
    "TOWERDEFENSE::JoueurSingleton\0\0"
    "creditChanged()\0viesChanged()\0"
    "signalPlusDeVies()\0ennemi\0"
    "signalAjouterEnnemi(Ennemi*)\0defenseur\0"
    "signalAjouterDefenseur(Defenseur*)\0"
    "projectile\0signalAjouterProjectile(Projectile*)\0"
    "signalEnnemiMort(Ennemi*)\0"
    "signalEnnemiBut(Ennemi*)\0"
    "signalSupprimerDefenseur(Defenseur*)\0"
    "signalSupprimerProjectile(Projectile*)\0"
    "signalVagueTerminee()\0"
};

const QMetaObject TOWERDEFENSE::JoueurSingleton::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TOWERDEFENSE__JoueurSingleton,
      qt_meta_data_TOWERDEFENSE__JoueurSingleton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TOWERDEFENSE::JoueurSingleton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TOWERDEFENSE::JoueurSingleton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TOWERDEFENSE::JoueurSingleton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TOWERDEFENSE__JoueurSingleton))
        return static_cast<void*>(const_cast< JoueurSingleton*>(this));
    return QObject::qt_metacast(_clname);
}

int TOWERDEFENSE::JoueurSingleton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: creditChanged(); break;
        case 1: viesChanged(); break;
        case 2: signalPlusDeVies(); break;
        case 3: signalAjouterEnnemi((*reinterpret_cast< Ennemi*(*)>(_a[1]))); break;
        case 4: signalAjouterDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 5: signalAjouterProjectile((*reinterpret_cast< Projectile*(*)>(_a[1]))); break;
        case 6: signalEnnemiMort((*reinterpret_cast< Ennemi*(*)>(_a[1]))); break;
        case 7: signalEnnemiBut((*reinterpret_cast< Ennemi*(*)>(_a[1]))); break;
        case 8: signalSupprimerDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 9: signalSupprimerProjectile((*reinterpret_cast< Projectile*(*)>(_a[1]))); break;
        case 10: signalVagueTerminee(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TOWERDEFENSE::JoueurSingleton::creditChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TOWERDEFENSE::JoueurSingleton::viesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TOWERDEFENSE::JoueurSingleton::signalPlusDeVies()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TOWERDEFENSE::JoueurSingleton::signalAjouterEnnemi(Ennemi * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TOWERDEFENSE::JoueurSingleton::signalAjouterDefenseur(Defenseur * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TOWERDEFENSE::JoueurSingleton::signalAjouterProjectile(Projectile * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TOWERDEFENSE::JoueurSingleton::signalEnnemiMort(Ennemi * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TOWERDEFENSE::JoueurSingleton::signalEnnemiBut(Ennemi * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TOWERDEFENSE::JoueurSingleton::signalSupprimerDefenseur(Defenseur * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TOWERDEFENSE::JoueurSingleton::signalSupprimerProjectile(Projectile * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TOWERDEFENSE::JoueurSingleton::signalVagueTerminee()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
