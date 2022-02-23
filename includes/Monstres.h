#ifndef __MONSTRES__
#define __MONSTRES__

typedef struct {
    int hp;
    int atk;
    int exp;
} Monstres;

void init_attribut_monstre(Monstres *m, int etage);
int mort_monstre(Monstres *m);

#endif