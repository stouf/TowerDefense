#ifndef GUEPE_H
#define GUEPE_H

#include <vector>

#include "Enum.h"
#include "Position.h"
#include "Ennemi.h"
#include "Projectile.h"

namespace TOWERDEFENSE
{

    class Guepe : public Ennemi
    {
    private:
        // Attributs
        std::vector<QImage> image;
        int indiceImage;

    public:
        // Constructeur
        Guepe(Position position, float taille);
        Guepe(Position position, float taille, float vitaliteBase, float vitalite, float resistance, float vitesse, int timerMalusVitesse);

        // Methodes
        /**
          * Appelée lorsque la vitalité de l'ennemi vaut 0.
          * Crédite le joueur de la taille de l'ennemi.
          * Cause des dégats de 5 * taille² aux voisins.
          */
        void mort();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };

}

#endif // GUEPE_H
