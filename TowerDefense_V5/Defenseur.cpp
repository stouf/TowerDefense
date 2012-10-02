#include "Defenseur.h"

namespace TOWERDEFENSE
{
    Defenseur::Defenseur(Position n_position, int n_niveau):
            position(n_position), niveau(n_niveau)
    {
        setX(n_position.getXAffi());
        setY(n_position.getYAffi());
        setData(0, "DEFENSE");
    }

    void Defenseur::ameliorer()
    {
        if(peutAmeliorer())
        {
            JoueurSingleton::setCredit(JoueurSingleton::getCredit() - coutAchat(niveau + 1));
            niveau++;
        }

    }

	
    float Attaquant::getPuissance() const
    {
        return getPuissanceBase() * ( 1 + getBonusFrappe());
    }


    float Attaquant::getBonusFrappe() const
    {
        float bonus = 0;
        std::vector<Musicien*> listeMusiciens = DefenseurFactory::getListeMusiciens(getPosition());
        for(unsigned int i = 0; i < listeMusiciens.size(); i++)
        {
            bonus += listeMusiciens[i]->getBonus();
        }

        return bonus;
    }


    Position Defenseur::getPosition() const
    {
        return position;
    }
    float Defenseur::getNiveau() const
    {
        return niveau;
    }

    TypeDeplacement Attaquant::getTypeCibles()
    {
        return typeCible;
    }

    QRectF Defenseur::boundingRect() const
    {
        QRectF rect = QRect(-MyQGraphicsScene::getHauteurUnite() / 2, -MyQGraphicsScene::getHauteurUnite() / 2, MyQGraphicsScene::getHauteurUnite(), MyQGraphicsScene::getHauteurUnite());
        return rect;
    }

    void Defenseur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        float taille = 0.3 * niveau + 0.1;
        painter->setBrush(Qt::blue);
        painter->drawEllipse(-MyQGraphicsScene::getHauteurUnite() * taille / 2, - MyQGraphicsScene::getHauteurUnite() * taille / 2, MyQGraphicsScene::getHauteurUnite() * taille, MyQGraphicsScene::getHauteurUnite() * taille);

