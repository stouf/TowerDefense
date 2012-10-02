#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QIODevice>

#include "constantes.h"
#include "Position.h"
#include "Enum.h"

namespace TOWERDEFENSE
{
    class Carte
    {
    private:
        // Attributs
        ENTITES** carte;
        Position depart;

    public:
        // Constructeurs

        /*!
          * Constructeur par defaut
          * Il creera une carte vide, puisqu'au fichier ne lui est passe en parametre
          */
        Carte();

        /*!
          * Constructeur principal
          * Il creera une carte selon les descriptions faite dans le fichier qui lui est passe en parametre
          * Le fichier doit etre de type texte et doit respecter les normes posees par l'enonce
          * \param fichier Chemin du fichier duquel s'inspire le constructeur pour creer la carte
          */
        Carte(const std::string& fichier);


        // Destructeur
        /*!
          * Destructeur de la classe
          */
        ~Carte();


        // Methodes

        /*!
          * Methode d'affichage
          * Cette methode affiche le tableau a deux dimensions representant la carte
          * \param flux Il s'agit du flux vers lequel on va afficher le tableau
          */
        void Afficher(std::ostream& flux) const;


        // Accesseurs

        /*!
           * Retourne le tableau d'ENTITES (enumeration) representant la carte
           * \return carteNommee Tableau d'ENTITES (enumeration) representant la carte
          */
        ENTITES** getCarte() const;

        ENTITES getCase(int X, int Y) const;

        float getAngle(int X, int Y) const;

        std::string afficherCase(int X, int Y) const;

        Position getDepart();
    };
}

#endif // CARTE_H
