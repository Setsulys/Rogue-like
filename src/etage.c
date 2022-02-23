#include "../includes/labyrinthe_expand.h"
#include "../includes/etage.h"


Floors alloue_etage(Floors etage, Labyrinthe l, int numetage, int colorwall, int colorfloor){
	Floors element;

	element = malloc(sizeof(struct floors));

	if(element != NULL){
		element->numetage = numetage;
		element->colorwall = colorwall;
		element->colorfloor = colorfloor;
		element->terrain = l;
		element->suivant = etage;
	}
	return element;
}

int taille_donjon(Floors etage){
	int taille = 0;
	while(etage != NULL){
		etage = etage->suivant;
		taille++;
	}
	return taille;
}

Floors etage_actuel(Floors etage, int etageact){/*retoune uniquement le labyrinthe actuel*/
	while(etage != NULL && etage->numetage != etageact){
		etage = etage->suivant;
	}
	return etage;
}

Floors ajouteetage(Floors etage, Floors etageact, int numetageact){
	int i = 0;
	Floors current, new;

	if(etage != NULL && etage->numetage !=numetageact){
		new = malloc(sizeof(struct floors));
		new->terrain = etageact->terrain;
		new->numetage = etageact->numetage;
		new->colorfloor = etageact->colorfloor;
		new->colorwall =  etage->colorwall;
		if(numetageact ==  taille_donjon(etage)){
			new->suivant = etage;
			etage = new;
		}
		else{
			current = etage;
			while(i < numetageact - 1){
				current = current->suivant;
				i++;
			}
			new->suivant = current->suivant;
			current->suivant = new;
		}
	}
	return etage;
}

Floors supprimeetage(Floors etage, int etageact){
	Floors tmp = NULL;
	Floors previous = NULL;
	int i = 0;

	if(etage == NULL)
		return NULL;

	previous = etage;
	if(etageact == 0){
		etage = previous->suivant;
		free(previous);
		return etage;
	}

	tmp = previous->suivant;
	while(tmp != NULL){
		if(i == etageact){
			previous->suivant = tmp->suivant;
			free(tmp);
			return etage;
		}
		previous = tmp;
		tmp = tmp->suivant;
		i++;
	}
	return etage;
}

Floors modifetage(Floors etage, Floors etageact, int numetageact){
	numetageact = numetageact - taille_donjon(etage);
	//etage = ajouteetage(etage,etageact, numetageact);
	etage = supprimeetage(etage, numetageact);
	return etage;
}


Floors effacelisteetage(Floors etage){
	Floors tmp = etage;
	Floors tmpnxt;
	while(tmp!=NULL){
		tmpnxt = tmp->suivant;	
		free(tmp);
		tmp =tmpnxt;
	}
	return NULL;
}