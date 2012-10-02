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
          * M�thode s'occupant des taches de cr�ation d'un nouveau projectile.
          * \return Pointeur sur le projectile cr��
          */
        static Projectile* getProjectile(TypeProjectile typeProjectile, float frappe, float portee, int vitesse, TypeDeplacement typeCible, Position depart, Position courante, Position cible);

        /**
          * M�thode s'occupant des taches de destruction d'un projectile.
          * \param Pointeur sur le projectile � d�truire.
          */
        static void eraseProjectile(Projectile* projectile);

    };
}


#endif // PROJECTILEFACTORY_H
