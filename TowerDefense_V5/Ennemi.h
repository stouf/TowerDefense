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
        TypeDeplacement typeDeplacement;    ///< Type de déplacement courant de l'ennemi.
        float taille;       ///< Taille en unité de l'ennemi.
        float resistance;   ///< Résistance de l'ennemi.
        float vitaliteBase; ///< Vitalité de base de l'ennemi.
        float vitalite;     ///< Vitalité courante de l'ennemi (vitalité de base - dégats reçus).
        float vitesse;      ///< Vitesse de déplacement de base de l'ennemi.
        int timerMalusVitesse;  ///< Nombre de Tick de timer restant avant la fin du malus de vitesse suite à une touche par une bille de Paint-Ball. 0 si pas de malus.
        float angle;        ///< Direction du déplacement


    public:
        int ID;             ///< ID utilisé pour le debug
        // Constructeur
        /**
          * Peut être utilisé pour la création d'un nouvel ennemi, ou pour le chargement d'un ennemi lors d'une sauvegarde de la partie.
          * \param Position : position de l'ennemi.
          * \param TypeDeplacement : type de déplacement de l'ennemi.
          * \param taille : taille de l'ennemi, en unités.
          * \param resistance : resistance de l'ennemi.
          * \param vitaliteBase : vitalité de base de l'ennemi.
          * \param vitalite : vitalité courante de l'ennemi.
          * \param vitesse : vitesse de base de l'ennemi.
          * \param timerMalusVitesse : nombre de tick de timer restant avant la fin du malus de vitesse suite à une touche par une bille de Paint-Ball. 0 si pas de malus.
          */
        Ennemi(Position position, TypeDeplacement typeDeplacement, float taille, float resistance, float vitaliteBase, float vitalite, float vitesse, int timerMalusVitesse = 0);

        // Methodes

        /**
          * \return Taille de l'ennemi
          */
        virtual float getTaille() const;

        /**
          * \return résistance de l'ennemi
          */
        virtual float getResistance() const;

        /**
          * \return vitalité de base de l'ennemi
          */
        virtual float getVitaliteBase() const;

        /**
          * \return Vitalité restant à l'ennemi
          */
        virtual float getVitalite() const;

        /**
          * \return Vitesse de base de l'ennemi
          */
        virtual float getVitesseBase() const;

        /**
          * \return Vitesse courante de l'ennemi, après application des bonus et malus de vitesse.
          */
        virtual float getVitesse() const;

        /**
          * \return Type de déplacement courant de l'ennemi
          */
        virtual TypeDeplacement getTypeDeplacement() const;

        /**
          * \return Position courante de l'ennemi
          */
        virtual Position getPosition() const;

        /**
          * Effectue les opérations de base lorsque l'ennemi est atteint par un projectile :
          * - Inflige les dégats via la méthode recevoirDegats()
          * - Suivant les projectiles, effectue différentes opérations (ralentissement si bille de Paint-Ball, dégats aux voisins si boule de pétanque).
          * \param Projectile : projectile qui vient d'atteindre la cible
          */
        virtual void recevoirProjectile(Projectile* projectile);

        /**
          * Calcule les dégats à infliger en fonction de la puissance de la frappe et met à jour la vitalité.\n
          * Appelle la méthode mort() lorsque la vitalité devient nulle.
          */
        virtual void recevoirDegats(float degats);

        /**
          * Appelée lorsque la vitalité de l'ennemi vaut 0.\n
          * Crédite le joueur de la taille de l'ennemi.
          */
        virtual void mort();

        // Fonction des QGraphicsItem

        /**
          * Surcharge de la méthode héritée de QGraphicsItem.\n
          * Définit la zone de collision de l'ennemi.
          */
        virtual QRectF boundingRect() const;

        /**
          * Surcharge de la méthode héritée de QGraphicsItem.\n
          * Permet de définir la forme affichée à l'écran.
          */
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        /**
          * Surcharge de la méthode héritée de QGraphicsItem.\n
          * Appelée à chaque Tick du timer.\n
          * Utilisée pour gérer les actions effectuées par les ennemis (suivi du chemin, arrivée au but).
          */
        virtual void advance(int phase);

    };

    class EnnemiFactory : public QObject
    {
        Q_OBJECT
    private:
        static std::vector<Ennemi*> listeEnnemis;   ///< Liste des ennemis présents dans le jeu. Utilisée par le mécanisme.
        static int nombreEnnemis;                   ///< Nombre d'ennemis créés dans le jeu (depuis le début de la partie).

    public:
        /**
          * Constructeur de la factory.
          */
        EnnemiFactory();

        /**
          * Méthode utilisée pour la création d'un nouvel ennemi.\n
          * Se charge de toutes les opérations de base :
          * - Construction
          * - Affichage
          * - Insertion dans les mécanismes
          * \return Pointeur sur l'ennemi créé.
          */
        static Ennemi* getEnnemi(TypeEnnemi typeEnnemi, Position position, float taille);

        /**
          * Méthode utilisée pour supprimer un ennemi du jeu :
          * - Suppression des mécanismes
          * - Ajout des crédits correspondant à la vente.
          */
        static void eraseEnnemi(Ennemi* ennemi);

        /**
          * \return Nombre d'ennemis créés depuis le début de la partie
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
          * \return Liste des ennemis du type spécifié actuellement vivant.
          */
        static std::vector<Ennemi*> getListeEnnemis(TypeDeplacement typeCible);

        /**
          * Effectue une recherche d'ennemis du type spécifié, à une distance portee autour de la position spécifiée.
          * \param Position : position autour de laquelle chercher.
          * \param portee : distance à laquelle limiter la recherche.
          * \param TypeDeplacement : type d'ennemis à chercher
          * \return Liste d'ennemis répondant à la recherche.
          */
        static std::vector<Ennemi*> getListeEnnemisPortee(Position position, float portee, TypeDeplacement typeCible);

        /**
          * Choisi parmis les ennemis à portée lequel attaquer. Fonctionnement similaire à getListeEnnemisPortee().
          * \param Position : position autour de laquelle chercher.
          * \param portee : distance à laquelle limiter la recherche.
          * \param TypeDeplacement : type d'ennemis à chercher.
          * \return Ennemi à attaquer
          */
        static Ennemi* getCible(Position position, float portee, TypeDeplacement typeCible);

    };

}

#include "Ennemis/Cafard.h"
#include "Ennemis/Fourmi.h"
#include "Ennemis/Guepe.h"
#include "Ennemis/Moustique.h"

#endif // ENNEMI_H
