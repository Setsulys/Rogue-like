#ifndef __PERSONNAGE__
#define __PERSONNAGE__
#include "../includes/labyrinthe_expand.h"
typedef struct {
    int hp_max;
    int hp_actuel;
    int mp_max;
    int mp_actuel;
    int atk;
    int intel;
    int def;
    int chance_crit;
    int chance_critplus;
    int exp;
    int expmax;
    int lvl;
    int pts;
    int tours_potionexp;
    int tours_potionprecision;
    int tours_potion_regen;
    int boostxp;
} Personnage;

void init_attribut_perso_lvl1(Personnage *p);
void restauration_hp_mp(Personnage *p);
int monte_niveau(Personnage *p);
int attribution_pts_atk(Personnage *p);
int attribution_pts_intel(Personnage *p);
int attribution_pts_def(Personnage *p);
int mort_personnage(Personnage *p);
void gagne_exp(Personnage *p, Labyrinthe l, int x, int y);
int hp_act(int hp_acts, int hp_mx);
int mp_act(int mp_acts, int mp_mx);
int xp_act(int xp_acts, int xp_mx);
#endif