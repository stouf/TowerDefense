#include "fenetre_principale.h"

namespace TOWERDEFENSE
{
    FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
        QMainWindow(parent)
    {

        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainWindow"));
        this->resize(1024, 768);
        actionNouvelle_Partie = new QAction(this);
        actionNouvelle_Partie->setObjectName(QString::fromUtf8("actionNouvelle_Partie"));
        actionSauvegarder_la_Partie = new QAction(this);
        actionSauvegarder_la_Partie->setObjectName(QString::fromUtf8("actionSauvegarder_la_Partie"));
        actionCharger_une_Partie = new QAction(this);
        actionCharger_une_Partie->setObjectName(QString::fromUtf8("actionCharger_une_Partie"));
        actionA_Propos = new QAction(this);
        actionA_Propos->setObjectName(QString::fromUtf8("actionA_Propos"));
        centralWidget = new QWidget(this);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelDescriptionVague = new QLabel(centralWidget);
        labelDescriptionVague->setObjectName(QString::fromUtf8("labelDescriptionVague"));
        labelDescriptionVague->setGeometry(QRect(20, 700, 672, 20));
        groupBoxInformationsJeu = new QGroupBox(centralWidget);
        groupBoxInformationsJeu->setObjectName(QString::fromUtf8("groupBoxInformationsJeu"));
        groupBoxInformationsJeu->setGeometry(QRect(710, 10, 300, 161));
        groupBoxInformationsJeu->setAutoFillBackground(false);
        lcdNumberCredits = new QLCDNumber(groupBoxInformationsJeu);
        lcdNumberCredits->setObjectName(QString::fromUtf8("lcdNumberCredits"));
        lcdNumberCredits->setGeometry(QRect(20, 52, 121, 41));
        lcdNumberVies = new QLCDNumber(groupBoxInformationsJeu);
        lcdNumberVies->setObjectName(QString::fromUtf8("lcdNumberVies"));
        lcdNumberVies->setGeometry(QRect(160, 50, 121, 41));
        labelCredits = new QLabel(groupBoxInformationsJeu);
        labelCredits->setObjectName(QString::fromUtf8("labelCredits"));
        labelCredits->setGeometry(QRect(20, 30, 111, 21));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        labelCredits->setFont(font);
        labelCredits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelVies = new QLabel(groupBoxInformationsJeu);
        labelVies->setObjectName(QString::fromUtf8("labelVies"));
        labelVies->setGeometry(QRect(160, 30, 111, 21));
        labelVies->setFont(font);
        labelVies->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        boutonLancerVague = new QPushButton(groupBoxInformationsJeu);
        boutonLancerVague->setObjectName(QString::fromUtf8("boutonLancerVague"));
        boutonLancerVague->setGeometry(QRect(20, 110, 121, 31));
        boutonLancerVague->setDisabled(true);

        boutonPause = new QPushButton(groupBoxInformationsJeu);
        boutonPause->setObjectName(QString::fromUtf8("boutonPause"));
        boutonPause->setGeometry(QRect(160, 110, 121, 31));
        boutonPause->setDisabled(true);

        groupBoxCreationDefense = new QGroupBox(centralWidget);
        groupBoxCreationDefense->setObjectName(QString::fromUtf8("groupBoxCreationDefense"));
        groupBoxCreationDefense->setGeometry(QRect(710, 190, 300, 160));
        boutonCreerPistoleteau = new QPushButton(groupBoxCreationDefense);
        boutonCreerPistoleteau->setObjectName(QString::fromUtf8("boutonCreerPistoleteau"));
        boutonCreerPistoleteau->setGeometry(QRect(20, 30, 121, 31));
        boutonCreerPistoleteau->setDisabled(true);
        boutonCreerLancepierre = new QPushButton(groupBoxCreationDefense);
        boutonCreerLancepierre->setObjectName(QString::fromUtf8("boutonCreerLancepierre"));
        boutonCreerLancepierre->setGeometry(QRect(160, 30, 121, 31));
        boutonCreerLancepierre->setDisabled(true);
        boutonCreerPaintball = new QPushButton(groupBoxCreationDefense);
        boutonCreerPaintball->setObjectName(QString::fromUtf8("boutonCreerPaintball"));
        boutonCreerPaintball->setGeometry(QRect(20, 70, 121, 31));
        boutonCreerPaintball->setDisabled(true);
        boutonCreerPetanque = new QPushButton(groupBoxCreationDefense);
        boutonCreerPetanque->setObjectName(QString::fromUtf8("boutonCreerPetanque"));
        boutonCreerPetanque->setGeometry(QRect(160, 70, 121, 31));
        boutonCreerPetanque->setDisabled(true);
        boutonCreerMusicien = new QPushButton(groupBoxCreationDefense);
        boutonCreerMusicien->setObjectName(QString::fromUtf8("boutonCreerMusicien"));
        boutonCreerMusicien->setGeometry(QRect(20, 110, 121, 31));
        boutonCreerMusicien->setDisabled(true);
        groupBoxInformations = new QGroupBox(centralWidget);
        groupBoxInformations->setObjectName(QString::fromUtf8("groupBoxInformations"));
        groupBoxInformations->setEnabled(true);
        groupBoxInformations->setGeometry(QRect(710, 370, 300, 201));
        groupBoxInformations->setMinimumSize(QSize(299, 200));
        groupBoxInformations->hide();
        labelDefenseurType = new QLabel(groupBoxInformations);
        labelDefenseurType->setObjectName(QString::fromUtf8("labelDefenseurType"));
        labelDefenseurType->setGeometry(QRect(20, 20, 80, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelDefenseurType->setFont(font1);
        labelDefenseurCibles = new QLabel(groupBoxInformations);
        labelDefenseurCibles->setObjectName(QString::fromUtf8("labelDefenseurCibles"));
        labelDefenseurCibles->setGeometry(QRect(20, 40, 80, 16));
        labelDefenseurCibles->setFont(font1);
        labelDefenseurPortee = new QLabel(groupBoxInformations);
        labelDefenseurPortee->setObjectName(QString::fromUtf8("labelDefenseurPortee"));
        labelDefenseurPortee->setGeometry(QRect(20, 60, 80, 16));
        labelDefenseurPortee->setFont(font1);
        labelDefenseurCadence = new QLabel(groupBoxInformations);
        labelDefenseurCadence->setObjectName(QString::fromUtf8("labelDefenseurCadence"));
        labelDefenseurCadence->setGeometry(QRect(20, 80, 80, 16));
        labelDefenseurCadence->setFont(font1);
        labelDefenseurFrappe = new QLabel(groupBoxInformations);
        labelDefenseurFrappe->setObjectName(QString::fromUtf8("labelDefenseurFrappe"));
        labelDefenseurFrappe->setGeometry(QRect(20, 100, 80, 16));
        labelDefenseurFrappe->setFont(font1);
        labelDefenseurNiveau = new QLabel(groupBoxInformations);
        labelDefenseurNiveau->setObjectName(QString::fromUtf8("labelDefenseurNiveau"));
        labelDefenseurNiveau->setGeometry(QRect(20, 120, 80, 16));
        labelDefenseurNiveau->setFont(font1);
        boutonSupprimerDefense = new QPushButton(groupBoxInformations);
        boutonSupprimerDefense->setObjectName(QString::fromUtf8("boutonSupprimerDefense"));
        boutonSupprimerDefense->setGeometry(QRect(160, 150, 121, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        boutonSupprimerDefense->setFont(font2);
        boutonAmeliorerDefense = new QPushButton(groupBoxInformations);
        boutonAmeliorerDefense->setObjectName(QString::fromUtf8("boutonAmeliorerDefense"));
        boutonAmeliorerDefense->setGeometry(QRect(20, 150, 121, 31));
        boutonAmeliorerDefense->setFont(font1);
        labelDefenseurType_info = new QLabel(groupBoxInformations);
        labelDefenseurType_info->setObjectName(QString::fromUtf8("labelDefenseurType_info"));
        labelDefenseurType_info->setGeometry(QRect(130, 20, 160, 16));
        labelDefenseurType_info->setFont(font1);
        labelDefenseurCibles_info = new QLabel(groupBoxInformations);
        labelDefenseurCibles_info->setObjectName(QString::fromUtf8("labelDefenseurCibles_info"));
        labelDefenseurCibles_info->setGeometry(QRect(130, 40, 160, 16));
        labelDefenseurCibles_info->setFont(font1);
        labelDefenseurPortee_info = new QLabel(groupBoxInformations);
        labelDefenseurPortee_info->setObjectName(QString::fromUtf8("labelDefenseurPortee_info"));
        labelDefenseurPortee_info->setGeometry(QRect(130, 60, 160, 16));
        labelDefenseurPortee_info->setFont(font1);
        labelDefenseurCadence_info = new QLabel(groupBoxInformations);
        labelDefenseurCadence_info->setObjectName(QString::fromUtf8("labelDefenseurCadence_info"));
        labelDefenseurCadence_info->setGeometry(QRect(130, 80, 160, 16));
        labelDefenseurCadence_info->setFont(font1);
        labelDefenseurFrappe_info = new QLabel(groupBoxInformations);
        labelDefenseurFrappe_info->setObjectName(QString::fromUtf8("labelDefenseurFrappe_info"));
        labelDefenseurFrappe_info->setGeometry(QRect(130, 100, 160, 16));
        labelDefenseurFrappe_info->setFont(font1);
        labelDefenseurNiveau_info = new QLabel(groupBoxInformations);
        labelDefenseurNiveau_info->setObjectName(QString::fromUtf8("labelDefenseurNiveau_info"));
        labelDefenseurNiveau_info->setGeometry(QRect(130, 120, 160, 16));
        labelDefenseurNiveau_info->setFont(font1);


        widgetCarte = new QWidget(centralWidget);
        widgetCarte->setPalette(QColor("white"));
        widgetCarte->setAutoFillBackground(true);
        widgetCarte->setGeometry(QRect(10, 10, 691, 691));
        widgetCarte->setObjectName(QString::fromUtf8("widgetCarte"));

        carteGraphicsScene = new MyQGraphicsScene;
        carteGraphicsScene->setSceneRect(10, 10, Constantes::largeurGraphicsScene, Constantes::hauteurGraphicsScene);
        carteGraphicsView = new QGraphicsView(carteGraphicsScene, widgetCarte);
        carteGraphicsView->setBackgroundBrush(QPixmap(QString(":/images/herbe.jpg")));

        this->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(this);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        this->setStatusBar(statusBar);
        menuBar = new QMenuBar(this);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuTowerDefense = new QMenu(menuBar);
        menuTowerDefense->setObjectName(QString::fromUtf8("menuTowerDefense"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        this->setMenuBar(menuBar);

        menuBar->addAction(menuTowerDefense->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuTowerDefense->addAction(actionNouvelle_Partie);
        menuTowerDefense->addAction(actionSauvegarder_la_Partie);
        menuTowerDefense->addAction(actionCharger_une_Partie);
        menuAide->addAction(actionA_Propos);


        this->setWindowTitle(QApplication::translate("MainWindow", "Tower Defense - LO21", 0, QApplication::UnicodeUTF8));
        actionNouvelle_Partie->setText(QApplication::translate("MainWindow", "Nouvelle Partie", 0, QApplication::UnicodeUTF8));
        actionNouvelle_Partie->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSauvegarder_la_Partie->setText(QApplication::translate("MainWindow", "Sauvegarder la Partie", 0, QApplication::UnicodeUTF8));
        actionSauvegarder_la_Partie->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionCharger_une_Partie->setText(QApplication::translate("MainWindow", "Charger une Partie", 0, QApplication::UnicodeUTF8));
        actionCharger_une_Partie->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionA_Propos->setText(QApplication::translate("MainWindow", "A Propos", 0, QApplication::UnicodeUTF8));
        actionA_Propos->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        labelDescriptionVague->setText(QApplication::translate("MainWindow", "Aucune vague en cours...", 0, QApplication::UnicodeUTF8));
        groupBoxInformationsJeu->setTitle(QApplication::translate("MainWindow", "Informations de la partie", 0, QApplication::UnicodeUTF8));
        labelCredits->setText(QApplication::translate("MainWindow", "Cr\303\251dits", 0, QApplication::UnicodeUTF8));
        labelVies->setText(QApplication::translate("MainWindow", "Vies", 0, QApplication::UnicodeUTF8));
        boutonLancerVague->setText(QApplication::translate("MainWindow", "Lancer la Vague", 0, QApplication::UnicodeUTF8));
        boutonPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        groupBoxCreationDefense->setTitle(QApplication::translate("MainWindow", "Cr\303\251er une d\303\251fense", 0, QApplication::UnicodeUTF8));
        boutonCreerPistoleteau->setText(QApplication::translate("MainWindow", "Pistolet \303\240 Eau", 0, QApplication::UnicodeUTF8));
        boutonCreerLancepierre->setText(QApplication::translate("MainWindow", "Lance-Pierre", 0, QApplication::UnicodeUTF8));
        boutonCreerPaintball->setText(QApplication::translate("MainWindow", "Paint-Ball", 0, QApplication::UnicodeUTF8));
        boutonCreerPetanque->setText(QApplication::translate("MainWindow", "P\303\251tanque", 0, QApplication::UnicodeUTF8));
        boutonCreerMusicien->setText(QApplication::translate("MainWindow", "Musicien", 0, QApplication::UnicodeUTF8));
        groupBoxInformations->setTitle(QApplication::translate("MainWindow", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        labelDefenseurType->setText(QApplication::translate("MainWindow", "Type :", 0, QApplication::UnicodeUTF8));
        labelDefenseurCibles->setText(QApplication::translate("MainWindow", "Cibles :", 0, QApplication::UnicodeUTF8));
        labelDefenseurPortee->setText(QApplication::translate("MainWindow", "Port\303\251e :", 0, QApplication::UnicodeUTF8));
        labelDefenseurCadence->setText(QApplication::translate("MainWindow", "Cadence :", 0, QApplication::UnicodeUTF8));
        labelDefenseurFrappe->setText(QApplication::translate("MainWindow", "Frappe :", 0, QApplication::UnicodeUTF8));
        labelDefenseurNiveau->setText(QApplication::translate("MainWindow", "Niveau :", 0, QApplication::UnicodeUTF8));
        boutonSupprimerDefense->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        boutonAmeliorerDefense->setText(QApplication::translate("MainWindow", "Am\303\251liorer", 0, QApplication::UnicodeUTF8));
        labelDefenseurType_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDefenseurCibles_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDefenseurPortee_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDefenseurCadence_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDefenseurFrappe_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        labelDefenseurNiveau_info->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        menuTowerDefense->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));


        timer = new QTimer();


        // Connexion des signaux et des slots
        QObject::connect(timer, SIGNAL(timeout()), carteGraphicsScene, SLOT(advance()));
        QObject::connect(boutonLancerVague, SIGNAL(clicked()), this, SLOT(lancerVague()));
        QObject::connect(boutonPause, SIGNAL(clicked()), this, SLOT(slotPause()));
        QObject::connect(boutonCreerPaintball, SIGNAL(clicked()), this, SLOT(activerInsertion()));
        QObject::connect(boutonCreerLancepierre, SIGNAL(clicked()), this, SLOT(activerInsertion()));
        QObject::connect(boutonCreerPetanque, SIGNAL(clicked()), this, SLOT(activerInsertion()));
        QObject::connect(boutonCreerPistoleteau, SIGNAL(clicked()), this, SLOT(activerInsertion()));
        QObject::connect(boutonCreerMusicien, SIGNAL(clicked()), this, SLOT(activerInsertion()));
        QObject::connect(boutonAmeliorerDefense, SIGNAL(clicked()), carteGraphicsScene, SLOT(ameliorerDefenseur()));
        QObject::connect(boutonSupprimerDefense, SIGNAL(clicked()), carteGraphicsScene, SLOT(supprimerDefenseur()));

        QObject::connect(carteGraphicsScene, SIGNAL(mauvaisEndroitClique()), this, SLOT(mauvaisEndroitClique()));

        // Connexion entre les factories et la partie graphique
        // Mise à jour des informations courantes du jeu
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(creditChanged()), this, SLOT(creditChanged()));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(creditChanged()), carteGraphicsScene, SLOT(creditChanged()));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(viesChanged()), this, SLOT(viesChanged()));
        QObject::connect(carteGraphicsScene, SIGNAL(signalAfficherInfosDefenseur(Defenseur*)), this, SLOT(afficherInfosDefenseur(Defenseur*)));


        // Gestion de l'affichage des ennemis
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalAjouterEnnemi(Ennemi*)), this, SLOT(ajouterEnnemi(Ennemi*)));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalEnnemiMort(Ennemi*)), this, SLOT(supprimerEnnemi(Ennemi*)));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalEnnemiBut(Ennemi*)), this, SLOT(supprimerEnnemi(Ennemi*)));

        // Gestion de l'affichage des defenseurs
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalAjouterDefenseur(Defenseur*)), this, SLOT(ajouterDefenseur(Defenseur*)));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalSupprimerDefenseur(Defenseur*)), this, SLOT(supprimerDefenseur(Defenseur*)));

        // Gestion de l'affichage des projectiles
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalAjouterProjectile(Projectile*)), this, SLOT(ajouterProjectile(Projectile*)));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalSupprimerProjectile(Projectile*)), this, SLOT(supprimerProjectile(Projectile*)));

        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalPlusDeVies()), this, SLOT(plusDeVies()));
        QObject::connect(JoueurSingleton::getInstance(), SIGNAL(signalVagueTerminee()), this, SLOT(vagueTerminee()));

        QObject::connect(actionNouvelle_Partie, SIGNAL(triggered()), this, SLOT(lancerNouvellePartie()));





    }


    FenetrePrincipale::~FenetrePrincipale()
    {
        /*delete contenu;

        // Suppression des layout
        delete layoutPrincipal;
        delete panneauControleLayout;

        // Suppression de tout ce qui compose le panneau de controle a droite
        delete lancerVagueBouton;
        delete nbViesLCD;
        delete nbViesLabel;
        delete nbCreditsLCD;
        delete nbCreditsLabel;
        delete pistoletEauBouton;
        delete lancePierreBouton;
        delete paintBallBouton;
        delete petanqueBouton;
        delete panneauControleWidget;

        // Suppression de tout ce qui compose la carte de jeu, a gauche
        // delete contenu;
        delete carteGraphicsView;
        delete carteGraphicsScene;
        delete carteWidget;*/
    }

    float FenetrePrincipale::ScalePourUnite(const QPixmap &image, float largeur, float hauteur) const
    {
        float scale1 = largeur / (float)image.size().width();
        float scale2 = hauteur / (float)image.size().height();
        if(scale2 > scale1)
        {
            scale1 = scale2;
        }

        return scale1;
    }


    void FenetrePrincipale::AfficherCarte() const
    {
        int xZero, yZero;
        int l = carteGraphicsScene->getLargeurUnite(), h = carteGraphicsScene->getHauteurUnite();

        QPen styloNoir;
        styloNoir.setWidth(2);
        styloNoir.setColor(QColor("black"));
        QPen styloBleu;
        styloBleu.setWidth(10);
        styloBleu.setColor(QColor("blue"));

        Carte* carte = JoueurSingleton::getInstance()->getCarte();

        for(int i=0; i<16; i++)
        {
            for(int j=0; j<16; j++)
            {
                xZero = j*l;
                yZero = i*h;


                if(carte->getCase(j, i) == CHEMIN_NORD)
                {
                    QPixmap butPixmap(QString(":/images/chemin_N.jpg"));
                    butPixmap = butPixmap.scaled(l, h);
                    QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                    //tmp->setScale(ScalePourUnite(butPixmap, l, h));
                    tmp->setPos(xZero, yZero);
                    tmp->setData(0, "CHEMIN_NORD");
                }
                else if(carte->getCase(j, i) ==  CHEMIN_SUD)
                {
                    QPixmap butPixmap(QString(":/images/chemin_S.jpg"));
                    butPixmap = butPixmap.scaled(l, h);
                    QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                    tmp->setPos(xZero, yZero);
                    tmp->setData(0, "CHEMIN_SUD");
                }
                else if(carte->getCase(j, i) == CHEMIN_OUEST)
                {
                    QPixmap butPixmap(QString(":/images/chemin_W.jpg"));
                    butPixmap = butPixmap.scaled(l, h);
                    QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                    tmp->setPos(xZero, yZero);
                    tmp->setData(0, "CHEMIN_OUEST");
                }
                else if(carte->getCase(j, i) ==  CHEMIN_EST)
                {
                    QPixmap butPixmap(QString(":/images/chemin_E.jpg"));
                    butPixmap = butPixmap.scaled(l, h);
                    QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                    tmp->setPos(xZero, yZero);
                    tmp->setData(0, "CHEMIN_EST");
                }
                else if(carte->getCase(j, i) == CHEMIN_NO)
                {
                    if(carte->getCase(j, i-1) == CHEMIN_NORD || carte->getCase(j, i-1) == CHEMIN_SUD)
                    {
                        QPixmap butPixmap(QString(":/images/chemin_SE.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_NO");
                    }
                    else
                    {
                        QPixmap butPixmap(QString(":/images/chemin_NW.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_NO");
                    }
                }
                else if(carte->getCase(j, i) == CHEMIN_SE)
                {
                    if(carte->getCase(j, i-1) == CHEMIN_NORD || carte->getCase(j, i-1) == CHEMIN_SUD)
                    {
                        QPixmap butPixmap(QString(":/images/chemin_SE.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_SE");
                    }
                    else
                    {
                        QPixmap butPixmap(QString(":/images/chemin_NW.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_SE");
                    }
                }
                else if(carte->getCase(j, i) == CHEMIN_NE)
                {
                    if(carte->getCase(j, i-1) == CHEMIN_NORD || carte->getCase(j, i-1) == CHEMIN_SUD)
                    {
                        QPixmap butPixmap(QString(":/images/chemin_SW.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_NE");
                    }
                    else
                    {
                        QPixmap butPixmap(QString(":/images/chemin_NE.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_NE");
                    }
                }
                else if(carte->getCase(j, i) == CHEMIN_SO)
                {
                    if(carte->getCase(j, i-1) == CHEMIN_NORD || carte->getCase(j, i-1) == CHEMIN_SUD)
                    {
                        QPixmap butPixmap(QString(":/images/chemin_SW.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_SO");
                    }
                    else
                    {
                        QPixmap butPixmap(QString(":/images/chemin_NE.jpg"));
                        butPixmap = butPixmap.scaled(l, h);
                        QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                        tmp->setPos(xZero, yZero);
                        tmp->setData(0, "CHEMIN_SO");
                    }

                 }
                else if(carte->getCase(j, i) == BUT_ENNEMIS)
                {
                    QPixmap butPixmap(QString(":/images/but.png"));
                    butPixmap = butPixmap.scaled(l, h);
                    QGraphicsPixmapItem* tmp = carteGraphicsScene->addPixmap(butPixmap);
                    tmp->setPos(xZero, yZero);
                    tmp->setData(0, "BUT_ENNEMIS");
                }
                else if(carte->getCase(j, i) == DEPART_NORD || carte->getCase(j, i) == DEPART_SUD || carte->getCase(j, i) == DEPART_OUEST || carte->getCase(j, i) == DEPART_EST)
                {
                    QGraphicsItem* item = carteGraphicsScene->addRect(xZero, yZero, l, h, styloBleu, Qt::blue);
                    item->setData(0, "DEPART");
                }
                else if(carte->getCase(j, i) == BOUE)
                {
                    QGraphicsItem* item = carteGraphicsScene->addRect(xZero, yZero, l, h, QPen(Qt::darkGreen), Qt::darkGreen);
                    item->setData(0, "BOUE");
                }
                else
                {
                    QGraphicsItem* item = carteGraphicsScene->addRect(xZero, yZero, l, h, QPen(Qt::transparent));
                    item->setData(0, "LIBRE");
                }
            }
        }
    }


    void FenetrePrincipale::activerInsertion()
    {
        carteGraphicsScene->setInsertionActive(true);
        labelDescriptionVague->setText("Insertion active.");
        QObject* origine = sender();
        if(origine == boutonCreerPistoleteau)
        {
            carteGraphicsScene->setAjoutDefense(PISTOLET_EAU);
        }
        else if(origine == boutonCreerLancepierre)
        {
            carteGraphicsScene->setAjoutDefense(LANCE_PIERRE);
        }
        else if(origine == boutonCreerPetanque)
        {
            carteGraphicsScene->setAjoutDefense(PETANQUE);
        }
        else if(origine == boutonCreerPaintball)
        {
            carteGraphicsScene->setAjoutDefense(PAINTBALL);
        }
        else if(origine == boutonCreerMusicien)
        {
            carteGraphicsScene->setAjoutDefense(MUSICIEN);
        }
        else
        {
            carteGraphicsScene->setAjoutDefense(NONE);
        }
    }


    void FenetrePrincipale::mauvaisEndroitClique()
    {
        labelDescriptionVague->setText("VOUS NE POUVEZ PAS AJOUTER DE DEFENSE ICI !!!\n"+Constantes::message1);
    }

    void FenetrePrincipale::creditChanged()
    {
        lcdNumberCredits->display(JoueurSingleton::getCredit());

        if(DefenseurFactory::peutAcheter(PETANQUE, 1))
            boutonCreerPetanque->setDisabled(false);
        else
            boutonCreerPetanque->setDisabled(true);

        if(DefenseurFactory::peutAcheter(MUSICIEN, 1))
            boutonCreerMusicien->setDisabled(false);
        else
            boutonCreerMusicien->setDisabled(true);

        if(DefenseurFactory::peutAcheter(PISTOLET_EAU, 1))
            boutonCreerPistoleteau->setDisabled(false);
        else
            boutonCreerPistoleteau->setDisabled(true);

        if(DefenseurFactory::peutAcheter(PAINTBALL, 1))
            boutonCreerPaintball->setDisabled(false);
        else
            boutonCreerPaintball->setDisabled(true);

        if(DefenseurFactory::peutAcheter(LANCE_PIERRE, 1))
            boutonCreerLancepierre->setDisabled(false);
        else
            boutonCreerLancepierre->setDisabled(true);

    }

    void FenetrePrincipale::viesChanged()
    {
        lcdNumberVies->display(JoueurSingleton::getVies());
    }

    void FenetrePrincipale::ajouterEnnemi(Ennemi* ennemi)
    {
        carteGraphicsScene->addItem(ennemi);
    }

    void FenetrePrincipale::supprimerEnnemi(Ennemi* ennemi)
    {
        carteGraphicsScene->removeItem(ennemi);
    }

    void FenetrePrincipale::ajouterDefenseur(Defenseur* defenseur)
    {
        carteGraphicsScene->addItem(defenseur);
        afficherInfosDefenseur(defenseur);
        labelDescriptionVague->setText(Constantes::message1);
    }

    void FenetrePrincipale::supprimerDefenseur(Defenseur* defenseur)
    {
        carteGraphicsScene->removeItem(defenseur);
    }

    void FenetrePrincipale::ajouterProjectile(Projectile* projectile)
    {
        carteGraphicsScene->addItem(projectile);
    }

    void FenetrePrincipale::supprimerProjectile(Projectile* projectile)
    {
        carteGraphicsScene->removeItem(projectile);
        std::cout << "Pointeur de projectile : " << projectile << "\n";
        //delete projectile;
    }

    void FenetrePrincipale::slotPause()
    {
        if(timer->isActive())
        {
            timer->stop();
        }
        else
        {
            timer->start(20);
        }
    }

    void FenetrePrincipale::lancerVague()
    {
        if(!timer->isActive())
        {
            timer->start(20);
        }
        boutonPause->setDisabled(false);

        if(numVague >= 0)
        {
            // On regarde si on a encore des vagues a lancer
            if(vagues.getNombreVagues() < numVague)
            {
                return;
            }

            // On regarde si la vague precedente est terminee avant d'en lancer une nouvelle
            if(vagues.getVague(numVague)->estTerminee())
            {
                numVague++;
            }            
        }

        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerVague()));
        labelDescriptionVague->setText("Vague en cours...");

        std::cout << "On passe ici aussi !" << std::endl;

        boutonLancerVague->setDisabled(true);

    }

    void FenetrePrincipale::timerVague()
    {

        VagueEnnemi* ennemi = vagues.getVague(numVague)->getEnnemi();
        if(ennemi)
        {
            std::cout << "On a un ennemi a creer !!!!\n";
            Position depart = JoueurSingleton::getInstance()->getCarte()->getDepart();
            EnnemiFactory::getEnnemi(ennemi->getTypeEnnemi(), Position(depart.getX() + 0.5, depart.getY() + 0.5), ennemi->getTaille());
        }

    }

    void FenetrePrincipale::vagueTerminee()
    {
        boutonPause->setDisabled(true);
        timer->stop();

        QList<QGraphicsItem*> listeItems = carteGraphicsScene->items();

        for(unsigned int i = 0; i < listeItems.size(); i++)
        {
            if(listeItems[i]->data(0) == "PROJECTILE")
                carteGraphicsScene->removeItem(listeItems[i]);
        }

        if(numVague < vagues.getNombreVagues())
        {
            // Il reste des vagues

            labelDescriptionVague->setText(QString("Prochaine Vague :"));
            boutonLancerVague->setDisabled(false);
        }
        else
        {
            labelDescriptionVague->setText("Il n'y a plus de vague, fin de la partie");
            boutonLancerVague->setDisabled(true);
        }


    }

    void FenetrePrincipale::plusDeVies()
    {
        timer->stop();
        boutonPause->setDisabled(true);
        labelDescriptionVague->setText("Vous avez perdu !!!");
        QMessageBox qmes;
        qmes.setText("Vous n'avez plus de vies, partie terminée !");
        qmes.exec();
    }

    void FenetrePrincipale::afficherInfosDefenseur(Defenseur* defenseur)
    {
        if(defenseur)
        {
            groupBoxInformations->show();
            QString tmp;

            Attaquant* attaquant = dynamic_cast<Attaquant*>(defenseur);

            if(attaquant)
            {
                labelDefenseurCadence_info->setText(tmp.setNum(attaquant->getCadence(), 'f', 2));
                switch(attaquant->getTypeCibles())
                {
                case RAMPANT:
                    labelDefenseurCibles_info->setText("Insectes rampants");
                    break;
                case VOLANT:
                    labelDefenseurCibles_info->setText("Insectes volants");
                    break;
                case TOUS:
                    labelDefenseurCibles_info->setText("Tous les insectes");
                    break;

                }


                labelDefenseurFrappe_info->setText(tmp.setNum(attaquant->getPuissance(), 'f', 2));
                labelDefenseurNiveau_info->setText(tmp.setNum(attaquant->getNiveau(), 'g'));
                labelDefenseurPortee_info->setText(tmp.setNum(attaquant->getPortee(), 'f', 2));
                labelDefenseurType_info->setText(attaquant->getTypeDefenseur());
            }
            else
            {
                Musicien* musicien = dynamic_cast<Musicien*>(defenseur);
                if(musicien)
                {
                    labelDefenseurCadence_info->setText("Ne tire pas");
                    labelDefenseurCibles_info->setText("Aide ses copains");
                    labelDefenseurFrappe_info->setText(tmp.setNum(musicien->getBonus(), 'f', 2));
                    labelDefenseurNiveau_info->setText(tmp.setNum(musicien->getNiveau(), 'g'));
                    labelDefenseurPortee_info->setText(tmp.setNum(musicien->getPortee(), 'f', 2));
                    labelDefenseurType_info->setText(musicien->getTypeDefenseur());
                }
            }

            if(defenseur->peutAmeliorer())
            {
                boutonAmeliorerDefense->setDisabled(false);
            }
            else
            {
                boutonAmeliorerDefense->setDisabled(true);
            }
            boutonSupprimerDefense->setDisabled(false);
        }
        else
        {
            groupBoxInformations->hide();
            boutonSupprimerDefense->setDisabled(true);
            boutonAmeliorerDefense->setDisabled(true);

            labelDefenseurCadence_info->setText("-");
            labelDefenseurCibles_info->setText("-");
            labelDefenseurFrappe_info->setText("-");
            labelDefenseurNiveau_info->setText("-");
            labelDefenseurPortee_info->setText("-");
            labelDefenseurType_info->setText("-");
        }

    }

    void FenetrePrincipale::lancerNouvellePartie()
    {
        // On remet le jeu dans sa configuration initiale
        boutonPause->setDisabled(true);

        if(timer->isActive())
            timer->stop();

        std::vector<Ennemi*> listeEnnemis = EnnemiFactory::getListeEnnemis();
        for(int i = 0; i < listeEnnemis.size(); i++)
        {
            EnnemiFactory::eraseEnnemi(listeEnnemis[i]);
        }

        std::vector<Defenseur*> listeDefenseurs = DefenseurFactory::getListeDefenseurs();
        for(int i = 0; i < listeDefenseurs.size(); i++)
        {
            DefenseurFactory::eraseDefenseur(listeDefenseurs[i]);
        }

        QList<QGraphicsItem*> listeItems = carteGraphicsScene->items();

        for(unsigned int i = 0; i < listeItems.size(); i++)
        {
            carteGraphicsScene->removeItem(listeItems[i]);
        }

        // Lecture de la carte
        //contenu = new Carte(Constantes::DOSSIER_MEDIA+std::string("map.txt"));
        JoueurSingleton::getInstance()->setCarte(Constantes::DOSSIER_MEDIA+std::string("map.txt"));
        AfficherCarte();

        // Initialisation des vagues
        numVague = 0;

        //delete &vagues;
        vagues = Vagues(Constantes::DOSSIER_MEDIA+std::string("waves.txt"));


        boutonLancerVague->setDisabled(false);

        JoueurSingleton::setCredit(200);
        JoueurSingleton::setVies(10);
        groupBoxInformations->hide();



    }

}
