#include "../includes/labyrinthe_expand.h"
#include "../includes/Combat.h"

void joueur_attaque_mele(Personnage *p, Labyrinthe * l,int x, int y) {
    int coup_crit;

    coup_crit = coup_critique_joueur(p);

    printf("\nCC mele Joueur : %d\n", coup_crit);

    if (coup_crit != 1) {
        l->floor[x][y].entity.hp = l->floor[x][y].entity.hp - (p->atk * (80 + rand() % 40) / 100);
    }

    else {
        l->floor[x][y].entity.hp = l->floor[x][y].entity.hp - ((p->atk * (80 + rand() % 40) / 100) * 3);
    }
}

void joueur_attaque_magique(Personnage *p, Labyrinthe * l,int x, int y) {
    int coup_crit;

    coup_crit = coup_critique_joueur(p);

    printf("\nCC magique Joueur : %d\n", coup_crit);

    p->mp_actuel -= 20;
    if(p->mp_actuel< 0)
        p->mp_actuel=0;
    if (coup_crit != 1) {
        l->floor[x][y].entity.hp = l->floor[x][y].entity.hp - ((p->intel * 2) * (80 + rand() % 40) / 100);
    }

    else {
        l->floor[x][y].entity.hp = l->floor[x][y].entity.hp - (((p->intel * 2) * (80 + rand() % 40) / 100) * 3);
    }
}

void monstre_attaque_mele(Personnage *p, Labyrinthe * l,int x, int y) {
    int coup_crit;

    coup_crit = coup_critique_monstre();

    printf("\nCC Monstre : %d\n", coup_crit);

    if (coup_crit != 1) {
        p->hp_actuel = p->hp_actuel - (l->floor[x][y].entity.atk * (80 + rand() % 40) / 100);
    }

    else {
        p->hp_actuel = p->hp_actuel - ((l->floor[x][y].entity.atk * (80 + rand() % 40) / 100) * 3);
    }
}

int coup_critique_joueur(Personnage *p) {
    int coup_critique;

    if (p->chance_crit == 5) 
        coup_critique = rand() % 20;

    else if (p->chance_crit == 15)
        coup_critique = rand() % 7;

    return coup_critique;
}

int coup_critique_monstre(void) {
    int coup_critique;

    coup_critique = rand() % 20;

    return coup_critique;
}

void affiche_stat_joueur(Personnage p) {
    printf("Joueur\n\natk : %d\nintel : %d\ndef : %d\nhp max : %d\nhp actuel : %d\nmp max : %d\nmp actuel : %d\nexp : %d\nlvl : %d\npts : %d\n",
        p.atk, p.intel, p.def, p.hp_max, p.hp_actuel, p.mp_max, p.mp_actuel, p.exp, p.lvl, p.pts);
}

void affiche_stat_monstre(Monstres m) {
    printf("\nMonstre\n\natk : %d\nhp : %d\n", m.atk, m.hp);
}

int monstrevie(Labyrinthe * l,int x, int y) {
    if (l->floor[x][y].entity.hp <= 0)
        return 0;

    else
        return 1;
}