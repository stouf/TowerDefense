#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <QString>

namespace TOWERDEFENSE
{
    class Constantes
    {
    public:
        Constantes();

        /*!
          * Il s'agit du dossier contenant tous les medias requis pour le programme
          */
        static const char* DOSSIER_MEDIA;

        /*!
          * Il s'agit de la largeur totale de la fenetre
          */
        static const int largeurFenetre;

        /*!
          * Il s'agit de la hauteur totale de la fenetre
          */
        static const int hauteurFenetre;

        /*!
          * Il s'agit de la largeur totale de la scene graphique
          */
        static const int largeurGraphicsScene;

        /*!
          * Il s'agit de la hauteur totale de la scene graphique
          */
        static const int hauteurGraphicsScene;

        static const QString& message1;
    };
}

#endif // CONSTANTES_H
