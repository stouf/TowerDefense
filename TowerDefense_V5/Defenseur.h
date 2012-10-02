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
        Position position;  ///< Position du d�fenseur.
        int niveau;         ///< Niveau courant du d�fenseur.

    public:
        // Constructeur
        /**
          * \param position : Position du d�fenseur
          * \param niveau : Niveau du d�fenseur
          */
        Defenseur(Position position, int niveau);

        // Methodes
        /**
          * Retourne la position du d�fenseur.
          */
        virtual Position getPosition() const;

        /**
          * Retourne le niveau du d�fenseur.
          */
        virtual float getNiveau() const;

        /**
          * Retourne la portee du d�fenseur, en nombre de cases.
          */
        virtual float getPortee() = 0;

        /**
          * Retourne une chaine de caract�re correspondant au type de d�fenseur.\n
          * Utilis� pour l'affichage des informations des d�fenseurs dans l'interface de jeu.
          */
        virtual QString getTypeDefenseur() = 0;



        /**
          * V�rifie si le d�fenseur peut �tre am�lior� ou non :
          * - V�rification des cr�dits
          * - V�rification du niveau (niveau < niveauMax)
          */
        virtual bool peutAmeliorer() const = 0;

        /**
          * Augmentation du niveau du d�fenseur.\n
          * V�rifie si le d�fenseur peut �tre am�lior� avant d'effectuer l'am�lioration.
          */
        virtual void ameliorer();

        /**
          * Retourne le nombre de cr�dits n�cessaires � l'achat d'un niveau.
          * \param level : Niveau pour lequel on souhaite connaitre le prix.
          */
        virtual int coutAchat(int level = 1) = 0;

        // Fonction des QGraphicsItem
        /**
          * Surcharge de la m�thode h�rit�e de QGraphicsItem.\n
          * D�finit la zone de collision du d�fenseur.
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
          * Utilis�e pour g�rer les actions effectu�es par le d�fenseur (recherche des ennemis, vis�e, tir,...).
          */
        virtual void advance(int phase) = 0;

    };

    class Attaquant : public Defenseur
    {
    private:
        TypeDeplacement typeCible;          ///< Type de cible pouvant �tre atteint
        TypeProjectile typeProjectile;      ///< Type de projectiles lanc�
        int vitesseProjectile;              ///< Vitesse des projectiles lanc�s
        int timerProchaineFrappe;           ///< Intervalle avant la prochaine frappe

    public:
        /**
          * D�finition des diff�rents param�tres du d�fenseur.
          * \param typeCible : Type de cible pouvant �tre atteint.
          * \param typeProjectile : Type de projectile lanc�. Utilis� pour l'affectation d'actions sp�ciales (explosion, baisse de la vitesse,...).
          * \param position : Position du d�fenseur. Valeur envoy�e au constructeur de Defenseur.
          * \param niveau : Niveau du d�fenseur. Valeur envoy�e au constructeur de Defenseur.
          * \param vitesseProjectile : Vitesse du projectile lanc� par l'attaquant.
          * \param timerProchaineFrappe : Nombre de tick de timer avant de pouvoir tirer.
          */
        Attaquant(TypeDeplacement typeCible, TypeProjectile typeProjectile, Position position, int niveau, int vitesseProjectile, int timerProchaineFrappe);

        /**
          * Retourne le nombre de projectiles pouvant �tre lanc� par secondes.
          */
        virtual float getCadence() = 0;

        /**
          * Retourne le mode de d�placement des cibles pouvant �tre touch�es.
          */
        virtual TypeDeplacement getTypeCibles();

        /**
          * Retourne la puissance de base du d�fenseur, sans les bonus.
          */
        virtual float getPuissanceBase() const = 0;

        /**
          * Retourne la puissance du d�fenseur apr�s application des bonus.
          */
        float getPuissance() const;

        /**
          * Retourne le bonus (en pourcentage) de puissance gagn� grace aux musiciens.
          */
        virtual float getBonusFrappe() const;

        virtual void advance(int phase);

    };

    class DefenseurFactory : public QObject
    {
        Q_OBJECT

        static float nombreDefenseurs;      ///< Nombre de d�fenseurs
        static std::vector<Defenseur*> listeDefenseurs; ///< Liste des d�fenseurs. Utilis� pour les op�rations du jeu (plus rapide que la recherche par items de la QGraphicsScene).

    public:
        /**
          * Cr�ation d'une instance de la factory.
          */
        DefenseurFactory();

        /**
          * Retourne vrai si le d�fenseur peut-�tre achet� au niveau sp�cifi�.\n
          * Utilis� par le m�canisme de jeu, et pour l'activation des boutons de cr�ation ou d'am�lioration des d�fenseurs.\n
          * Fait appel aux m�thodes peutAmeliorer().
          * \param typeDefenseur : Type de d�fenseur � tester.
          * \param level : Niveau � tester.
          * \return True si un d�fenseur du type sp�cifi� peut-�tre achet� au niveau sp�cifi�, False sinon.
          */
        static bool peutAcheter(TypeDefenseur typeDefenseur, int level = 1);

        /**
          * M�thode utilis�e pour la cr�ation d'un nouveau d�fenseur.\n
          * Se charge de toutes les op�rations de base :
          * - Construction
          * - Affichage
          * - Insertion dans les m�canismes
          * \return Pointeur sur le d�fenseur cr��.
          */
        static Defenseur* getDefenseur(TypeDefenseur typeDefenseur, Position position);

        /**
          * M�thode utilis�e pour supprimer un d�fenseur du jeu :
          * - Suppression des m�canismes
          * - Ajout des cr�dits correspondant � la vente.
          */
        static void eraseDefenseur(Defenseur* ptdefenseur);

        /**
          * Utilis� pour am�liorer d'un niveau un d�fenseur.\n
          * Fait appel � la m�thode ameliorer() des d�fenseurs.
          */
        static void updateDefenseur(Defenseur* defenseur);

        /**
          * Retourne le nombre de d�fenseurs existant.
          * \return Nombre de d�fenseurs du jeu.
          */
        int getNombreDefenseurs() const;

        /**
          * Retourne une liste des d�fenseurs pr�sents dans le jeu.
          * \return Liste des d�fenseurs du jeu.
          */
        static std::vector<Defenseur*> getListeDefenseurs();

        /**
          * Retourne une liste des musiciens ayant une influence sur la position pass�e en param�tre.\n
          * Utilis�e pour savoir si un Attaquant recoit ou non des bonus.
          * \param Position sur l'aire de jeu.
          * \return Liste des d�fenseurs ayant une influence sur la position pass�e en param�tre.
          */
        static std::vector<Musicien*> getListeMusiciens(Position position);

    signals:
        /**
          * Signal envoy� � la sc�ne pour lui signaler qu'un d�fenseur a �t� supprim�.
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
