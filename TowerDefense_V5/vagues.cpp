#include "vagues.h"

namespace TOWERDEFENSE
{
    Vagues::Vagues()
    {
    }


    Vagues::Vagues(const std::string& fichier)
    {
        QFile descripteurFichier(fichier.c_str());
        if(descripteurFichier.open(QIODevice::ReadOnly))
        {
            // Le fichier a ete ouvert correctement
            QString contenu = descripteurFichier.readAll();
            QStringList liste1 = contenu.split("\n");
            QStringList liste2;
            QStringList liste3;
            Vague* vague = 0;

            for(int i=0; i<liste1.size(); i++)
            {
                // Pour chaque ligne...
                // i = une vague

                liste2 = liste1.at(i).split(";");

                vague = new Vague(liste2.at(0).toStdString());

                for(int j=1; j<liste2.size(); j++)
                {
                    // Pour chaque champs de chaque ligne...
                    // j = un champ de vague


                    liste3 = liste2.at(j).split(":");

                    TypeEnnemi typeEnnemi;

                    if(liste3.at(0).toStdString() == "fourmi")
                    {
                        typeEnnemi = FOURMI;
                    }
                    else if(liste3.at(0).toStdString() == "cafard")
                    {
                        typeEnnemi = CAFARD;
                    }
                    else if(liste3.at(0).toStdString() == "guepe")
                    {
                        typeEnnemi = GUEPE;
                    }
                    else if(liste3.at(0).toStdString() == "moustique")
                    {
                        typeEnnemi = MOUSTIQUE;
                    }

                    float taille = liste3.at(1).toFloat();

                    int quantite = liste3.at(2).toInt();
                    int intervalle = liste3.at(3).toInt();

                    for(int k = 0; k < quantite; k++)
                    {
                        VagueEnnemi* ennemi = new VagueEnnemi(typeEnnemi, taille, intervalle);
                        vague->ajoutEnnemi(ennemi);
                    }

                }
                mesVagues.push_back(vague);
            }
        }
        else
        {
            std::cout << "Une erreur est survenue lors de l'ouverture du fichier" << std::endl;
            std::cout << "Le constructeur par defaut sera appele" << std::endl;
        }
    }

    Vague* Vagues::getVague(unsigned int i) const
    {
        if(mesVagues.size() <= i)
        {
            return mesVagues[0];
        }
        else
        {
            return mesVagues[i];
        }
    }

    int Vagues::getNombreVagues() const
    {
        return mesVagues.size();
    }
}
