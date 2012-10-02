#ifndef MOUSTIQUE_H
#define MOUSTIQUE_H

#include "Enum.h"
#include "Position.h"
#include "Ennemi.h"
#include "Projectile.h"

namespace TOWERDEFENSE
{

    class Moustique : public Ennemi
    {
    private:
        // Attributs
        int timerChangTypeDep;
        std::vector<QImage> image;
        int indiceImage;

    public:
        // Constructeur
        Moustique(Position position, float taille);
        Moustique(Position position, float taille, float vitaliteBase, float vitalite, float resistance, float vitesse, int timerMalusVitesse, int timerChangTypeDep = 0);

        // Methodes
        /**
          * La résistance évolue avec le mode de déplacement du moustique.
          * \return Résistance de l'ennemi
          */
        float getResistance() const;

        /**
          * La vitesse évolue avec le mode de déplacement du moustique.
          * \return Vitesse de l'ennemi
          */
        float getVitesse() const;

        /**
          * Effectue les opérations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les dégats via la méthode recevoirDegats()
          * - Suivant les projectiles, effectue différentes opérations (ralentissement si bille de Paint-Ball, dégats aux voisins si boule de pétanque).
          * Lorsque le moustique est touché, il se déplace en rampant pendant 3 secondes
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        void recevoirProjectile(Projectile* projectile);

        /**
          * Permet de passer de la phase volant à la phase rampant, et vice-versa
          */
        void changerTypeDeplacement();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void advance(int phase);
    };

}

#endif // MOUSTIQUE_H
