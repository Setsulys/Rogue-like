#ifndef __INVENTAIRE__
#define __INVENTAIRE__

#include "Objets.h"

void init_inventaire(Objets *inventaire[SLOT_INVENTAIRE]);
int verif_slot_libre_inventaire(Objets *inventaire[SLOT_INVENTAIRE]);
int ajoute_objet_inventaire(Objets *inventaire[SLOT_INVENTAIRE], Objets tresor);
int supprime_item_inventaire(Objets *inventaire[SLOT_INVENTAIRE], int emplacement);
int ouvre_tresor(Objets *inventaire[SLOT_INVENTAIRE], int etage);

#endif