#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/Monstres.h"

void init_attribut_monstre(Monstres *m, int etage) {
    m->hp = (rand() % 11) + 10 * etage;
    m->atk = ((rand() % 5) + 1) * etage;
    m->exp = (rand() % 30) + 15 * etage;
}

int mort_monstre(Monstres *m) {
    if (m->hp <= 0)
        return 0;

    else
        return 1;
}
