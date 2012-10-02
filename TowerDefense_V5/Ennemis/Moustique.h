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
          * La r�sistance �volue avec le mode de d�placement du moustique.
          * \return R�sistance de l'ennemi
          */
        float getResistance() const;

        /**
          * La vitesse �volue avec le mode de d�placement du moustique.
          * \return Vitesse de l'ennemi
          */
        float getVitesse() const;

        /**
          * Effectue les op�rations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les d�gats via la m�thode recevoirDegats()
          * - Suivant les projectiles, effectue diff�rentes op�rations (ralentissement si bille de Paint-Ball, d�gats aux voisins si boule de p�tanque).
          * Lorsque le moustique est touch�, il se d�place en rampant pendant 3 secondes
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        void recevoirProjectile(Projectile* projectile);

        /**
          * Permet de passer de la phase volant � la phase rampant, et vice-versa
          */
        void changerTypeDeplacement();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void advance(int phase);
    };

}

#endif // MOUSTIQUE_H
