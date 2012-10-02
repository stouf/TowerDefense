#include "Defenseurs/PistoletEau.h"

namespace TOWERDEFENSE
{

    PistoletEau::PistoletEau(Position newPosition):Attaquant(TOUS, PROJ_PISTOLET_EAU, newPosition, 1, 40, 0)
    {

    }

    int PistoletEau::coutAchat(int level)
    {
        return PistoletEau::getCoutAchat(level);
    }

    int PistoletEau::getCoutAchat(int level)
    {
        switch(level)
        {
        case 1:
            return 8;
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

    bool PistoletEau::peutAmeliorer() const
    {
        int nextLevel = niveau + 1;
        if(niveau < 3 && getCoutAchat(nextLevel) < JoueurSingleton::getCredit())
            return true;
        return false;
    }

    float PistoletEau::getPortee()
    {
        return 2.0 + niveau / 2.0;
    }

    float PistoletEau::getCadence()
    {
        return 4.0 - niveau / 2.0;
    }

    float PistoletEau::getPuissanceBase() const
    {
        return 5.0 * niveau * sqrt(niveau);
    }

    QString PistoletEau::getTypeDefenseur()
    {
        return "Pistolet a Eau";
    }

    void PistoletEau::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        float taille = 0.2 * niveau + 0.3;

        painter->setBrush(Qt::blue);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::yellow);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

}
