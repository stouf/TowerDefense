#include "Defenseurs/LancePierre.h"

namespace TOWERDEFENSE
{

    LancePierres::LancePierres(Position newPosition):Attaquant(VOLANT, PROJ_LANCE_PIERRE, newPosition, 1, 25, 0)
    {

    }

    int LancePierres::coutAchat(int level)
    {
        return LancePierres::getCoutAchat(level);
    }

    int LancePierres::getCoutAchat(int level)
    {
        switch(level)
        {
        case 1:
            return 12;
            break;
        case 2:
            return 25;
            break;
        case 3:
            return 60;
            break;
        default:
            return 999;
            break;
        }
    }

    bool LancePierres::peutAmeliorer() const
    {
        int nextLevel = niveau + 1;
        if(niveau < 3 && getCoutAchat(nextLevel) < JoueurSingleton::getCredit())
            return true;
        return false;
    }

    float LancePierres::getPortee()
    {
        return 3.0 + niveau / 2.0;
    }

    float LancePierres::getCadence()
    {
        return 1.0;
    }

    float LancePierres::getPuissanceBase() const
    {
        return 10.0 * niveau * sqrt(niveau);
    }


    QString LancePierres::getTypeDefenseur()
    {
        return "Lance-Pierres";
    }

    void LancePierres::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        float taille = 0.2 * niveau + 0.3;

        painter->setBrush(Qt::yellow);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::black);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

}
