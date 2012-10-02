#include "JoueurSingleton.h"

namespace TOWERDEFENSE
{
    bool JoueurSingleton::instanceFlag = false;
    JoueurSingleton* JoueurSingleton::single = NULL;
    int JoueurSingleton::credit = 200;
    int JoueurSingleton::vies = 10;
    Carte* JoueurSingleton::carte = NULL;

    JoueurSingleton::JoueurSingleton()
    {
    }

    JoueurSingleton::~JoueurSingleton()
    {
        instanceFlag = false;
    }


    JoueurSingleton* JoueurSingleton::getInstance()
    {
        if(! instanceFlag)
        {
            single = new JoueurSingleton();
            instanceFlag = true;
            return single;
        }
        else
        {
            return single;
        }
    }

    int JoueurSingleton::getCredit()
    {
        return credit;
    }

    void JoueurSingleton::setCredit(int newCredit)
    {
        if(newCredit >= 0)
        {
            credit = newCredit;
            emit JoueurSingleton::getInstance()->creditChanged();

        }
        else
        {
        }
    }

    int JoueurSingleton::getVies()
    {
        return vies;
    }

    void JoueurSingleton::setVies(int newVies)
    {
        if(newVies > 0)
        {
            vies = newVies;
            emit JoueurSingleton::getInstance()->viesChanged();
        }
        else
        {
            vies = newVies;
            emit JoueurSingleton::getInstance()->viesChanged();
            emit JoueurSingleton::getInstance()->signalPlusDeVies();
        }
    }

    void JoueurSingleton::defenseurCree(Defenseur* defenseur)
    {
        emit JoueurSingleton::getInstance()->signalAjouterDefenseur(defenseur);
    }

    void JoueurSingleton::defenseurErase(Defenseur* defenseur)
    {
        emit JoueurSingleton::getInstance()->signalSupprimerDefenseur(defenseur);
    }

    void JoueurSingleton::projectileCree(Projectile* projectile)
    {
        emit JoueurSingleton::getInstance()->signalAjouterProjectile(projectile);
    }

    void JoueurSingleton::projectileErase(Projectile* projectile)
    {
        emit JoueurSingleton::getInstance()->signalSupprimerProjectile(projectile);
    }



    void JoueurSingleton::ennemiCree(Ennemi* ennemi)
    {
        emit JoueurSingleton::getInstance()->signalAjouterEnnemi(ennemi);
    }

    void JoueurSingleton::ennemiMort(Ennemi* ennemi)
    {
        emit JoueurSingleton::getInstance()->signalEnnemiMort(ennemi);
    }

    void JoueurSingleton::ennemiBut(Ennemi* ennemi)
    {
        emit JoueurSingleton::getInstance()->signalEnnemiBut(ennemi);
        EnnemiFactory::eraseEnnemi(ennemi);
        JoueurSingleton::setVies(JoueurSingleton::getVies() - 1);
    }

    void JoueurSingleton::vagueTerminee()
    {
        emit JoueurSingleton::getInstance()->signalVagueTerminee();
    }

    Carte* JoueurSingleton::getCarte()
    {
        return carte;
    }

    void JoueurSingleton::setCarte(const std::string& fichier)
    {
        carte = new Carte(fichier);
    }

}
