#ifndef VAGUEENNEMI_H
#define VAGUEENNEMI_H

#include "Enum.h"
#include <iostream>

namespace TOWERDEFENSE
{
    class VagueEnnemi
    {

    private:
        TypeEnnemi typeEnnemi;      ///< Type de l'ennemi composant la vague
        float taille;               ///< Taille de l'ennemi
        int intervalle;             ///< Nombre de tick du timer avant la création de cet ennemi

    public:
        VagueEnnemi(TypeEnnemi typeEnnemi, float taille, int intervalle);
        float getTaille();
        int getIntervalle();
        TypeEnnemi getTypeEnnemi();
        void afficher(std::ostream& f=std::cout) const;
    };
}


#endif // VAGUEENNEMI_H
