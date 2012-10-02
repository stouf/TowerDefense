#include "VagueEnnemi.h"

namespace TOWERDEFENSE
{
    VagueEnnemi::VagueEnnemi(TypeEnnemi n_typeEnnemi, float n_taille, int n_intervalle):typeEnnemi(n_typeEnnemi), taille(n_taille), intervalle(n_intervalle)
    {

    }

    float VagueEnnemi::getTaille()
    {
        return taille;
    }

    int VagueEnnemi::getIntervalle()
    {
        return intervalle;
    }

    TypeEnnemi VagueEnnemi::getTypeEnnemi()
    {
        return typeEnnemi;
    }

    void VagueEnnemi::afficher(std::ostream& f) const
    {
        f << "Ennmi a charger : " << typeEnnemi << " - Taille = " << taille << " - Intervalle = " << intervalle << std::endl;
    }

}

