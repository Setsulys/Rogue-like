#include "../includes/labyrinthe_expand.h"
#include "../includes/etage.h"
#include "../includes/devtools.h"

void affichepile(Toexpand liste){				
	Toexpand tmp = liste;
	while(tmp != NULL){
		printf("%d, %d\n",tmp->x, tmp->y);	
		tmp = tmp->suivant;
	}
	printf("\n");
}
	
void affiche_labyrinthe(Labyrinthe L) {
	int i,j;
	printf("-------------------\n ");
	for(i = 0; i < NB_LIG; i++){
		printf("\n ");
		for(j = 0; j < NB_COL; j++){
			if(L.floor[i][j].type == WALL)
				printf("   ");
			else if(L.floor[i][j].type == STAIR_UP)
				printf("{_}");
			else if(L.floor[i][j].type == ROOM)
				printf("[ ]");
			else if(L.floor[i][j].type == MONSTER)
				printf("[M]");
			else if(L.floor[i][j].type == TREASURE)
				printf("[T]" );
			else if(L.floor[i][j].type == STAIR_DOWN)
				printf("{0}");
		}
	}
}

void affiche_etage(Floors etage){
	while(etage != NULL){
		printf("\netage -> %d\n couleurs:\n sol->%d mur->%d\n",etage->numetage, etage->colorfloor, etage->colorwall);
		//affiche_labyrinthe(etage->terrain);
		etage = etage->suivant;
	}
}