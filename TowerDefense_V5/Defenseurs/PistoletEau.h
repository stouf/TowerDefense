#ifndef PISTOLETEAU_H
#define PISTOLETEAU_H

#include <string>
#include <iostream>
#include <vector>

#include "Defenseur.h"
#include "Position.h"

namespace TOWERDEFENSE
{

    class PistoletEau : public Attaquant
    {

    private:
        // Attributs

    public:
        // Constructeur
        PistoletEau(Position position);

        // Methodes
        int coutAchat(int level = 1);
        static int getCoutAchat(int level = 1);
        bool peutAmeliorer() const;
        QString getTypeDefenseur();
        float getPortee();
        float getCadence();
        float getPuissanceBase() const;

        void afficher(std::ostream& f=std::cout) const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    };

}

#endif // PISTOLETEAU_H
