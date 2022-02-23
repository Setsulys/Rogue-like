#ifndef __COMBAT__
#define __COMBAT__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/Personnage.h"

int coup_critique_joueur(Personnage *p);
int coup_critique_monstre(void);
void joueur_attaque_mele(Personnage *p, Labyrinthe * l, int x, int y);
void joueur_attaque_magique(Personnage *p, Labyrinthe * l, int x, int y);
void monstre_attaque_mele(Personnage *p, Labyrinthe * l, int x, int y);
void affiche_stat_joueur(Personnage p);
void affiche_stat_monstre(Monstres m);
int monstrevie(Labyrinthe * l,int x, int y);

#endif