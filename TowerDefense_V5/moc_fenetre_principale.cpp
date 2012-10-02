/****************************************************************************
** Meta object code from reading C++ file 'fenetre_principale.h'
**
** Created: Thu Sep 8 10:01:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fenetre_principale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre_principale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TOWERDEFENSE__FenetrePrincipale[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   32,   32,   32, 0x0a,
      52,   32,   32,   32, 0x0a,
      75,   32,   32,   32, 0x0a,
      91,   32,   32,   32, 0x0a,
     105,   32,   32,   32, 0x0a,
     125,  118,   32,   32, 0x0a,
     148,  118,   32,   32, 0x0a,
     183,  173,   32,   32, 0x0a,
     212,  173,   32,   32, 0x0a,
     254,  243,   32,   32, 0x0a,
     285,  243,   32,   32, 0x0a,
     318,   32,   32,   32, 0x0a,
     332,   32,   32,   32, 0x0a,
     345,   32,   32,   32, 0x0a,
     361,  173,   32,   32, 0x0a,
     396,   32,   32,   32, 0x0a,
     419,   32,   32,   32, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TOWERDEFENSE__FenetrePrincipale[] = {
    "TOWERDEFENSE::FenetrePrincipale\0\0"
    "activerInsertion()\0mauvaisEndroitClique()\0"
    "creditChanged()\0viesChanged()\0"
    "plusDeVies()\0ennemi\0ajouterEnnemi(Ennemi*)\0"
    "supprimerEnnemi(Ennemi*)\0defenseur\0"
    "ajouterDefenseur(Defenseur*)\0"
    "supprimerDefenseur(Defenseur*)\0"
    "projectile\0ajouterProjectile(Projectile*)\0"
    "supprimerProjectile(Projectile*)\0"
    "lancerVague()\0timerVague()\0vagueTerminee()\0"
    "afficherInfosDefenseur(Defenseur*)\0"
    "lancerNouvellePartie()\0slotPause()\0"
};

const QMetaObject TOWERDEFENSE::FenetrePrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TOWERDEFENSE__FenetrePrincipale,
      qt_meta_data_TOWERDEFENSE__FenetrePrincipale, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TOWERDEFENSE::FenetrePrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TOWERDEFENSE::FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TOWERDEFENSE::FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TOWERDEFENSE__FenetrePrincipale))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TOWERDEFENSE::FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activerInsertion(); break;
        case 1: mauvaisEndroitClique(); break;
        case 2: creditChanged(); break;
        case 3: viesChanged(); break;
        case 4: plusDeVies(); break;
        case 5: ajouterEnnemi((*reinterpret_cast< Ennemi*(*)>(_a[1]))); break;
        case 6: supprimerEnnemi((*reinterpret_cast< Ennemi*(*)>(_a[1]))); break;
        case 7: ajouterDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 8: supprimerDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 9: ajouterProjectile((*reinterpret_cast< Projectile*(*)>(_a[1]))); break;
        case 10: supprimerProjectile((*reinterpret_cast< Projectile*(*)>(_a[1]))); break;
        case 11: lancerVague(); break;
        case 12: timerVague(); break;
        case 13: vagueTerminee(); break;
        case 14: afficherInfosDefenseur((*reinterpret_cast< Defenseur*(*)>(_a[1]))); break;
        case 15: lancerNouvellePartie(); break;
        case 16: slotPause(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
