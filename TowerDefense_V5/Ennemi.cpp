#include "Ennemi.h"


namespace TOWERDEFENSE
{

    Ennemi::Ennemi(Position pos, TypeDeplacement typeDep, float tai, float res, float vitaBase, float vita, float vite, int timMalusVitesse)
        :position(pos),typeDeplacement(typeDep),taille(tai),resistance(res),vitaliteBase(vitaBase),vitalite(vita),vitesse(vite), timerMalusVitesse(timMalusVitesse), angle(0)
    {
        ID = EnnemiFactory::getNombreEnnemis();
        setX(pos.getXAffi());
        setY(pos.getYAffi());
        setData(0, "ENNEMI");
    }

    float Ennemi::getTaille() const
    {
        return taille;
    }

    float Ennemi::getVitaliteBase() const
    {
        return vitaliteBase;
    }

    float Ennemi::getVitalite() const
    {
        return vitalite;
    }

    float Ennemi::getResistance() const
    {
        return resistance;
    }

    float Ennemi::getVitesseBase() const
    {
        return vitesse;
    }

    float Ennemi::getVitesse() const
    {

        if(timerMalusVitesse > 0)
            return vitesse * 0.5;
        else
            return vitesse;
    }

    TypeDeplacement Ennemi::getTypeDeplacement() const
    {
        return typeDeplacement;
    }

    Position Ennemi::getPosition() const
    {
        return position;
    }

    void Ennemi::recevoirProjectile(Projectile* proj)
    {
        Position tmpPos = getPosition();
        recevoirDegats(proj->getPuissance());

        if(proj->getTypeProjectile() == PROJ_PETANQUE)
        {
            float degatsChoc = proj->getPuissance() * 10.0 / 15.0;
            // On inflige des dégats aux voisins
            std::vector<Ennemi*> listeVoisins = EnnemiFactory::getListeEnnemisPortee(tmpPos, 1, RAMPANT);

            for(unsigned int i = 0; i<listeVoisins.size(); i++)
            {
                listeVoisins[i]->recevoirDegats(degatsChoc);
            }
        }
        else if(proj->getTypeProjectile() == PROJ_PAINTBALL)
        {
            timerMalusVitesse = 4 * FREQ_RAF;
        }

        ProjectileFactory::eraseProjectile(proj);
        delete proj;
    }

    void Ennemi::recevoirDegats(float degats)
    {
        if(vitalite <= 0)
            return;         // On ne tue pas les morts !

        degats -= resistance;
        degats = degats > 0 ? degats : 0;

        vitalite = vitalite - degats;

        if(vitalite <= 0)
        {
            vitalite = 0;
            mort();
        }
    }

    void Ennemi::mort()
    {
        JoueurSingleton::setCredit(JoueurSingleton::getCredit() + taille);
        EnnemiFactory::eraseEnnemi(this);
        JoueurSingleton::ennemiMort(this);
    }

    QRectF Ennemi::boundingRect() const
    {
        QRectF rect = QRectF(-MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille, MyQGraphicsScene::getHauteurUnite() * 0.8 * taille);

        return rect;

    }

    void Ennemi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {

        QColor color(((int)getVitalite() * 100) % 256, ((int)getVitalite() * 100) % 256, ((int)getVitalite() * 100) % 256);
        QRectF rect = QRectF(-MyQGraphicsScene::getHauteurUnite() * 0.2 * taille, -MyQGraphicsScene::getHauteurUnite() * 0.2 * taille, MyQGraphicsScene::getHauteurUnite() * 0.4 * taille, MyQGraphicsScene::getHauteurUnite() * 0.4 * taille);
        painter->setBrush(color);
        painter->drawEllipse(rect);
    }

