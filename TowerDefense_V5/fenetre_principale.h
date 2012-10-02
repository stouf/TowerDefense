#ifndef FENETRE_PRINCIPALE_H
#define FENETRE_PRINCIPALE_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QPushButton>
#include <QColor>
#include <QGridLayout>
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include <QGroupBox>
#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>

#include "carte.h"
#include "my_q_graphics_scene.h"

#include "Defenseur.h"
#include "Ennemi.h"
#include "vagues.h"


namespace TOWERDEFENSE
{
    class FenetrePrincipale : public QMainWindow
    {
        Q_OBJECT

    private:

        // Attributs
        QAction *actionNouvelle_Partie;
        QAction *actionSauvegarder_la_Partie;
        QAction *actionCharger_une_Partie;
        QAction *actionA_Propos;
        QWidget *centralWidget;
        QLabel *labelDescriptionVague;
        QGroupBox *groupBoxInformationsJeu;
        QLCDNumber *lcdNumberCredits;
        QLCDNumber *lcdNumberVies;
        QLabel *labelCredits;
        QLabel *labelVies;
        QPushButton *boutonLancerVague;
        QPushButton *boutonPause;
        QGroupBox *groupBoxCreationDefense;
        QPushButton *boutonCreerPistoleteau;
        QPushButton *boutonCreerLancepierre;
        QPushButton *boutonCreerPaintball;
        QPushButton *boutonCreerPetanque;
        QPushButton *boutonCreerMusicien;
        QGroupBox *groupBoxInformations;
        QLabel *labelDefenseurType;
        QLabel *labelDefenseurCibles;
        QLabel *labelDefenseurPortee;
        QLabel *labelDefenseurCadence;
        QLabel *labelDefenseurFrappe;
        QLabel *labelDefenseurNiveau;
        QPushButton *boutonSupprimerDefense;
        QPushButton *boutonAmeliorerDefense;
        QLabel *labelDefenseurType_info;
        QLabel *labelDefenseurCibles_info;
        QLabel *labelDefenseurPortee_info;
        QLabel *labelDefenseurCadence_info;
        QLabel *labelDefenseurFrappe_info;
        QLabel *labelDefenseurNiveau_info;
        QWidget *widgetCarte;
        QStatusBar *statusBar;
        QMenuBar *menuBar;
        QMenu *menuTowerDefense;
        QMenu *menuAide;
        QGraphicsView* carteGraphicsView;
        MyQGraphicsScene* carteGraphicsScene;

        bool insertionDefence;

        EnnemiFactory* ennFact;
        DefenseurFactory* defFact;
        
        QTimer* timer;

        int numVague;
        Vagues vagues;





        // Methodes

        /*!
          * Cette fonction retourne l'echelle a laquelle il faut multiplier l'image afin qu'elle puisse etre contenue par une zone dont les limites sont donnees
          * \param image L'image pour laquelle il faut trouver une echelle
          * \param largeur La largeur de la zone de destination
          * \param longueur La longueur de la zone de destination
          * \return Un reel representant l'echelle recherchee
          */
        float ScalePourUnite(const QPixmap& image, float largeur, float hauteur) const;

        /*!
          * Cette fonction va actualiser graphiquement l'etat courant de la carte
          */
        void AfficherCarte() const;


    public:

        /*!
          * Constructeur principal
          * Il prend en parametre un objet parent et un chemin vers une image de fond
          * \param parent Un pointeur vers un QWidget parent de l'objet a construire
          * \param arrierePlanPath Chemin vers un fichier a charger en arriere plan
          */
        explicit FenetrePrincipale(QWidget *parent = 0);

        /*!
          * Destructeur
          */
        ~FenetrePrincipale();



        void rechercheDepart(int* x, int* y) const;


    public slots:
        /*!
          * Ce slot active l'insertion d'element par clic de bouton d'un des elements de la defense.
          */
        void activerInsertion();

        /*!
          * Ce slot est recu de la part de son attribut carteGraphicsScene (de type MyQGraphicsScene)
          * Il recoit un signal nommee mauvaisEndroitClique() dans le cas ou l'utilisateur tente de cliquer la ou il ne peut pas ajouter d'element
          * Le seul but de ce slot est d'afficher un message indiquant l'erreur a l'utilisateur, et de reafficher le messgae original
          */
        void mauvaisEndroitClique();

        /*!
          * Ce slot permet le raffraichissement de l'affichage du nombre de crédit dans le panneau LCD
          */
        void creditChanged();

        /*!
          * Ce slot permet le raffraichissement de l'affichage du nombre de vies restant dans le panneau LCD
          */
        void viesChanged();

        /**
          * Ce slot indique à l'interface que le joueur n'a plus de vies.
          */
        void plusDeVies();

        /*!
          * Ce slot permet l'ajout des ennemi dans l'affichage
          * \param ennemi Pointeur sur l'ennemi à ajouter
          */
        void ajouterEnnemi(Ennemi* ennemi);

        /*!
          * Ce slot permet la suppression d'un ennemi dans l'affichage
          * \param ennemi Pointeur sur l'ennemi à supprimer
          */
        void supprimerEnnemi(Ennemi* ennemi);

        /**
          * Ce slot permet l'ajout d'un défenseur dans l'affichage
          * \param defenseur Défenseur à ajouter
          */
        void ajouterDefenseur(Defenseur* defenseur);

        /**
          * Ce slot permet la suppression d'un défenseur dans l'affichage
          * \param defenseur Défenseur à supprimer
          */
        void supprimerDefenseur(Defenseur* defenseur);

        /**
          * Ce slot permet l'ajout d'un projectile dans l'affichage
          * \param projectile Projectile à ajouter
          */
        void ajouterProjectile(Projectile* projectile);

        /**
          * Ce slot permet la suppression d'un projectile dans l'affichage
          * \param projectile Projectile à supprimer
          */
        void supprimerProjectile(Projectile* projectile);

        /**
          * Ce slot permet le lancement d'une nouvelle vague d'ennemis
          */
        void lancerVague();

        /**
          * Slot appelé à chaque tick de timer afin de gérer la création des ennemis de la vague.
          */
        void timerVague();

        /**
          * Slot appelé lorsqu'il n'y a plus d'ennemis dans la vague.
          */
        void vagueTerminee();

        /**
          * Slot demandant l'affichage des informations du défenseur dans l'interface.
          * \param defenseur Pointeur sur le défenseur à afficher
          */
        void afficherInfosDefenseur(Defenseur* defenseur);

        /**
          * Slot permettant le lancement d'une nouvelle partie.\n
          * Remise à zéro des paramètres du jeu, chargement de la carte, des vagues.
          */
        void lancerNouvellePartie();

        /**
          * Slot permettant la mise en pause du jeu, ou sa remise en route.
          */
        void slotPause();


    };
}

#endif // FENETRE_PRINCIPALE_H
