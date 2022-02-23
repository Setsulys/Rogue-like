#ifndef __ETAGE__
#define __ETAGE__


#include <stdio.h>
#include <stdlib.h>


typedef struct floors{
	int numetage;
	int colorfloor;
	int colorwall;
	Labyrinthe terrain;
	struct floors * suivant;
} * Floors;


Floors alloue_etage(Floors etage, Labyrinthe l, int numetage, int colorwall, int colorfloor);

int taille_donjon(Floors etage);

Floors etage_actuel(Floors etage, int etageact);

Floors ajouteetage(Floors etage, Floors etageact, int numetageact);

Floors supprimeetage(Floors etage, int etageact);

Floors modifetage(Floors etage, Floors etageact, int numetageact);

Floors effacelisteetage(Floors etage);

#endif