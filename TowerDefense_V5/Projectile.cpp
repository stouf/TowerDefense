#include "Projectile.h"

namespace TOWERDEFENSE
{

    Projectile::Projectile(TypeProjectile newTypeProjectile, float puis, float port, int vit, TypeDeplacement typCib, Position dep, Position cou, Position cib)
        :typeProjectile(newTypeProjectile), puissance(puis), vitesse(vit), portee(port), depart(dep), courante(cou), cible(cib), typeEnnemi(typCib)

    {
        setX(cou.getXAffi());
        setY(cou.getYAffi());
        setData(0, "PROJECTILE");

    }

    // Methodes
    float Projectile::getPuissance()
    {
        return puissance;
    }

    int Projectile::getVitesse()
    {
        return vitesse;
    }

    TypeProjectile Projectile::getTypeProjectile()
    {
        return typeProjectile;
    }


    QRectF Projectile::boundingRect() const
    {
        QRectF rect = QRectF(-MyQGraphicsScene::getHauteurUnite() * 0.1, -MyQGraphicsScene::getHauteurUnite() * 0.1, MyQGraphicsScene::getHauteurUnite() * 0.2, MyQGraphicsScene::getHauteurUnite() * 0.2);
        return rect;
    }

    void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rect = QRectF(-MyQGraphicsScene::getHauteurUnite() * 0.1, -MyQGraphicsScene::getHauteurUnite() * 0.1, MyQGraphicsScene::getHauteurUnite() * 0.2, MyQGraphicsScene::getHauteurUnite() * 0.2);
        painter->setBrush(Qt::red);
        painter->drawEllipse(rect);
    }

    void Projectile::advance(int phase)
    {
        if(!phase)
            return;

        if(depart.calculDistance(courante) > portee)
        {
            return ProjectileFactory::eraseProjectile(this);
        }

        courante.deplacer(cible.calculAngle(depart) * 57.3 + 180, getVitesse() * 1.0 / FREQ_RAF );

        setX(courante.getXAffi());
        setY(courante.getYAffi());

        std::vector<Ennemi*> listeEnnemis = EnnemiFactory::getListeEnnemis();
        for(unsigned int i(0);i<listeEnnemis.size();++i) // On parcourt le tableau.
        {
            if(typeEnnemi == TOUS || listeEnnemis[i]->getTypeDeplacement() == typeEnnemi)
            {
                Ennemi* ennemi = listeEnnemis[i];

                if(this->collidesWithItem(ennemi))
                {
                    ennemi->recevoirProjectile(this);
                    return;
                }

            }
        }
    }


}
