#include "Ennemis/Cafard.h"

namespace TOWERDEFENSE
{
    Cafard::Cafard(Position pos, float tai):Ennemi(pos, RAMPANT, tai, (5 * tai * tai), (10 * tai * tai), (10 * tai * tai), 2, 0)
    {
        image.push_back(QImage(QString(":/images/cafard1.png")));
        image.push_back(QImage(QString(":/images/cafard2.png")));
        image.push_back(QImage(QString(":/images/cafard3.png")));
        indiceImage = 0;

    }

    Cafard::Cafard(Position pos, float tai, float vitaBase, float vita, float res, float vite, int timMalusVitesse): Ennemi(pos, RAMPANT, tai, vitaBase, vita, res, vite, timMalusVitesse)
    {
        image.push_back(QImage(QString(":/images/cafard1.png")));
        image.push_back(QImage(QString(":/images/cafard2.png")));
        image.push_back(QImage(QString(":/images/cafard3.png")));
        indiceImage = 0;

    }

    void Cafard::mort()
    {
        if(taille >= 2)
        {
            EnnemiFactory::getEnnemi(CAFARD, position, taille-1);
            EnnemiFactory::getEnnemi(CAFARD, position, taille-1);
        }

        Ennemi::mort();
    }

    void Cafard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rect(-MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille);
        painter->drawImage(rect, image[indiceImage/5]);
        indiceImage = (indiceImage + 1) % (image.size() * 5);
    }

}

