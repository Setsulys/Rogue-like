	#ifndef  __LABYRINTHE_EXPAND__
#define __LABYRINTHE_EXPAND__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COL 	/*13*/63
#define NB_LIG 	/*9*/43

#define HEIGHT 1300
#define WIDTH 900

typedef enum{
	WALL,
	ROOM,
	MONSTER,
	TREASURE,
	TREASUREO,
	STAIR_UP,
	STAIR_DOWN
}Celltype;

typedef struct {
    int hp;
    int atk;
    int exp;
} Monstres;

typedef struct {
	Monstres entity;
	Celltype type;
}Cell;

typedef struct{
	Cell floor[NB_LIG][NB_COL];
} Labyrinthe;

typedef struct cellule{
	int x;
	int y;
	struct cellule * suivant;
}* Toexpand;

void init_labyrinthe(Labyrinthe * l);

Toexpand alloue_cellule(Toexpand liste, int x, int y);

Toexpand recuperation(Toexpand liste, int indice);

Toexpand suppression(Toexpand liste, int indice);

int taille_liste(Toexpand liste);

/*Fonction verifiant qu'il y a une salle au plus au tour de la case*/
int sum_range1(int x, int y,Labyrinthe l);

/*Fonction verifiant qu'il y a deux salles au plus au tour de la case a distance 2*/
int sum_range2(int x,int y,Labyrinthe l);

/*Fonction verifiant que la case est admissible*/
int admissible(int x,int y,Labyrinthe l);

/*verifie si une case est deja dans la liste*/
int verif_presence(int x, int y,Toexpand liste);

Toexpand adjacent_expand(int x, int y, Labyrinthe l, Toexpand liste);

/*compte le nombre de mur autour de la salle*/
int sum_rangewall(int x, int y,Labyrinthe l);

/*identifie toutes les case de salles adjacentes a trois cases de mur et les transformes en mur*/
void adjacent_3mur(Labyrinthe *l);

void expand(Labyrinthe *l);
#endif