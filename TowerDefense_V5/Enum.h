#ifndef ENUM_H
#define ENUM_H

namespace TOWERDEFENSE
{
    /** Enum TypeDeplacement
      * D�finition des diff�rents types de d�placement possibles.
      * Utilise pour d�finir le mode de d�placement des ennemis et pour le type de cibles pouvant �tre touch�es par les d�fenseurs
      */
    enum TypeDeplacement {RAMPANT, VOLANT, TOUS};

    /** Enum TypeEnnemi
      * D�finition des diff�rents types d'ennemis existant.
      */
    enum TypeEnnemi {FOURMI, CAFARD, GUEPE, MOUSTIQUE};

    /** Enum TypeDefenseur
      * D�finition des diff�rents types de d�fenseurs existant.
      */
    enum TypeDefenseur {PISTOLET_EAU, LANCE_PIERRE, PETANQUE, PAINTBALL, MUSICIEN, NONE};

    /** Enum ENTITES
      * D�finition des diff�rents blocs de terrain existant.
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
      * D�finition des diff�rents projectiles pouvant �tre tir�s.
      */
    enum TypeProjectile {PROJ_PISTOLET_EAU, PROJ_LANCE_PIERRE, PROJ_PETANQUE, PROJ_PAINTBALL};
}

#endif // ENUM_H
