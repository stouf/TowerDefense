#include "ProjectileFactory.h"

namespace TOWERDEFENSE
{

    ProjectileFactory::ProjectileFactory()
    {
    }

    Projectile* ProjectileFactory::getProjectile(TypeProjectile typeProjectile, float frappe, float portee, int vitesse, TypeDeplacement typeCible, Position depart, Position courante, Position cible)
    {
        Projectile* tmp = new Projectile(typeProjectile, frappe, portee, vitesse, typeCible, depart, courante, cible);
        JoueurSingleton::projectileCree(tmp);

        return tmp;
    }

    void ProjectileFactory::eraseProjectile(Projectile* projectile)
    {
        JoueurSingleton::projectileErase(projectile);
    }

}


