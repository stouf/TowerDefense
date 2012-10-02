#include <QApplication>

#include "fenetre_principale.h"
#include "Ennemi.h"
#include "Defenseur.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    TOWERDEFENSE::FenetrePrincipale fenetre;
    fenetre.show();

    return app.exec();
}
