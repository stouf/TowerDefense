#ifndef VAGUES_H
#define VAGUES_H

#include <string>
#include <QFile>
#include <QString>
#include <QStringList>

#include <vector>

#include <iostream>

#include "vague.h"

namespace TOWERDEFENSE
{
    class Vagues
    {

    private:

        // Attributs
        std::vector<Vague*> mesVagues;




    public:

        // Constructeur

        Vagues();

        /**
          * Construction avec parsing de fichier passe en argument
          * \param fichier Le fichier a parser pour la construction de l'objet
          */
        Vagues(const std::string& fichier);



        // Methodes

        /**
          * Cette methode retourne la i-eme vague de l'objet
          * Si i est plus grand que le nombre de vagues contenus, alors la methode renverra la premiere vague stockee
          * \param i Le rang auquel on souhaite acceder
          * \return Vague& Une reference sur la i-eme vague
          */
        Vague* getVague(unsigned int i) const;


        /**
          * Cette methode retourne le nombre de vagues stockees dans l'objet
          * \return int Le nombre de vagues stockees dans l'objet
          */
        int getNombreVagues() const;


    };
}

#endif // VAGUES_H
