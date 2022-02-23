#ifndef __POTION__
#define __POTION__

#include "Personnage.h"
#include "Objets.h"
#include "Inventaire.h"

void utilise_potion_soin(Personnage *p);
void utilise_potion_mana(Personnage *p);
void utilise_potion_regen(Personnage *p);
void utilise_potion_precision(Personnage *p);
void utilise_potion_exp(Personnage *p);
void utilise_potion(Objets * Inventaire[SLOT_INVENTAIRE],Personnage * p, int emplacement);

#endif