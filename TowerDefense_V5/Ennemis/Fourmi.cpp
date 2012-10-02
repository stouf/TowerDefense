#include "Ennemis/Fourmi.h"

namespace TOWERDEFENSE
{
    Fourmi::Fourmi(Position pos, float tai):Ennemi(pos, RAMPANT, tai, (tai * tai), (5 * tai * tai), (5 * tai * tai), (2 + tai / 2), 0), timerBonusVitesseCoup(0)
    {
        image.push_back(QImage(QString(":/images/fourmi1.png")));
        image.push_back(QImage(QString(":/images/fourmi2.png")));
        image.push_back(QImage(QString(":/images/fourmi3.png")));
        indiceImage = 0;

    }

    Fourmi::Fourmi(Position pos, float tai, float vitaBase, float vita, float res, float vite, int timMalusVitesse, int timBonusVitesseCoup):Ennemi(pos, RAMPANT, tai, vitaBase, vita, res, vite, timMalusVitesse),timerBonusVitesseCoup(timBonusVitesseCoup)
    {
        image.push_back(QImage(QString(":/images/fourmi1.png")));
        image.push_back(QImage(QString(":/images/fourmi2.png")));
        image.push_back(QImage(QString(":/images/fourmi3.png")));
        indiceImage = 0;

    }

    void Fourmi::recevoirProjectile(Projectile* projectile)
    {
        Ennemi::recevoirProjectile(projectile);
        timerBonusVitesseCoup = 5 * FREQ_RAF;
    }

    float Fourmi::getVitesse() const
    {
        if(timerBonusVitesseCoup > 0)
            return Ennemi::getVitesse() * 1.5;

        return Ennemi::getVitesse();
    }

    void Fourmi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rect(-MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille);
        painter->drawImage(rect, image[indiceImage/5]);
        indiceImage = (indiceImage + 1) % (image.size() * 5);
    }

}
