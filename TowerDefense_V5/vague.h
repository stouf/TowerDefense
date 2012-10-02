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
        int timerEnnemi;                    ///< Nombre de tick du timer avant la création d'un nouvel ennemi
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
          * Méthode permettant de définir la description de la vague.
          */
        void setDescription(const std::string& desc);




        // Methodes
        /**
          * Méthode utilisée au chargement du jeu, permettant d'ajouter un ennemi à une vague.
          * \param ennemi : Pointeur sur le VagueEnnemi à ajouter.
          */
        void ajoutEnnemi(VagueEnnemi* ennemi);

        /**
          * Méthode gérant la création des ennemis (gestion de informations sur l'ennemi à créer, gestion du timer).
          */
        VagueEnnemi* getEnnemi();

        /**
          * Indique l'état de la vague.
          * \return True si il n'y a plus d'ennemi à envoyer, False sinon.
          */
        bool estTerminee();

    signals:
        /**
          * Signal émit lorsqu'il n'y a plus d'ennemi à envoyer.
          */
        void signalVagueTerminee();



    };
}

#endif // VAGUE_H
