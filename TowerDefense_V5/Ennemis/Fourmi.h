#ifndef FOURMI_H
#define FOURMI_H

#include "Enum.h"
#include "Position.h"
#include "Ennemi.h"
#include "Projectile.h"

namespace TOWERDEFENSE
{

    class Fourmi : public Ennemi
    {
    private:
        // Attributs
        int timerBonusVitesseCoup;
        std::vector<QImage> image;
        int indiceImage;

    public:
        // Constructeur
        Fourmi(Position position, float taille);
        Fourmi(Position position, float taille, float vitaliteBase, float vitalite, float resistance, float vitesse, int timerMalusVitesse, int timerBonusVitesseCoup);

        // Methodes
        /**
          * Effectue les op�rations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les d�gats via la m�thode recevoirDegats()
          * - Suivant les projectiles, effectue diff�rentes op�rations (ralentissement si bille de Paint-Ball, d�gats aux voisins si boule de p�tanque).
          * Lorsque la fourmi est touch�e, sa vitesse augmente durant 5 secondes.
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        void recevoirProjectile(Projectile* projectile);
        float getVitesse() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };

}

#endif // FOURMI_H
