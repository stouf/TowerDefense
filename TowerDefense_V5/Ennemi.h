#ifndef ENNEMI_H
#define ENNEMI_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPointF>
#include <QPainter>
#include <QString>

#include <string>
#include <iostream>
#include <vector>

#include "Projectile.h"

#include "Enum.h"
#include "Position.h"

#include "JoueurSingleton.h"

#include "my_q_graphics_scene.h"



const int FREQ_RAF = 50;

namespace TOWERDEFENSE
{
    class Projectile;
    class Ennemi : public QGraphicsItem
    {

    protected:
        // Attributs
        Position position;  ///< Position de l'ennemi.
        TypeDeplacement typeDeplacement;    ///< Type de d�placement courant de l'ennemi.
        float taille;       ///< Taille en unit� de l'ennemi.
        float resistance;   ///< R�sistance de l'ennemi.
        float vitaliteBase; ///< Vitalit� de base de l'ennemi.
        float vitalite;     ///< Vitalit� courante de l'ennemi (vitalit� de base - d�gats re�us).
        float vitesse;      ///< Vitesse de d�placement de base de l'ennemi.
        int timerMalusVitesse;  ///< Nombre de Tick de timer restant avant la fin du malus de vitesse suite � une touche par une bille de Paint-Ball. 0 si pas de malus.
        float angle;        ///< Direction du d�placement


    public:
        int ID;             ///< ID utilis� pour le debug
        // Constructeur
        /**
          * Peut �tre utilis� pour la cr�ation d'un nouvel ennemi, ou pour le chargement d'un ennemi lors d'une sauvegarde de la partie.
          * \param Position : position de l'ennemi.
          * \param TypeDeplacement : type de d�placement de l'ennemi.
          * \param taille : taille de l'ennemi, en unit�s.
          * \param resistance : resistance de l'ennemi.
          * \param vitaliteBase : vitalit� de base de l'ennemi.
          * \param vitalite : vitalit� courante de l'ennemi.
          * \param vitesse : vitesse de base de l'ennemi.
          * \param timerMalusVitesse : nombre de tick de timer restant avant la fin du malus de vitesse suite � une touche par une bille de Paint-Ball. 0 si pas de malus.
          */
        Ennemi(Position position, TypeDeplacement typeDeplacement, float taille, float resistance, float vitaliteBase, float vitalite, float vitesse, int timerMalusVitesse = 0);

        // Methodes

        /**
          * \return Taille de l'ennemi
          */
        virtual float getTaille() const;

        /**
          * \return r�sistance de l'ennemi
          */
        virtual float getResistance() const;

        /**
          * \return vitalit� de base de l'ennemi
          */
        virtual float getVitaliteBase() const;

        /**
          * \return Vitalit� restant � l'ennemi
          */
        virtual float getVitalite() const;

        /**
          * \return Vitesse de base de l'ennemi
          */
        virtual float getVitesseBase() const;

        /**
          * \return Vitesse courante de l'ennemi, apr�s application des bonus et malus de vitesse.
          */
        virtual float getVitesse() const;

        /**
          * \return Type de d�placement courant de l'ennemi
          */
        virtual TypeDeplacement getTypeDeplacement() const;

        /**
          * \return Position courante de l'ennemi
          */
        virtual Position getPosition() const;

        /**
          * Effectue les op�rations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les d�gats via la m�thode recevoirDegats()
          * - Suivant les projectiles, effectue diff�rentes op�rations (ralentissement si bille de Paint-Ball, d�gats aux voisins si boule de p�tanque).
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        virtual void recevoirProjectile(Projectile* projectile);

        /**
          * Calcule les d�gats � infliger en fonction de la puissance de la frappe et met � jour la vitalit�.\n
          * Appelle la m�thode mort() lorsque la vitalit� devient nulle.
          */
        virtual void recevoirDegats(float degats);

        /**
          * Appel�e lorsque la vitalit� de l'ennemi vaut 0.\n
          * Cr�dite le joueur de la taille de l'ennemi.
          */
        virtual void mort();

        // Fonction des QGraphicsItem

        /**
          * Surcharge de la m�thode h�rit�e de QGraphicsItem.\n
          * D�finit la zone de collision de l'ennemi.
          */
        virtual QRectF boundingRect() const;

        /**
          * Surcharge de la m�thode h�rit�e de QGraphicsItem.\n
          * Permet de d�finir la forme affich�e � l'�cran.
          */
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        /**
          * Surcharge de la m�thode h�rit�e de QGraphicsItem.\n
          * Appel�e � chaque Tick du timer.\n
          * Utilis�e pour g�rer les actions effectu�es par les ennemis (suivi du chemin, arriv�e au but).
          */
        virtual void advance(int phase);

    };

    class EnnemiFactory : public QObject
    {
        Q_OBJECT
    private:
        static std::vector<Ennemi*> listeEnnemis;   ///< Liste des ennemis pr�sents dans le jeu. Utilis�e par le m�canisme.
        static int nombreEnnemis;                   ///< Nombre d'ennemis cr��s dans le jeu (depuis le d�but de la partie).

    public:
        /**
          * Constructeur de la factory.
          */
        EnnemiFactory();

        /**
          * M�thode utilis�e pour la cr�ation d'un nouvel ennemi.\n
          * Se charge de toutes les op�rations de base :
          * - Construction
          * - Affichage
          * - Insertion dans les m�canismes
          * \return Pointeur sur l'ennemi cr��.
          */
        static Ennemi* getEnnemi(TypeEnnemi typeEnnemi, Position position, float taille);

        /**
          * M�thode utilis�e pour supprimer un ennemi du jeu :
          * - Suppression des m�canismes
          * - Ajout des cr�dits correspondant � la vente.
          */
        static void eraseEnnemi(Ennemi* ennemi);

        /**
          * \return Nombre d'ennemis cr��s depuis le d�but de la partie
          */
        static int getNombreEnnemis();

        /**
          * \return Nombre d'ennemis actuellement vivant.
          */
        static int getNombreEnnemisCourant();

        /**
          * \return Liste de tous les ennemis actuellement vivant.
          */
        static std::vector<Ennemi*> getListeEnnemis();

        /**
          * \return Liste des ennemis du type sp�cifi� actuellement vivant.
          */
        static std::vector<Ennemi*> getListeEnnemis(TypeDeplacement typeCible);

        /**
          * Effectue une recherche d'ennemis du type sp�cifi�, � une distance portee autour de la position sp�cifi�e.
          * \param Position : position autour de laquelle chercher.
          * \param portee : distance � laquelle limiter la recherche.
          * \param TypeDeplacement : type d'ennemis � chercher
          * \return Liste d'ennemis r�pondant � la recherche.
          */
        static std::vector<Ennemi*> getListeEnnemisPortee(Position position, float portee, TypeDeplacement typeCible);

        /**
          * Choisi parmis les ennemis � port�e lequel attaquer. Fonctionnement similaire � getListeEnnemisPortee().
          * \param Position : position autour de laquelle chercher.
          * \param portee : distance � laquelle limiter la recherche.
          * \param TypeDeplacement : type d'ennemis � chercher.
          * \return Ennemi � attaquer
          */
        static Ennemi* getCible(Position position, float portee, TypeDeplacement typeCible);

    };

}

#include "Ennemis/Cafard.h"
#include "Ennemis/Fourmi.h"
#include "Ennemis/Guepe.h"
#include "Ennemis/Moustique.h"

#endif // ENNEMI_H
