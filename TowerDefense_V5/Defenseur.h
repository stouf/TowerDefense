#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <QGraphicsItem>
#include <QMessageBox>

#include <string>
#include <iostream>
#include <vector>



#include "Position.h"
#include "Enum.h"
#include "Position.h"
#include "Ennemi.h"
#include "JoueurSingleton.h"
#include "Projectile.h"
#include "ProjectileFactory.h"

#include "my_q_graphics_scene.h"



namespace TOWERDEFENSE
{

    class Ennemi;
    class Musicien;
    class Defenseur : public QGraphicsItem
    {

    protected:
        // Attributs
        Position position;  ///< Position du défenseur.
        int niveau;         ///< Niveau courant du défenseur.

    public:
        // Constructeur
        /**
          * \param position : Position du défenseur
          * \param niveau : Niveau du défenseur
          */
        Defenseur(Position position, int niveau);

        // Methodes
        /**
          * Retourne la position du défenseur.
          */
        virtual Position getPosition() const;

        /**
          * Retourne le niveau du défenseur.
          */
        virtual float getNiveau() const;

        /**
          * Retourne la portee du défenseur, en nombre de cases.
          */
        virtual float getPortee() = 0;

        /**
          * Retourne une chaine de caractère correspondant au type de défenseur.\n
          * Utilisé pour l'affichage des informations des défenseurs dans l'interface de jeu.
          */
        virtual QString getTypeDefenseur() = 0;



        /**
          * Vérifie si le défenseur peut être amélioré ou non :
          * - Vérification des crédits
          * - Vérification du niveau (niveau < niveauMax)
          */
        virtual bool peutAmeliorer() const = 0;

        /**
          * Augmentation du niveau du défenseur.\n
          * Vérifie si le défenseur peut être amélioré avant d'effectuer l'amélioration.
          */
        virtual void ameliorer();

        /**
          * Retourne le nombre de crédits nécessaires à l'achat d'un niveau.
          * \param level : Niveau pour lequel on souhaite connaitre le prix.
          */
        virtual int coutAchat(int level = 1) = 0;

        // Fonction des QGraphicsItem
        /**
          * Surcharge de la méthode héritée de QGraphicsItem.\n
          * Définit la zone de collision du défenseur.
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
          * Utilisée pour gérer les actions effectuées par le défenseur (recherche des ennemis, visée, tir,...).
          */
        virtual void advance(int phase) = 0;

    };

    class Attaquant : public Defenseur
    {
    private:
        TypeDeplacement typeCible;          ///< Type de cible pouvant être atteint
        TypeProjectile typeProjectile;      ///< Type de projectiles lancé
        int vitesseProjectile;              ///< Vitesse des projectiles lancés
        int timerProchaineFrappe;           ///< Intervalle avant la prochaine frappe

    public:
        /**
          * Définition des différents paramètres du défenseur.
          * \param typeCible : Type de cible pouvant être atteint.
          * \param typeProjectile : Type de projectile lancé. Utilisé pour l'affectation d'actions spéciales (explosion, baisse de la vitesse,...).
          * \param position : Position du défenseur. Valeur envoyée au constructeur de Defenseur.
          * \param niveau : Niveau du défenseur. Valeur envoyée au constructeur de Defenseur.
          * \param vitesseProjectile : Vitesse du projectile lancé par l'attaquant.
          * \param timerProchaineFrappe : Nombre de tick de timer avant de pouvoir tirer.
          */
        Attaquant(TypeDeplacement typeCible, TypeProjectile typeProjectile, Position position, int niveau, int vitesseProjectile, int timerProchaineFrappe);

        /**
          * Retourne le nombre de projectiles pouvant être lancé par secondes.
          */
        virtual float getCadence() = 0;

        /**
          * Retourne le mode de déplacement des cibles pouvant être touchées.
          */
        virtual TypeDeplacement getTypeCibles();

        /**
          * Retourne la puissance de base du défenseur, sans les bonus.
          */
        virtual float getPuissanceBase() const = 0;

        /**
          * Retourne la puissance du défenseur après application des bonus.
          */
        float getPuissance() const;

        /**
          * Retourne le bonus (en pourcentage) de puissance gagné grace aux musiciens.
          */
        virtual float getBonusFrappe() const;

        virtual void advance(int phase);

    };

    class DefenseurFactory : public QObject
    {
        Q_OBJECT

        static float nombreDefenseurs;      ///< Nombre de défenseurs
        static std::vector<Defenseur*> listeDefenseurs; ///< Liste des défenseurs. Utilisé pour les opérations du jeu (plus rapide que la recherche par items de la QGraphicsScene).

    public:
        /**
          * Création d'une instance de la factory.
          */
        DefenseurFactory();

        /**
          * Retourne vrai si le défenseur peut-être acheté au niveau spécifié.\n
          * Utilisé par le mécanisme de jeu, et pour l'activation des boutons de création ou d'amélioration des défenseurs.\n
          * Fait appel aux méthodes peutAmeliorer().
          * \param typeDefenseur : Type de défenseur à tester.
          * \param level : Niveau à tester.
          * \return True si un défenseur du type spécifié peut-être acheté au niveau spécifié, False sinon.
          */
        static bool peutAcheter(TypeDefenseur typeDefenseur, int level = 1);

        /**
          * Méthode utilisée pour la création d'un nouveau défenseur.\n
          * Se charge de toutes les opérations de base :
          * - Construction
          * - Affichage
          * - Insertion dans les mécanismes
          * \return Pointeur sur le défenseur créé.
          */
        static Defenseur* getDefenseur(TypeDefenseur typeDefenseur, Position position);

        /**
          * Méthode utilisée pour supprimer un défenseur du jeu :
          * - Suppression des mécanismes
          * - Ajout des crédits correspondant à la vente.
          */
        static void eraseDefenseur(Defenseur* ptdefenseur);

        /**
          * Utilisé pour améliorer d'un niveau un défenseur.\n
          * Fait appel à la méthode ameliorer() des défenseurs.
          */
        static void updateDefenseur(Defenseur* defenseur);

        /**
          * Retourne le nombre de défenseurs existant.
          * \return Nombre de défenseurs du jeu.
          */
        int getNombreDefenseurs() const;

        /**
          * Retourne une liste des défenseurs présents dans le jeu.
          * \return Liste des défenseurs du jeu.
          */
        static std::vector<Defenseur*> getListeDefenseurs();

        /**
          * Retourne une liste des musiciens ayant une influence sur la position passée en paramètre.\n
          * Utilisée pour savoir si un Attaquant recoit ou non des bonus.
          * \param Position sur l'aire de jeu.
          * \return Liste des défenseurs ayant une influence sur la position passée en paramètre.
          */
        static std::vector<Musicien*> getListeMusiciens(Position position);

    signals:
        /**
          * Signal envoyé à la scène pour lui signaler qu'un défenseur a été supprimé.
          */
        void supprimerDefenseur(Defenseur* defenseur);
    };

}
#include "Defenseurs/LancePierre.h"
#include "Defenseurs/Musicien.h"
#include "Defenseurs/PaintBall.h"
#include "Defenseurs/Petanque.h"
#include "Defenseurs/PistoletEau.h"

#endif // DEFENSEUR_H
