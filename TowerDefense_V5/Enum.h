#ifndef ENUM_H
#define ENUM_H

namespace TOWERDEFENSE
{
    /** Enum TypeDeplacement
      * Définition des différents types de déplacement possibles.
      * Utilise pour définir le mode de déplacement des ennemis et pour le type de cibles pouvant être touchées par les défenseurs
      */
    enum TypeDeplacement {RAMPANT, VOLANT, TOUS};

    /** Enum TypeEnnemi
      * Définition des différents types d'ennemis existant.
      */
    enum TypeEnnemi {FOURMI, CAFARD, GUEPE, MOUSTIQUE};

    /** Enum TypeDefenseur
      * Définition des différents types de défenseurs existant.
      */
    enum TypeDefenseur {PISTOLET_EAU, LANCE_PIERRE, PETANQUE, PAINTBALL, MUSICIEN, NONE};

    /** Enum ENTITES
      * Définition des différents blocs de terrain existant.
      */
    enum ENTITES
    {
        LIBRE,          // 0
        CHEMIN_NORD,    // 1
        CHEMIN_SUD,     // 2
        CHEMIN_EST,     // 4
        CHEMIN_OUEST,   // 8
        CHEMIN_NE,      // 5
        CHEMIN_SE,      // 6
        CHEMIN_NO,      // 9
        CHEMIN_SO,      // 10
        DEPART_NORD,    // 17
        DEPART_SUD,     // 18
        DEPART_OUEST,   // 24
        DEPART_EST,     // 20
        BUT_ENNEMIS,    // 32
        BOUE            // 64
    };

    /** Enum TypeProjectile
      * Définition des différents projectiles pouvant être tirés.
      */
    enum TypeProjectile {PROJ_PISTOLET_EAU, PROJ_LANCE_PIERRE, PROJ_PETANQUE, PROJ_PAINTBALL};
}

#endif // ENUM_H
