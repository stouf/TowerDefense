#include "vague.h"

namespace TOWERDEFENSE
{
    Vague::Vague():ennemiCourant(0), vagueTerminee(false)
    {

    }

    Vague::Vague(std::string n_description):description(n_description), ennemiCourant(0), vagueTerminee(false)
    {

    }

    Vague::~Vague()
    {

    }

    const std::string& Vague::getDescription() const
    {
        return description;
    }

    void Vague::setDescription(const std::string& desc)
    {
        description = desc;
    }

    void Vague::ajoutEnnemi(VagueEnnemi* ennemi)
    {
        listeEnnemis.push_back(ennemi);
    }

    VagueEnnemi* Vague::getEnnemi()
    {
        if(vagueTerminee)
        {
            if(EnnemiFactory::getNombreEnnemisCourant() == 0)
            {
                JoueurSingleton::vagueTerminee();
            }
            return 0;
        }

        if(timerEnnemi >= listeEnnemis[ennemiCourant]->getIntervalle())
        {
            VagueEnnemi* tmp = listeEnnemis[ennemiCourant];
            ennemiCourant++;
            if(ennemiCourant >= listeEnnemis.size())
            {
                vagueTerminee = true;
            }
            timerEnnemi = 1;
            return tmp;
        }
        timerEnnemi++;
        return 0;
    }

    bool Vague::estTerminee()
    {
        return vagueTerminee;
    }
}
