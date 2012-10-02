#include "carte.h"

namespace TOWERDEFENSE
{
    Carte::Carte()
    {
        carte = new ENTITES*[16];
        for(int i=0; i<16; i++)
        {
            carte[i] = new ENTITES[16];
        }

        for(int i=0; i<16; i++)
        {
            for(int j=0; j<16; j++)
            {
                carte[i][j] = LIBRE;
            }
        }

        depart = Position(0, 0);

    }


    Carte::Carte(const std::string& fichier)
    {
        // Initialisation du tableau
        carte = new ENTITES*[16];
        for(int i=0; i<16; i++)
        {
            carte[i] = new ENTITES[16];
        }



        // Ouverture du fichier
        std::string cheminAbsolu = Constantes::DOSSIER_MEDIA+fichier;
        QFile fichierDesc(QString(cheminAbsolu.c_str()));
        if(fichierDesc.open(QIODevice::ReadOnly))
        {
            // Le fichier a su etre ouvert
            QTextStream fluxFichier(&fichierDesc);
            QString tampon;
            QStringList listeTmp;

            // Lecture du fichier
            tampon = fluxFichier.readAll();
            listeTmp = tampon.split(" ", QString::SkipEmptyParts);

            int k = 0;
            for(int i=0; i<16; i++)
            {
                for(int j=0; j<16; j++)
                {

                    switch(listeTmp.at(k).toInt())
                    {
                    case 0:
                        carte[i][j] = LIBRE;
                        break;
                    case 1:
                        carte[i][j] = CHEMIN_NORD;
                        break;
                    case 2:
                        carte[i][j] = CHEMIN_SUD;
                        break;
                    case 4:
                        carte[i][j] = CHEMIN_EST;
                        break;
                    case 8:
                        carte[i][j] = CHEMIN_OUEST;
                        break;
                    case 5:
                        carte[i][j] = CHEMIN_NE;
                        break;
                    case 6:
                        carte[i][j] = CHEMIN_SE;
                        break;
                    case 9:
                        carte[i][j] = CHEMIN_NO;
                        break;
                    case 10:
                        carte[i][j] = CHEMIN_SO;
                        break;
                    case 17:
                        carte[i][j] = DEPART_NORD;
                        depart = Position(j, i);
                        break;
                    case 18:
                        carte[i][j] = DEPART_SUD;
                        depart = Position(j, i);
                        break;
                    case 20:
                        carte[i][j] = DEPART_EST;
                        depart = Position(j, i);
                        break;
                    case 24:
                        carte[i][j] = DEPART_OUEST;
                        depart = Position(j, i);
                        break;
                    case 32:
                        carte[i][j] = BUT_ENNEMIS;
                        break;
                    case 64:
                        carte[i][j] = BOUE;
                        break;
                    default:
                        carte[i][j] = LIBRE;
                        break;
                    }


                    k++;
                }
                std::cout << "\n";
            }
            fichierDesc.close();
        }
        else
        {
            // Le fichier n'a su etre ouvert correctement
            for(int i=0; i<16; i++)
            {
                for(int j=0; j<16; j++)
                {
                    carte[i][j] = LIBRE;
                }
            }
        }
    }


    Carte::~Carte()
    {
        for(int i=0;i<16; i++)
        {
            delete[] carte[i];
        }
        delete[] carte;
    }


    void Carte::Afficher(std::ostream& flux) const
    {
        for(int i=0; i<16; i++)
        {
            for(int j=0; j<16; j++)
            {
               switch(carte[i][j])
               {
               case LIBRE:
                    flux << "Libre\t";
                    break;
               case CHEMIN_NORD:
                   flux << "Nord\t";
                   break;
               case CHEMIN_SUD:
                   flux << "Sud\t";
                   break;
               case CHEMIN_OUEST:
                   flux << "Ouest\t";
                   break;
               case CHEMIN_EST:
                   flux << "Est\t";
                   break;
               case CHEMIN_NO:
                   flux << "Nord-Ouest\t";
                   break;
               case CHEMIN_NE:
                   flux << "Nord-Est\t";
                   break;
               case CHEMIN_SO:
                   flux << "Sud-Ouest\t";
                   break;
               case CHEMIN_SE:
                   flux << "Sud-Est\t";
                   break;
               case DEPART_NORD:
                   flux << "Depart nord\t";
                   break;
               case DEPART_SUD:
                   flux << "Depart sud\t";
                   break;
               case DEPART_OUEST:
                   flux << "Depart ouest\t";
                   break;
               case DEPART_EST:
                   flux << "Depart est\t";
                   break;
               case BUT_ENNEMIS:
                   flux << "But\t";
                   break;
               case BOUE:
                   flux << "Sud-Est\t";
                   break;
               default:
                   break;
               }
            }
            flux << "\n";
        }
    }

    ENTITES** Carte::getCarte() const
    {
        return carte;
    }

    ENTITES Carte::getCase(int X, int Y) const
    {
        if(X >= 0 && X < 16 && Y >= 0 && Y < 16)
            return carte[Y][X];
        return LIBRE;
    }

    std::string Carte::afficherCase(int X, int Y) const
    {
       switch(getCase(X, Y))
       {
       case LIBRE:
            return "Libre";
            break;
       case CHEMIN_NORD:
           return "Nord";
           break;
       case CHEMIN_SUD:
           return "Sud";
           break;
       case CHEMIN_OUEST:
           return "Ouest";
           break;
       case CHEMIN_EST:
           return "Est";
           break;
       case CHEMIN_NO:
           return "Nord-Ouest";
           break;
       case CHEMIN_NE:
           return "Nord-Est";
           break;
       case CHEMIN_SO:
           return "Sud-Ouest";
           break;
       case CHEMIN_SE:
           return "Sud-Est";
           break;
       case DEPART_NORD:
           return "Depart nord";
           break;
       case DEPART_SUD:
           return "Depart sud";
           break;
       case DEPART_OUEST:
           return "Depart ouest";
           break;
       case DEPART_EST:
           return "Depart est";
           break;
       case BUT_ENNEMIS:
           return "But";
           break;
       case BOUE:
           return "Sud-Est";
           break;
       default:
           return "Erreur de case";
           break;
       }

    }

    float Carte::getAngle(int X, int Y) const
    {
        ENTITES tmp = getCase(X, Y);

        switch(tmp)
        {
        case LIBRE:
        case DEPART_NORD:
        case BUT_ENNEMIS:
        case BOUE:
            return 90;
            break;
        case CHEMIN_NORD:
            return 270;
            break;
        case CHEMIN_SUD:
            return 90;
            break;
        case CHEMIN_EST:
            return 0;
            break;
        case CHEMIN_OUEST:
            return 180;
            break;
        case CHEMIN_NE:
            return 315;
            break;
        case CHEMIN_SE:
            return 45;
            break;
        case CHEMIN_NO:
            return 225;
            break;
        case CHEMIN_SO:
            return 135;
            break;
        default:
            return 90;
            break;

        }
    }

    Position Carte::getDepart()
    {
        return depart;
    }
}
