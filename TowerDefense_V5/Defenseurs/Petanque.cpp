#include "Defenseurs/Petanque.h"

namespace TOWERDEFENSE
{

    Petanque::Petanque(Position newPosition):Attaquant(RAMPANT, PROJ_PETANQUE, newPosition, 1, 20, 0)
    {

    }

    int Petanque::coutAchat(int level)
    {
        return Petanque::getCoutAchat(level);
    }

    int Petanque::getCoutAchat(int level)
    {
        switch(level)
        {
        case 1:
            return 15;
            break;
        case 2:
            return 40;
            break;
        case 3:
            return 80;
            break;
        default:
            return 999;
            break;
        }
    }

    bool Petanque::peutAmeliorer() const
    {
        int nextLevel = niveau + 1;
        if(niveau < 3 && getCoutAchat(nextLevel) < JoueurSingleton::getCredit())
            return true;
        return false;
    }

    float Petanque::getPortee()
    {
        return 3.0 + niveau;
    }

    float Petanque::getCadence()
    {
        return 0.5;
    }

    float Petanque::getPuissanceBase() const
    {
        return 15.0 * niveau * sqrt(niveau);
    }

    QString Petanque::getTypeDefenseur()
    {
        return "Petanque";
    }

    void Petanque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {

        float taille = 0.2 * niveau + 0.3;

        painter->setBrush(Qt::gray);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::yellow);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

}
