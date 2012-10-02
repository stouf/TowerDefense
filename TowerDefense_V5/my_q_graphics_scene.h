#ifndef MY_Q_GRAPHICS_SCENE_H
#define MY_Q_GRAPHICS_SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>

#include "constantes.h"
#include "Enum.h"
#include "JoueurSingleton.h"
#include "Defenseur.h"
#include "Ennemi.h"
#include "Position.h"


namespace TOWERDEFENSE
{

    class Defenseur;
    class MyQGraphicsScene : public QGraphicsScene
    {
        Q_OBJECT

    private:
        // Attributs
        bool insertionActive;           ///< Indique si on est en train de placer une d�fense.
        static int largeurUnite;        ///< Largeur d'une case (en pixels).
        static int hauteurUnite;        ///< Hauteur d'une case (en pixels).
        TypeDefenseur ajoutDefense;     ///< Type de d�fenseur en cours de placement.
        Defenseur* infosDefense;        ///< Pointeur sur le d�fenseur actuellement s�lectionn�. Si pas de d�fenseur s�lectionn�, vaut 0.


    public:

        /*!
          * Constructeur par defaut
          *  Herite de la classe QGraphicsScene
          */
        explicit MyQGraphicsScene(QObject *parent = 0);

        /*!
          * Methode herite de la classe QGraphicsScene
          */
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

        /*!
          * Methode herite de la classe QGraphicsScene
          */
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


        // Accesseurs et mutateurs

        /*!
          * Cette methode sert a rendre l'insertion d'elements active sur la scene
          * \param valeur La valeur de verite pour l'insertion d'elements
          */
        void setInsertionActive(bool valeur);

        /*!
          * Cette methode sert a indiquer quel defense sera ajoutee lors d'un clic sur la carte
          * \param valeur Le type de defense a ajouter (de type TypeDefense, qui est une enumeration)
          */
        void setAjoutDefense(TypeDefenseur valeur);

        /*!
          * Cette methode retourne la hauteur d'un des carres-unite composant la scene de jeu
          * \return La hauteur d'un des carres-unite composant la scene de jeu
          */
        static int getLargeurUnite();

        /*!
          * Cette methode retourne la largeur d'un des carres-unite composant la scene de jeu
          * \return La largeur d'un des carres-unite composant la scene de jeu
          */
        static int getHauteurUnite();


    signals:
        /*!
          * Ce signal est envoye dans le cas ou l'utilisateur clique sur une partie de la carte ou il ne peut pas inclure de defense
          * Ce signal sera envoye a un objet de type FenetrePrincipale, incluant this.
          * Il sera recupere par le slot mauvaisEndroitClique
          */
        void mauvaisEndroitClique();

        /**
          * D�clenche l'affichage des informatiosn du d�fenseur.
          */
        void signalAfficherInfosDefenseur(Defenseur* defenseur);

    public slots:
        /**
          * D�clenche l'am�lioration du d�fenseur actuellement s�lectionn�.
          */
        void ameliorerDefenseur();

        /**
          * D�clenche la suppression du d�fenseur actuellement s�lectionn�.
          */
        void supprimerDefenseur();

        /**
          * D�clenche le raffraichissement du nombre de cr�dits.
          */
        void creditChanged();

    };
}

#endif // MY_Q_GRAPHICS_SCENE_H
