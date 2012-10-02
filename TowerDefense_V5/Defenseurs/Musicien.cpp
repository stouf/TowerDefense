#include "Defenseurs/Musicien.h"

namespace TOWERDEFENSE
{

    Musicien::Musicien(Position newPosition):Defenseur(newPosition, 1)
    {

    }

    int Musicien::coutAchat(int level)
    {
        return Musicien::getCoutAchat(level);
    }

    int Musicien::getCoutAchat(int level)
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

    bool Musicien::peutAmeliorer() const
    {
        int nextLevel = niveau + 1;
        if(niveau < 3 && getCoutAchat(nextLevel) < JoueurSingleton::getCredit())
            return true;
        return false;
    }

    float Musicien::getPortee()
    {
        return 1.5;
    }

    float Musicien::getBonus()
    {
        return 0.2 * niveau;
    }

    QString Musicien::getTypeDefenseur()
    {
        return "Musicien";
    }

    void Musicien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        float taille = 0.2 * niveau + 0.3;

        painter->setBrush(Qt::red);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::yellow);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

    void Musicien::advance(int phase)
    {
        if(!phase)
            return;


        setRotation(this->rotation() + qrand() % 10 - qrand() % 10);
        //std::cout << "Defenseur " << position << " n'a pas de cible...\n";


    }

}