    void Ennemi::advance(int phase)
    {
        if(!phase)
            return;

        if(getVitalite() <= 0)
            return;

        if(timerMalusVitesse > 0)
            timerMalusVitesse--;

        if(JoueurSingleton::getInstance()->getCarte()->getCase(position.getX(), position.getY()) == BUT_ENNEMIS)
        {
            JoueurSingleton::ennemiBut(this);
            return;
        }

        float angleCase = JoueurSingleton::getInstance()->getCarte()->getAngle(position.getX(), position.getY());

        setRotation(angleCase);
        position.deplacer(angleCase, getVitesse() / FREQ_RAF );
        setX(position.getXAffi());
        setY(position.getYAffi());
    }

    int EnnemiFactory::nombreEnnemis = 0;
    std::vector<Ennemi*> EnnemiFactory::listeEnnemis;

    EnnemiFactory::EnnemiFactory()
    {

    }

    Ennemi* EnnemiFactory::getEnnemi(TypeEnnemi typeEnnemi, Position position, float taille)
    {
        Ennemi* tmp = 0;

        switch (typeEnnemi) {
        case MOUSTIQUE:
            tmp = new Moustique(position, taille);
            break;
        case CAFARD:
            tmp = new Cafard(position, taille);
            break;
        case GUEPE:
            tmp = new Guepe(position, taille);
            break;
        case FOURMI:
            tmp = new Fourmi(position, taille);
            break;
        default:
            return 0;
            break;
        }



        nombreEnnemis++;
        listeEnnemis.push_back(tmp);

        JoueurSingleton::ennemiCree(tmp);

        return tmp;
    }

    void EnnemiFactory::eraseEnnemi(Ennemi* ptennemi)
    {
        for(unsigned int i(0);i<listeEnnemis.size();++i) // On parcourt le tableau.
        {
            if(listeEnnemis[i] == ptennemi)
            {
                listeEnnemis.erase(listeEnnemis.begin() + i);
                //delete ptennemi;
                return;
            }
        }
    }

    int EnnemiFactory::getNombreEnnemis()
    {
        return nombreEnnemis;
    }

    int EnnemiFactory::getNombreEnnemisCourant()
    {
        return listeEnnemis.size();
    }

    std::vector<Ennemi*> EnnemiFactory::getListeEnnemis()
    {
        return listeEnnemis;
    }

    std::vector<Ennemi*> EnnemiFactory::getListeEnnemis(TypeDeplacement typeCible)
    {
        std::vector<Ennemi*> liste;

        for(unsigned int i(0);i<listeEnnemis.size();++i) // On parcours le tableau.
        {
            if(typeCible == TOUS || EnnemiFactory::listeEnnemis[i]->getTypeDeplacement() == typeCible)
            {
                liste.push_back(listeEnnemis[i]);
            }
        }

        return liste;
    }

    std::vector<Ennemi*> EnnemiFactory::getListeEnnemisPortee(Position position, float portee, TypeDeplacement typeCible)
    {
        std::vector<Ennemi*> liste;

        for(unsigned int i(0);i<listeEnnemis.size();++i) // On parcourt le tableau.
        {
            if(typeCible == TOUS || EnnemiFactory::listeEnnemis[i]->getTypeDeplacement() == typeCible)
            {
                Position positionEnnemi = EnnemiFactory::listeEnnemis[i]->getPosition();   // Et on affiche chacun des ennemis;

                if(positionEnnemi.calculDistance(position) <= portee)
                {
                    liste.push_back(listeEnnemis[i]);
                }
            }
        }
        return liste;
    }

    Ennemi* EnnemiFactory::getCible(Position position, float portee, TypeDeplacement typeCible)
    {
        for(unsigned int i(0);i<listeEnnemis.size();++i) // On parcourt le tableau.
        {
            if(typeCible == TOUS || EnnemiFactory::listeEnnemis[i]->getTypeDeplacement() == typeCible)
            {
                Position positionEnnemi = EnnemiFactory::listeEnnemis[i]->getPosition();   // Et on affiche chacun des ennemis;

                if(positionEnnemi.calculDistance(position) <= portee && EnnemiFactory::listeEnnemis[i]->getVitalite() > 0)
                {
                    return EnnemiFactory::listeEnnemis[i];
                }
            }
        }

        return 0;
    }

}
