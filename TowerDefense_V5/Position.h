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
          * Construction d'une position ayant pour coordonn�es X et Y.
          */
        Position(float X=0, float Y=0);

        // Methodes
        /**
          * \return Abscisse r�elle de la position (en unit� case).
          */
        float getX();

        /**
          * \return Ordonn�e r�elle de la position (en unit� case).
          */
        float getY();

        /**
          * \return Abscisse dans le rep�re du jeu de la position (en pixels).
          */
        float getXAffi();

        /**
          * \return Ordonn�e dans le rep�re du jeu de la position (en pixels).
          */
        float getYAffi();

        /**
          * Calcul de la norme euclidienne entre la position courante et les coordonn�es X et Y fournies.
          * \param X2 et Y2 : Point par rapport auquel calculer la distance.
          * \return Norme entre le point (X,Y) et le point (X2, Y2).
          */
        float calculDistance(float X2, float Y2);

        /**
          * Calcul de la norme euclidienne entre la position courante et la position fournie.
          * \param Position par rapport � laquelle calculer la distance.
          * \return Norme entre le point P et le point pass� en param�tre.
          */
        float calculDistance(Position P);

        /**
          * Calcul de l'angle entre la position courante et la position fournie.
          * \param Position par rapport � laquelle calculer l'angle.
          * \return Angle entre le point P et le point pass� en param�tre.
          */
        float calculAngle(Position P);

        /**
          * Calcul de l'angle entre la position courante et les coordonn�es X et Y fournies.
          * \param X2 et Y2 : Point par rapport auquel calculer l'angle.
          * \return Angle entre le point (X,Y) et le point (X2, Y2).
          */
        float calculAngle(float X2, float Y2);

        /**
          * Calcul et modification de la nouvelle position, apr�s un d�placement de la distance fournie, suivant l'angle d�sir�.
          * \param Angle du d�placement.
          * \param Distance de d�placement.
          */
        void deplacer(float angle, float distance);

        void Afficher(std::ostream& f) const;
    };

    std::ostream& operator<<(std::ostream&, const Position&);
}

#include "my_q_graphics_scene.h"


#endif // POSITION_H
