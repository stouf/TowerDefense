#ifndef PROJECTILEFACTORY_H
#define PROJECTILEFACTORY_H

#include <vector>
#include <string>

#include "Projectile.h"
#include "Position.h"
#include "JoueurSingleton.h"


namespace TOWERDEFENSE
{
    class Projectile;
    class ProjectileFactory
    {

    public:
        /**
          * Constructeur de la factory.
          */
        ProjectileFactory();

        /**
          * Méthode s'occupant des taches de création d'un nouveau projectile.
          * \return Pointeur sur le projectile créé
          */
        static Projectile* getProjectile(TypeProjectile typeProjectile, float frappe, float portee, int vitesse, TypeDeplacement typeCible, Position depart, Position courante, Position cible);

        /**
          * Méthode s'occupant des taches de destruction d'un projectile.
          * \param Pointeur sur le projectile à détruire.
          */
        static void eraseProjectile(Projectile* projectile);

    };
}


#endif // PROJECTILEFACTORY_H
