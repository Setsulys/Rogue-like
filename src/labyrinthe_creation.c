#include "../includes/labyrinthe_expand.h"
#include "../includes/labyrinthe_creation.h"

#include "../includes/objetslab.h"


void labyrinthe_creation(Labyrinthe * l, int pourcentage, int etage){
	init_labyrinthe(l);
	expand(l);
	tresor_sans_issue(l,etage);
	tresor_escalier(l);
	ajout_mob(l,pourcentage,etage);
	ajout_escalier(l);
}