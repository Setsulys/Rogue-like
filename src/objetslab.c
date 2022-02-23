#include "../includes/labyrinthe_expand.h"
#include "../includes/objetslab.h"

void tresor_sans_issue(Labyrinthe *l, int etage){
	int i,j;
	for(i = 0; i < NB_LIG; i++){
		for(j = 0; j < NB_COL; j++){
			if(sum_rangewall(i,j,*l)==3){
				if(l->floor[i][j].type == ROOM){
					l->floor[i][j].type = TREASURE;

					if(l->floor[i + 1][j].type == ROOM){
						l->floor[i + 1][j].type = MONSTER;
						l->floor[i + 1][j].entity.hp = (rand() % 11) + 10 * etage;
						l->floor[i + 1][j].entity.atk = ((rand() % 5) + 1) * etage;
						l->floor[i + 1][j].entity.exp = (rand() % 30) + 15 * etage;
					}
					else if(l->floor[i - 1][j].type == ROOM){
						l->floor[i - 1][j].type = MONSTER;
						l->floor[i - 1][j].entity.hp = (rand() % 11) + 10 * etage;
						l->floor[i - 1][j].entity.atk = ((rand() % 5) + 1) * etage;
						l->floor[i - 1][j].entity.exp = (rand() % 30) + 15 * etage;
					}
					else if(l->floor[i][j + 1].type == ROOM){
						l->floor[i][j +1].type = MONSTER;
						l->floor[i][j + 1].entity.hp = (rand() % 11) + 10 * etage;
						l->floor[i][j + 1].entity.atk = ((rand() % 5) + 1) * etage;
						l->floor[i][j + 1].entity.exp = (rand() % 30) + 15 * etage;
					}
					else{
						l->floor[i][j - 1].type = MONSTER;
						l->floor[i][j - 1].entity.hp = (rand() % 11) + 10 * etage;
						l->floor[i][j - 1].entity.atk = ((rand() % 5) + 1) * etage;
						l->floor[i][j - 1].entity.exp = (rand() % 30) + 15 * etage;
					}
				}
			}
		}
	}
}

void tresor_escalier(Labyrinthe *l){
	int random = 0;
	int verif = 0;
	do{
		verif=0;
		random = rand()%4;
		if(random == 0){
			if(l->floor[NB_LIG/2 + 1][NB_COL/2].type == ROOM)
				l->floor[NB_LIG/2 + 1][NB_COL/2].type = TREASURE;
			else
				verif=1;
		}
		if(random == 1){
			if(l->floor[NB_LIG/2 - 1][NB_COL/2].type == ROOM)
				l->floor[NB_LIG/2 - 1][NB_COL/2].type = TREASURE;
			else
				verif=1;
		}
		if(random == 2){
			if(l->floor[NB_LIG/2][NB_COL/2 + 1].type == ROOM)
				l->floor[NB_LIG/2][NB_COL/2 + 1].type = TREASURE;
			else
				verif=1;
		}
		if(random == 3){
			if(l->floor[NB_LIG/2][NB_COL/2 - 1].type == ROOM)
				l->floor[NB_LIG/2][NB_COL/2 - 1].type = TREASURE;
			else
				verif=1;
		}
	}while(verif==1);
}

void ajout_mob(Labyrinthe *l,int pourcentage, int etage){
	int i,j,random;
	for(i = 0; i < NB_LIG; i++){
		for(j = 0; j < NB_COL; j++){
			if(l->floor[i][j].type == ROOM){
				random = rand()%100;
				if(random <= pourcentage ){
					l->floor[i][j].type = MONSTER;
					l->floor[i][j].entity.hp = (rand() % 11) + 10 * etage;
					l->floor[i][j].entity.atk = ((rand() % 5) + 1) * etage;
					l->floor[i][j].entity.exp = (rand() % 30) + 15 * etage;
				}
			}
		}
	}
}


/*Distance de manhattan*/
	/*Fonction de valeur absolue*/
	int abs(int a){
		if(a < 0){
			return -a;
		}
		return a;
	}

	/*Fonction calculant la distance de manhattan*/
	int distance_de_Manhattan(int i1,int i2, int j1, int j2){
		return abs(i1 - i2) + abs(j1 - j2);
	}

Toexpand effaceliste(Toexpand liste){
	Toexpand tmp = liste;
	Toexpand tmpnxt;
	while(tmp!=NULL){
		tmpnxt = tmp->suivant;	
		free(tmp);
		tmp =tmpnxt;
	}
	return NULL;
}

void ajout_escalier(Labyrinthe *l){
	int i,j;
	Toexpand liste = NULL;
	Toexpand tmp = NULL;
	for(i = 0; i < NB_LIG; i++){
		for(j = 0; j < NB_COL; j++){
			if(l->floor[i][j].type == ROOM && distance_de_Manhattan(i,NB_LIG/2,j,NB_COL/2) >=25)
				liste = alloue_cellule(liste,i,j);
		}
	}
	tmp = recuperation(liste, rand()%taille_liste(liste));
	l->floor[tmp->x][tmp->y].type = STAIR_DOWN;
	liste=effaceliste(liste);
	free(liste);	
}


