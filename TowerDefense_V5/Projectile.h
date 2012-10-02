#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include <iostream>
#include <vector>

#include <QGraphicsItem>

#include "Enum.h"
#include "Projectile.h"
#include "Position.h"

namespace TOWERDEFENSE
{

    class Projectile : public QGraphicsItem
    {

    private:
        // Attributs
        TypeProjectile typeProjectile;		///< Type de projectile
        float puissance; 		///< Puissance du projectile
        int vitesse;                    ///< Vitesse de déplacement du projectile, en nombre de cases par secondes
        float portee;                   ///< Portée du projectile, en nombre de case
        Position depart;                ///< Position à laquelle était le défenseur lorsque le projectile a été tiré
        Position courante;              ///< Position courante du projectile
        Position cible;                 ///< Position visée par le projectile
        TypeDeplacement typeEnnemi;     ///< Type de cible pouvant être atteint par le projectile

    public:
        // Constructeur
        Projectile(TypeProjectile typeProjectile, float frappe, float portee, int vitesseProjectile, TypeDeplacement typeCible, Position depart, Position courante, Position cible);

        // Methodes
        /**
          * \return Puissance du projectile.
          */
        float getPuissance();

        /**
          * \return Vitesse de déplacement du projectile.
          */
        int getVitesse();

        /**
          * \return Type de projectile
          */
        TypeProjectile getTypeProjectile();

        virtual QRectF boundingRect() const;
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual void advance(int phase);

    };

}

#endif // PROJECTILE_H
