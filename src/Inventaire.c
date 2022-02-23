#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/Inventaire.h"

void init_inventaire(Objets *inventaire[SLOT_INVENTAIRE]) {
    int i;

    for (i = 0; i < SLOT_INVENTAIRE; i++) {
        inventaire[i] = malloc(sizeof(struct objet));

        if (inventaire[i] == NULL)
            exit(EXIT_FAILURE);

        inventaire[i]->type_objet = VIDE;
    }
}

int verif_slot_libre_inventaire(Objets *inventaire[SLOT_INVENTAIRE]) {
    int i;

    for (i = 0; i < SLOT_INVENTAIRE; i++) {
        if (inventaire[i]->type_objet == VIDE) {
            return i;
        }
    }

    return -1;
}

int ajoute_objet_inventaire(Objets *inventaire[SLOT_INVENTAIRE], Objets tresor) {
    int emplacement;

    if (tresor.type_objet != VIDE && tresor.type_objet != EPEE && tresor.type_objet != ARMURE && tresor.type_objet != GRIMOIRE) {
        if ((emplacement = verif_slot_libre_inventaire(inventaire)) != -1) {
            *inventaire[emplacement] = tresor;
            return tresor.type_objet;
        }
    }

    else {
        for (emplacement = 0; emplacement < SLOT_INVENTAIRE; emplacement++) {
            if (tresor.type_objet == EPEE && inventaire[emplacement]->type_objet == EPEE) {
                if (tresor.equipable.epee.qualite > inventaire[emplacement]->equipable.epee.qualite) {
                    *inventaire[emplacement] = tresor;

                    return tresor.type_objet;
                }

                return -1;
            }

            else if (tresor.type_objet == ARMURE && inventaire[emplacement]->type_objet == ARMURE) {
                if (tresor.equipable.armure.qualite > inventaire[emplacement]->equipable.armure.qualite) {
                    *inventaire[emplacement] = tresor;

                    return tresor.type_objet;
                }

                return -1;
            }

            else if (tresor.type_objet == GRIMOIRE && inventaire[emplacement]->type_objet == GRIMOIRE) {
                if (tresor.equipable.grimoire.qualite > inventaire[emplacement]->equipable.grimoire.qualite) {

                    *inventaire[emplacement] = tresor;

                    return tresor.type_objet;
                }

                return -1;
            }
        }

        if (tresor.type_objet != VIDE) {
            if ((emplacement = verif_slot_libre_inventaire(inventaire)) != -1) {
                *inventaire[emplacement] = tresor;

                return tresor.type_objet;
            }
        }
        if(tresor.type_objet == VIDE){
            return tresor.type_objet;
        }
    }

    return -1;
}

int supprime_item_inventaire(Objets *inventaire[SLOT_INVENTAIRE], int emplacement) {
    int tmp;

    tmp = inventaire[emplacement]->type_objet;
        inventaire[emplacement]->type_objet = VIDE;

    return tmp;
}

int ouvre_tresor(Objets *inventaire[SLOT_INVENTAIRE], int etage) {
    Objets tresor;

    tresor.type_objet = rand() % 9;

    if (tresor.type_objet == EPEE) {
        tresor.equipable.epee.atk = ((rand() % 3) + 1) * etage;
        tresor.equipable.epee.qualite = etage;
    }

    else if (tresor.type_objet == ARMURE) {
        tresor.equipable.armure.def = ((rand() % 3) + 1) * etage;
        tresor.equipable.armure.qualite = etage;
    }

    else if (tresor.type_objet == GRIMOIRE) {
        tresor.equipable.grimoire.intel = ((rand() % 3) + 1) * etage;
        tresor.equipable.grimoire.qualite = etage;
    }
    return ajoute_objet_inventaire(inventaire, tresor);
}
