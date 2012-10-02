#ifndef VAGUE_H
#define VAGUE_H

#include <QObject>

#include <string>
#include <vector>

#include "Enum.h"
#include "VagueEnnemi.h"
#include "Ennemi.h"

namespace TOWERDEFENSE
{

    class Vague : public QObject
    {
    Q_OBJECT
    private:

        // Attributs
        std::string description;                ///< Description de la vague.
        std::vector<VagueEnnemi*> listeEnnemis;     ///< Liste des ennemis composant la vague
        unsigned int ennemiCourant;         ///< Indice de l'ennemi courant
        int timerEnnemi;                    ///< Nombre de tick du timer avant la cr�ation d'un nouvel ennemi
        bool vagueTerminee;                 ///< Etat de la vague



    public:

        // Constructeurs

        Vague();
        Vague(std::string description);
        ~Vague();



        // Accesseurs

        /**
          * Cette methode retourne la description de la vague
          * \return std::string La description de la vague
          */
        const std::string& getDescription() const;



        /**
          * M�thode permettant de d�finir la description de la vague.
          */
        void setDescription(const std::string& desc);




        // Methodes
        /**
          * M�thode utilis�e au chargement du jeu, permettant d'ajouter un ennemi � une vague.
          * \param ennemi : Pointeur sur le VagueEnnemi � ajouter.
          */
        void ajoutEnnemi(VagueEnnemi* ennemi);

        /**
          * M�thode g�rant la cr�ation des ennemis (gestion de informations sur l'ennemi � cr�er, gestion du timer).
          */
        VagueEnnemi* getEnnemi();

        /**
          * Indique l'�tat de la vague.
          * \return True si il n'y a plus d'ennemi � envoyer, False sinon.
          */
        bool estTerminee();

    signals:
        /**
          * Signal �mit lorsqu'il n'y a plus d'ennemi � envoyer.
          */
        void signalVagueTerminee();



    };
}

#endif // VAGUE_H
