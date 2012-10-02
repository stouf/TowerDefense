#ifndef MUSICIEN_H
#define MUSICIEN_H

#include <string>
#include <iostream>
#include <vector>

#include "Defenseur.h"
#include "Position.h"

namespace TOWERDEFENSE
{
    class Musicien : public Defenseur
    {

    private:
        // Attributs


    public:
        // Constructeur
        Musicien(Position position);

        // Methodes
        int coutAchat(int level = 1);
        static int getCoutAchat(int level = 1);
        bool peutAmeliorer() const;
        QString getTypeDefenseur();
        float getBonus();
        float getPortee();


        void afficher(std::ostream& f=std::cout) const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void advance(int phase = 0);

    };

}

#endif // MUSICIEN_H
