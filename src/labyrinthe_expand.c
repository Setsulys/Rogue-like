#include "../includes/labyrinthe_expand.h"

void init_labyrinthe(Labyrinthe * l){
	int i,j;
	for(i = 0; i < NB_LIG; i++){
		for(j = 0; j < NB_COL; j++)
			l->floor[i][j].type = WALL;
	}
	l->floor[NB_LIG/2][NB_COL/2].type = STAIR_UP;
}

Toexpand alloue_cellule(Toexpand liste, int x, int y){
	Toexpand element;
	element = malloc(sizeof(struct cellule));
	if(element != NULL){
		element->x = x;
		element->y = y;
		element->suivant = liste;
	}
	return element;
}

Toexpand recuperation(Toexpand liste, int indice){
	int i;
	for (i = 0; i < indice && liste != NULL; i++){
		if(liste->suivant == NULL)
			return NULL;
		liste = liste->suivant;
	}
	return liste;
}

Toexpand suppression(Toexpand liste, int indice){
	Toexpand tmp = NULL;
	Toexpand previous = NULL;
	int i = 0;

	if(liste == NULL)
		return NULL;
	previous = liste;
	if(indice == 0){
		liste = previous->suivant;
		free(previous);
		return liste;
	}
	tmp = previous/*->suivant*/;
	while(tmp!= NULL){
		if(i == indice){
			previous->suivant = tmp->suivant;
			free(tmp);
			return liste;
		}
		previous = tmp;
		tmp = tmp->suivant;
		i++;
	}
	return liste;
}

int taille_liste(Toexpand liste){
	int taille = 0;
	while(liste != NULL){
		liste = liste->suivant;
		taille++;
	}
	return taille;
}

/*Fonction verifiant qu'il y a une salle au plus au tour de la case*/ /*PROBLEMME*/
int sum_range1(int x, int y,Labyrinthe l){	
	int somme = 0;
	if(l.floor[x - 1][y].type == ROOM)
		somme++;
	if(l.floor[x + 1][y].type == ROOM)
		somme++;
	if(l.floor[x][y - 1].type == ROOM)
		somme++;
	if(l.floor[x][y + 1].type == ROOM)
		somme++;
	return somme;
}

/*Fonction verifiant qu'il y a deux salles au plus au tour de la case a distance 2*//*PROBLEME*/
int sum_range2(int x,int y,Labyrinthe l){
	int somme = 0;
	if(l.floor[x - 2][y].type == ROOM)
		somme++;
	if(l.floor[x + 2][y].type == ROOM)
		somme++;
	if(l.floor[x][y - 2].type == ROOM)
		somme++;
	if(l.floor[x][y + 2].type == ROOM)
		somme++;
	if(l.floor[x - 1][y - 1].type == ROOM)
		somme++;
	if(l.floor[x + 1][y - 1].type == ROOM)
		somme++;
	if(l.floor[x - 1][y + 1].type == ROOM)
		somme++;
	if(l.floor[x + 1][y + 1].type == ROOM)
		somme++;
	return somme;
}

/*Fonction verifiant que la case est admissible*/
int admissible(int x,int y,Labyrinthe l){
	if((sum_range2(x,y,l)<= 2) && (sum_range1(x,y,l) == 1)){
		return 1;
		
	}
	return 0;
}


/*verifie si une case est deja dans la liste*/
int verif_presence(int x, int y,Toexpand liste){
	while(liste != NULL){
		if(liste->x == x && liste->y == y)
			return 1;
		liste = liste->suivant;
	}
	return 0;
}

Toexpand adjacent_expand(int x, int y, Labyrinthe l, Toexpand liste){
	if(!verif_presence(x - 1, y, liste) && admissible(x - 1,y,l)){
		if(l.floor[x - 1][y].type == WALL && x - 1 > 0)
			liste = alloue_cellule(liste, x - 1, y);
	}
	if(!verif_presence(x + 1, y, liste) && admissible(x + 1,y,l)){
		if(l.floor[x + 1][y].type == WALL && x + 1 < NB_LIG - 1)
			liste = alloue_cellule(liste,x + 1, y);
	}
	if(!verif_presence(x, y - 1, liste) && admissible(x,y - 1,l)){
		if(l.floor[x][y - 1].type == WALL && y - 1 > 0)
			liste = alloue_cellule(liste, x, y - 1);
	}if(!verif_presence(x, y + 1, liste) && admissible(x,y + 1,l)){
		if(l.floor[x][y + 1].type == WALL && y + 1 < NB_COL)
			liste = alloue_cellule(liste, x, y + 1);
	}	
	return liste;
}

/*compte le nombre de mur autour de la salle*/
int sum_rangewall(int x, int y,Labyrinthe l){
	int somme = 0;
	if(l.floor[x - 1][y].type == WALL)
		somme++;
	if(l.floor[x + 1][y].type == WALL)
		somme++;
	if(l.floor[x][y - 1].type == WALL)
		somme++;
	if(l.floor[x][y + 1].type == WALL)
		somme++;
	return somme;
}

/*identifie toutes les case de salles adjacentes a trois cases de mur et les transformes en mur*/
void adjacent_3mur(Labyrinthe *l){
	int i,j;
	for(i = 0; i < NB_LIG; i++){
		for(j = 0; j < NB_COL; j++){
			if(l->floor[i][j].type == ROOM){
				if(sum_rangewall(i,j,*l) == 3)
					l->floor[i][j].type = WALL;
			}
		}
	}	
}

void expand(Labyrinthe *l){
	Toexpand liste = NULL;
	Toexpand tmp = NULL;
	int tmpx,tmpy;
	int random;	
	liste = alloue_cellule(liste, NB_LIG/2 + 1, NB_COL/2);
	liste = alloue_cellule(liste, NB_LIG/2 - 1, NB_COL/2);
	liste = alloue_cellule(liste, NB_LIG/2, NB_COL/2 + 1);
	liste = alloue_cellule(liste, NB_LIG/2, NB_COL/2 - 1);
	do{
		do{	
			random = rand()%taille_liste(liste);
			tmp = recuperation(liste,random);
			tmpx = tmp->x;
			tmpy = tmp->y;
			liste = suppression(liste,random);
		}while(!admissible(tmpx,tmpy,*l) && liste != NULL);
		l->floor[tmpx][tmpy].type = ROOM;
		liste = adjacent_expand(tmpx,tmpy,*l,liste);	
	}while(liste!=NULL);
	adjacent_3mur(l);
	free(liste);
}