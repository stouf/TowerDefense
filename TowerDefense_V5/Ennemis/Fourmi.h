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
          * Effectue les opérations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les dégats via la méthode recevoirDegats()
          * - Suivant les projectiles, effectue différentes opérations (ralentissement si bille de Paint-Ball, dégats aux voisins si boule de pétanque).
          * Lorsque la fourmi est touchée, sa vitesse augmente durant 5 secondes.
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        void recevoirProjectile(Projectile* projectile);
        float getVitesse() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };

}

#endif // FOURMI_H
