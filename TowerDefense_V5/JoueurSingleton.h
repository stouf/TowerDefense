#ifndef JOUEURSINGLETON_H
#define JOUEURSINGLETON_H

#include <iostream>
#include <string>
#include <vector>

#include "QObject"
#include "Defenseur.h"
#include "Ennemi.h"
#include "carte.h"

namespace TOWERDEFENSE
{
    class Ennemi;
    class Carte;
    class Defenseur;

    /** \class JoueurSingleton
      * Interface entre les mécanismes du jeu et l'interface.\n
      * Centre du mécanisme du jeu (carte, crédits,...).\n
      * Envoi les signaux vers l'interface.
      */
    class JoueurSingleton : public QObject
    {
       Q_OBJECT

    private:
        static bool instanceFlag;
        static JoueurSingleton *single;
        static int credit;
        static int vies;
        static Carte* carte;
        JoueurSingleton();

    public:
        static JoueurSingleton* getInstance();
        ~JoueurSingleton();

        static int getCredit();
        static int getVies();
        static void setCredit(int newCredit);
        static void setVies(int newVies);
        static void ennemiMort(Ennemi* ennemi);
        static void ennemiBut(Ennemi* ennemi);
        static Carte* getCarte();
        static void setCarte(const std::string& fichier);
        static void ennemiCree(Ennemi* ennemi);
        static void defenseurCree(Defenseur* defenseur);
        static void defenseurErase(Defenseur* defenseur);
        static void projectileCree(Projectile* projectile);
        static void projectileErase(Projectile* projectile);
        static void vagueTerminee();

    signals:
        void creditChanged();
        void viesChanged();

        void signalPlusDeVies();

        void signalAjouterEnnemi(Ennemi* ennemi);
        void signalAjouterDefenseur(Defenseur* defenseur);
        void signalAjouterProjectile(Projectile* projectile);

        void signalEnnemiMort(Ennemi* ennemi);
        void signalEnnemiBut(Ennemi* ennemi);
        void signalSupprimerDefenseur(Defenseur* defenseur);
        void signalSupprimerProjectile(Projectile* projectile);

        void signalVagueTerminee();


    };
}

#endif // JOUEURSINGLETON_H
