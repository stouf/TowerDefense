#include "Defenseurs/PaintBall.h"

namespace TOWERDEFENSE
{

    PaintBall::PaintBall(Position newPosition):Attaquant(TOUS, PROJ_PAINTBALL, newPosition, 1, 30, 0)
    {

    }

    int PaintBall::coutAchat(int level)
    {
        return PaintBall::getCoutAchat(level);
    }

    int PaintBall::getCoutAchat(int level)
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
            return 0;
            break;
        }
    }

    bool PaintBall::peutAmeliorer() const
    {
        int nextLevel = niveau + 1;
        if(niveau < 3 && getCoutAchat(nextLevel) < JoueurSingleton::getCredit())
            return true;
        return false;
    }

    float PaintBall::getPortee()
    {
        return 4.0 + niveau / 2.0;
    }

    float PaintBall::getCadence()
    {
        return 2.0;
    }

    float PaintBall::getPuissanceBase() const
    {
        return 4.0 * niveau * sqrt(niveau);
    }

    QString PaintBall::getTypeDefenseur()
    {
        return "Paint-Ball";
    }

    void PaintBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        float taille = 0.2 * niveau + 0.3;

        painter->setBrush(Qt::green);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::yellow);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

}
