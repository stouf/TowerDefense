#include "Position.h"


namespace TOWERDEFENSE
{

    Position::Position(float newX, float newY): X(newX), Y(newY)
    {

    }

    float Position::getX()
    {
        return X;
    }

    float Position::getY()
    {
        return Y;
    }

    float Position::getXAffi()
    {
        return (X) * MyQGraphicsScene::getLargeurUnite();
    }

    float Position::getYAffi()
    {
        return (Y) * MyQGraphicsScene::getHauteurUnite();
    }

    float Position::calculDistance(Position P)
    {
        return calculDistance(P.getX(), P.getY());
    }

    float Position::calculDistance(float X2, float Y2)
    {
        return sqrt((X - X2) * (X - X2) + (Y - Y2) * (Y - Y2));
    }

    float Position::calculAngle(float X2, float Y2)
    {
        if(X2 - X > 0)
            return atan((Y2 - Y) / (X2 - X));
        return - PI  + atan((Y2 - Y) / (X2 - X));
    }

    float Position::calculAngle(Position P)
    {
        return calculAngle(P.getX(), P.getY());
    }

    void Position::deplacer(float angle, float distance)
    {

        X = X + distance * cos(angle * 0.01745329);
        Y = Y + distance * sin(angle * 0.01745329);
        return;

    }


    void Position::Afficher(std::ostream& f) const {
            f << "[ X=" << X << " ; Y=" << Y << " ]";
    }

    std::ostream& operator<<(std::ostream& f, const Position& p)
    {
        p.Afficher(f);
        return f;
    }
}



