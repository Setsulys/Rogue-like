#include <stdio.h>
#include <stdlib.h>
#include "../includes/labyrinthe_expand.h"
#include "../includes/Personnage.h"

void init_attribut_perso_lvl1(Personnage *p) {
    p->atk = 10;
    p->intel = 10;
    p->def = 10;
    p->hp_max = p->hp_actuel = 10 * p->def;
    p->mp_max = p->mp_actuel = 10 * p->intel - 50;
    p->chance_crit = 5;
    p->chance_critplus = 0;
    p->exp = 0;
    p->expmax = 400;
    p->lvl = 0;
    p->pts = 0;
    p->tours_potionexp=0;
    p->tours_potionprecision=0;
    p->tours_potion_regen=0;
    p->boostxp=0;
}

void restauration_hp_mp(Personnage *p) {
    p->hp_actuel = 10 * p->def;
    p->mp_actuel = 10 * p->intel - 50;
}

int monte_niveau(Personnage *p) {
    int n;

    n = p->lvl + 1;

    if (p->exp >= 350 + 50 * n) {
        p->expmax =350 + 50 * n;
        p->exp -= 350 + 50 * n;
        p->lvl++;
        p->pts += 3;

        restauration_hp_mp(p);

        return 0;
    }

    return 1;
}


int attribution_pts_atk(Personnage *p) {
    if (p->pts >= 1) {
        p->atk++;
        p->pts--;

        return 0;
    }

    return 1;
}

int attribution_pts_intel(Personnage *p) {
    if (p->pts >= 1) {
        p->intel++;
        p->pts--;
        p->mp_max = 10 * p->intel - 50;

        return 0;
    }
    return 1;
}

int attribution_pts_def(Personnage *p) {
    if (p->pts >= 1) {
        p->def++;
        p->pts--;
        p->hp_max = 10 * p->def;

        return 0;
    }

    return 1;
}

int mort_personnage(Personnage *p) {
    if (p->hp_actuel <= 0)
        return 0;

    else
        return 1;
}

void gagne_exp(Personnage *p,Labyrinthe l, int x,int y) {
    if(p->exp < p->expmax)
        p->exp += l.floor[x][y].entity.exp;
    monte_niveau(p);
}

int hp_act(int hp_acts, int hp_mx){
    return (hp_acts*100)/hp_mx;
}

int mp_act(int mp_acts, int mp_mx){
    return (mp_acts*100)/mp_mx;
}

int xp_act(int xp_acts, int xp_mx){
    return (xp_acts*100)/xp_mx;
}
