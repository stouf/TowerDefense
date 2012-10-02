#ifndef POSITION_H
#define POSITION_H

#define PI 3.14159265



#include <string>
#include <iostream>
#include <math.h>

namespace TOWERDEFENSE
{

    /**
      \class Position sur la carte
    **/

    class Position
    {
    private:
        // Attributs
        float X;
        float Y;

    public:
        // Constructeurs
        /**
          * Construction d'une position ayant pour coordonnées X et Y.
          */
        Position(float X=0, float Y=0);

        // Methodes
        /**
          * \return Abscisse réelle de la position (en unité case).
          */
        float getX();

        /**
          * \return Ordonnée réelle de la position (en unité case).
          */
        float getY();

        /**
          * \return Abscisse dans le repère du jeu de la position (en pixels).
          */
        float getXAffi();

        /**
          * \return Ordonnée dans le repère du jeu de la position (en pixels).
          */
        float getYAffi();

        /**
          * Calcul de la norme euclidienne entre la position courante et les coordonnées X et Y fournies.
          * \param X2 et Y2 : Point par rapport auquel calculer la distance.
          * \return Norme entre le point (X,Y) et le point (X2, Y2).
          */
        float calculDistance(float X2, float Y2);

        /**
          * Calcul de la norme euclidienne entre la position courante et la position fournie.
          * \param Position par rapport à laquelle calculer la distance.
          * \return Norme entre le point P et le point passé en paramètre.
          */
        float calculDistance(Position P);

        /**
          * Calcul de l'angle entre la position courante et la position fournie.
          * \param Position par rapport à laquelle calculer l'angle.
          * \return Angle entre le point P et le point passé en paramètre.
          */
        float calculAngle(Position P);

        /**
          * Calcul de l'angle entre la position courante et les coordonnées X et Y fournies.
          * \param X2 et Y2 : Point par rapport auquel calculer l'angle.
          * \return Angle entre le point (X,Y) et le point (X2, Y2).
          */
        float calculAngle(float X2, float Y2);

        /**
          * Calcul et modification de la nouvelle position, après un déplacement de la distance fournie, suivant l'angle désiré.
          * \param Angle du déplacement.
          * \param Distance de déplacement.
          */
        void deplacer(float angle, float distance);

        void Afficher(std::ostream& f) const;
    };

    std::ostream& operator<<(std::ostream&, const Position&);
}

#include "my_q_graphics_scene.h"


#endif // POSITION_H
