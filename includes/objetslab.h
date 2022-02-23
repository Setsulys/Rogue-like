#ifndef __OBJETSLAB__
#define __OBJETSLAB__

void tresor_sans_issue(Labyrinthe *l, int etage);

void tresor_escalier(Labyrinthe *l);

void ajout_mob(Labyrinthe *l,int pourcentage, int etage);

/*Distance de manhattan*/
/*Fonction de valeur absolue*/
int abs(int a);

/*Fonction calculant la distance de manhattan*/
int distance_de_Manhattan(int i1,int i2, int j1, int j2);

Toexpand effaceliste(Toexpand liste);

void ajout_escalier(Labyrinthe *l);

#endif