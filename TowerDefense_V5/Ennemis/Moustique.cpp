#include "Ennemis/Moustique.h"

namespace TOWERDEFENSE
{
    Moustique::Moustique(Position pos, float tai):Ennemi(pos, VOLANT, tai, (tai * tai), (6 * tai * tai), (6 * tai * tai), (2 + taille / 2), 0),timerChangTypeDep(7 * FREQ_RAF)
    {
        image.push_back(QImage(QString(":/images/moustiquevolant1.png")));
        image.push_back(QImage(QString(":/images/moustiquevolant2.png")));
        indiceImage = 0;

    }

    Moustique::Moustique(Position pos, float tai, float vitaBase, float vita, float res, float vite, int timMalusVitesse, int timChangTypeDep):Ennemi(pos, VOLANT, tai, vitaBase, vita, res, vite, timMalusVitesse),timerChangTypeDep(timChangTypeDep)
    {
        image.push_back(QImage(QString(":/images/moustiquevolant1.png")));
        image.push_back(QImage(QString(":/images/moustiquevolant2.png")));
        indiceImage = 0;

    }

    float Moustique::getResistance() const
    {
        switch(getTypeDeplacement())
        {
        case RAMPANT:
            return 15 * taille;
            break;
        case VOLANT:
        default:
            return taille * taille;
            break;
        }
    }

    float Moustique::getVitesse() const
    {
        switch(getTypeDeplacement())
        {
        case RAMPANT:
            return 1 + taille / 2;
            break;
        case VOLANT:
        default:
            return 2 + taille / 2;
            break;
        }
    }

    void Moustique::recevoirProjectile(Projectile* proj)
    {
        Ennemi::recevoirProjectile(proj);

        if(getTypeDeplacement() == VOLANT)
        {
            changerTypeDeplacement();
        }
    }

    void Moustique::changerTypeDeplacement()
    {
        switch(typeDeplacement)
        {
        case RAMPANT:
            timerChangTypeDep = 7 * FREQ_RAF;
            typeDeplacement = VOLANT;
            return;
            break;
        case VOLANT:
        default:
            timerChangTypeDep = 3 * FREQ_RAF;
            typeDeplacement = RAMPANT;
            return;
            break;

        }
    }

    void Moustique::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rect(-MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille);
        painter->drawImage(rect, image[indiceImage/5]);
        indiceImage = (indiceImage + 1) % (image.size() * 5);
    }

    void Moustique::advance(int phase)
    {
        Ennemi::advance(phase);

        if(!phase)
            return;

        timerChangTypeDep--;

        if(timerChangTypeDep <= 0)
            changerTypeDeplacement();

    }

}


