#include "Ennemis/Guepe.h"

namespace TOWERDEFENSE
{
    Guepe::Guepe(Position pos, float tai):Ennemi(pos, VOLANT, tai, (4 * tai * tai), (7 * tai * tai), (7 * tai * tai), 3, 0)
    {
        image.push_back(QImage(QString(":/images/guepe1.png")));
        image.push_back(QImage(QString(":/images/guepe2.png")));
        indiceImage = 0;

    }

    Guepe::Guepe(Position pos, float tai, float vitaBase, float vita, float res, float vite, int timMalusVitesse): Ennemi(pos, VOLANT, tai, vitaBase, vita, res, vite, timMalusVitesse)
    {
        image.push_back(QImage(QString(":/images/guepe1.png")));
        image.push_back(QImage(QString(":/images/guepe2.png")));
        indiceImage = 0;

    }

    void Guepe::mort()
    {
        std::cout << "Entree dans Guepe::mort()\n";
        std::vector<Ennemi*> liste;
        float degats = taille * taille * 5;
        // On inflige des degats aux voisins
        liste = EnnemiFactory::getListeEnnemisPortee(position, 1.5, RAMPANT);

        for(unsigned int i(0);i<liste.size();++i) // On parcourt le tableau.
        {
            liste[i]->recevoirDegats(degats);
            std::cout << "Degats a mon voisin ! " << std::endl;
        }

        Ennemi::mort();
    }


    void Guepe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rect(-MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille);
        painter->drawImage(rect, image[indiceImage/5]);
        indiceImage = (indiceImage + 1) % (image.size() * 5);
    }

}


