#include "my_q_graphics_scene.h"


namespace TOWERDEFENSE
{

    int MyQGraphicsScene::largeurUnite;
    int MyQGraphicsScene::hauteurUnite;

    MyQGraphicsScene::MyQGraphicsScene(QObject *parent) :
        QGraphicsScene(parent), insertionActive(false)
    {
        largeurUnite = Constantes::largeurGraphicsScene/16;
        hauteurUnite = Constantes::hauteurGraphicsScene/16;

        ajoutDefense = NONE;
        infosDefense = 0;
    }


    void MyQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        int x = event->scenePos().x();
        int y = event->scenePos().y();

        if(insertionActive)
        {
            if(itemAt(x, y)->data(0) == "LIBRE")
            {
                // Calcul de la position afin que l'element soit affiche "correctement" dans un "carre" de jeu
                int xPos = (x/largeurUnite);
                int yPos = (y/hauteurUnite);

                Defenseur* tmp = DefenseurFactory::getDefenseur(ajoutDefense, Position(xPos + 0.5, yPos + 0.5));
                infosDefense = tmp;
                //emit ajouterElement(xPos, yPos, ajoutDefense);

                ajoutDefense = NONE;
            }
            else
            {
                emit mauvaisEndroitClique();
            }

            insertionActive = false;
        }
        else
        {
            std::cout << "Clic en " << Position(x, y) << "\n";
            if(itemAt(x, y)->data(0) ==  "DEFENSE")
            {
                std::cout << "On selectionne le defenseur pour information !\n";
                infosDefense = dynamic_cast<Defenseur*> (itemAt(x, y));

                emit signalAfficherInfosDefenseur(infosDefense);

                //DefenseurFactory::eraseDefenseur(pt);
                //removeItem(itemAt(x, y));
            }
            else
            {
                infosDefense = 0;
                emit signalAfficherInfosDefenseur(infosDefense);
            }
        }
    }

    void MyQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
    }


    void MyQGraphicsScene::setInsertionActive(bool valeur)
    {
        insertionActive = valeur;
    }

    void MyQGraphicsScene::setAjoutDefense(TypeDefenseur valeur)
    {
        ajoutDefense = valeur;
    }

    int MyQGraphicsScene::getHauteurUnite()
    {
        return hauteurUnite;
    }

    int MyQGraphicsScene::getLargeurUnite()
    {
        return largeurUnite;
    }

    void MyQGraphicsScene::ameliorerDefenseur()
    {
        infosDefense->ameliorer();
        emit signalAfficherInfosDefenseur(infosDefense);
    }

    void MyQGraphicsScene::supprimerDefenseur()
    {
        if(infosDefense)
        {
            DefenseurFactory::eraseDefenseur(infosDefense);
            infosDefense = 0;
            emit signalAfficherInfosDefenseur(0);
        }
    }

    void MyQGraphicsScene::creditChanged()
    {
        emit signalAfficherInfosDefenseur(infosDefense);
    }

}
