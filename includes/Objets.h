#ifndef __OBJETS__
#define __OBJETS__

#define SLOT_INVENTAIRE 12

typedef struct {
    int atk;
    int qualite;
} Epees;

typedef struct {
    int intel;
    int qualite;
} Grimoires;

typedef struct {
    int def;
    int qualite;
} Armures;

typedef struct {
    Epees epee;
    Grimoires grimoire;
    Armures armure;
} Equipements;

typedef enum {
    EPEE,  /* 0 */
    ARMURE,
    GRIMOIRE,
    POTION_SOIN,
    POTION_MANA,
    POTION_REGEN,
    POTION_PRECISION,
    POTION_EXP, 
    VIDE/* 8 */
} Type_objet;

typedef struct objet {
    Type_objet type_objet;
    Equipements equipable;
} Objets;

#endif