        painter->setBrush(Qt::yellow);
        painter->drawLine(0, -MyQGraphicsScene::getHauteurUnite() * taille / 2, 0, 0);

    }

    Attaquant::Attaquant(TypeDeplacement n_typeCible, TypeProjectile n_typeProjectile, Position n_position, int n_niveau, int n_vitesseProjectile, int n_timerProchaineFrappe):Defenseur(n_position, n_niveau), typeCible(n_typeCible), typeProjectile(n_typeProjectile), vitesseProjectile(n_vitesseProjectile), timerProchaineFrappe(n_timerProchaineFrappe)
    {

    }

    void Attaquant::advance(int phase)
    {
        if(!phase)
            return;

        Ennemi* cible = EnnemiFactory::getCible(position, getPortee(), typeCible);
        if(cible != 0)
        {
            if(timerProchaineFrappe == 0)
            {

                ProjectileFactory::getProjectile(typeProjectile, getPuissance(), getPortee(), vitesseProjectile, typeCible, position, position, cible->getPosition());

                timerProchaineFrappe = FREQ_RAF / getCadence();
            }
            setRotation(cible->getPosition().calculAngle(getPosition()) * 57.3 + 270);
        }
        else
        {
            setRotation(this->rotation() + qrand() % 10 - qrand() % 10);
        }

        if(timerProchaineFrappe > 0)
            timerProchaineFrappe--;

    }

    float DefenseurFactory::nombreDefenseurs = 0;
    std::vector<Defenseur*> DefenseurFactory::listeDefenseurs;

    DefenseurFactory::DefenseurFactory()
    {
    }

    bool DefenseurFactory::peutAcheter(TypeDefenseur typeDefenseur, int level)
    {
        switch (typeDefenseur) {
        case PISTOLET_EAU:
            return PistoletEau::getCoutAchat(level) <= JoueurSingleton::getCredit();
            break;
        case LANCE_PIERRE:
            return LancePierres::getCoutAchat(level) <= JoueurSingleton::getCredit();
            break;
        case PAINTBALL:
            return PaintBall::getCoutAchat(level) <= JoueurSingleton::getCredit();
            break;
        case PETANQUE:
            return Petanque::getCoutAchat(level) <= JoueurSingleton::getCredit();
            break;
        case MUSICIEN:
            return Musicien::getCoutAchat(level) <= JoueurSingleton::getCredit();
            break;
          default:
            //throw std::runtime_error("Unknown enemy.");
            return 0;
            break;
        }
        return false;
    }

    void DefenseurFactory::updateDefenseur(Defenseur* defenseur)
    {
        if(defenseur->peutAmeliorer())
        {
            defenseur->ameliorer();
        }
    }

    Defenseur* DefenseurFactory::getDefenseur(TypeDefenseur typeDefenseur, Position position)
    {
        Defenseur* tmp = 0;
        int cout = 0; // Cout en credits, et non std::cout !!! :p

        switch (typeDefenseur) {
          case PISTOLET_EAU:
            cout = PistoletEau::getCoutAchat(1);
            if(JoueurSingleton::getCredit() >= cout)
            {
                tmp = new PistoletEau(position);
            }
            else
            {
                return 0;
            }
            break;
          case LANCE_PIERRE:
            cout = LancePierres::getCoutAchat(1);
            if(JoueurSingleton::getCredit() >= cout)
            {
                tmp = new LancePierres(position);
            }
            else
            {
                return 0;
            }
            break;
        case PAINTBALL:
            cout = PaintBall::getCoutAchat(1);
            if(JoueurSingleton::getCredit() >= cout)
            {
                tmp = new PaintBall(position);

            }
            else
            {
                return 0;
            }
            break;
        case PETANQUE:
            cout = Petanque::getCoutAchat(1);
            if(JoueurSingleton::getCredit() >= cout)
            {
                tmp = new Petanque(position);
            }
            else
            {
                return 0;
            }
            break;
        case MUSICIEN:
            cout = Musicien::getCoutAchat(1);
            if(JoueurSingleton::getCredit() >= cout)
            {
                tmp = new Musicien(position);
            }
            else
            {
                return 0;
            }
            break;
          default:
            return 0;
            break;
        }

        JoueurSingleton::setCredit(JoueurSingleton::getCredit() - cout);
        JoueurSingleton::defenseurCree(tmp);

        nombreDefenseurs++;
        listeDefenseurs.push_back(tmp);

        return tmp;
    }

    void DefenseurFactory::eraseDefenseur(Defenseur* ptdefenseur)
    {
        for(unsigned int i(0);i<listeDefenseurs.size();++i) // On parcourt le tableau.
        {
            if(listeDefenseurs[i] == ptdefenseur)
            {
                JoueurSingleton::setCredit(JoueurSingleton::getCredit() + ptdefenseur->coutAchat(ptdefenseur->getNiveau()) / 2);
                JoueurSingleton::defenseurErase(ptdefenseur);
                listeDefenseurs.erase(listeDefenseurs.begin() + i);
                delete ptdefenseur;
                return;
            }
        }
    }

    int DefenseurFactory::getNombreDefenseurs() const
    {
        return nombreDefenseurs;
    }

    std::vector<Defenseur*> DefenseurFactory::getListeDefenseurs()
    {
        return listeDefenseurs;
    }

    std::vector<Musicien*> DefenseurFactory::getListeMusiciens(Position position)
    {


        std::vector<Musicien*> liste;


        for(unsigned int i(0);i<listeDefenseurs.size();++i) // On parcourt le tableau.
        {
            Musicien* musicien = dynamic_cast<Musicien*>(listeDefenseurs[i]);
            if(musicien)
            {
                Position positionMusicien = musicien->getPosition();   // Et on affiche chacun des ennemis;

                if(positionMusicien.calculDistance(position) <= 1.5)
                {
                    liste.push_back(musicien);
                }
            }
        }

        return liste;
    }

}
