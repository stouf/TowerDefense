#ifndef CAFARD_H
#define CAFARD_H

#include "Enum.h"
#include "Position.h"
#include "Ennemi.h"
#include "Projectile.h"

namespace TOWERDEFENSE
{

    class Cafard : public Ennemi
    {
    private:
        // Attributs
        std::vector<QImage> image;
        int indiceImage;

    public:
        // Constructeur
        Cafard(Position position, float taille);
        Cafard(Position position, float taille, float vitaliteBase, float vitalite, float resistance, float vitesse, int timerMalusVitesse);

        // Methodes
        /**
          * Appel�e lorsque la vitalit� de l'ennemi vaut 0.
          * Cr�dite le joueur de la taille de l'ennemi.
          * Si le cafard mort a une taille sup�rieur ou �gale � 2, cr�ation de 2 cafards de taille = taille - 1
          */
        void mort();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };

}


#endif // CAFARD_H
