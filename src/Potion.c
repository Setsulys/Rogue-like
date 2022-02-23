#include <stdio.h>
#include <stdlib.h>
#include "../includes/Potion.h"
void utilise_potion_soin(Personnage *p) {
    int tmp = p->hp_max / 10;
    if(p->hp_actuel < 0 )
        p->hp_actuel =0;
    if (p->hp_actuel + tmp > p->hp_max)
        p->hp_actuel = p->hp_max;

    else
        p->hp_actuel += tmp;

}

void utilise_potion_mana(Personnage *p) {
    int tmp = p->mp_max / 10;
    if(p->mp_actuel < 0 )
        p->mp_actuel =0;
    p->mp_actuel += tmp;
    if (p->mp_actuel > p->mp_max)
        p->mp_actuel = p->mp_max;
}

void utilise_potion_regen(Personnage *p) {
    int tmp_hp, tmp_mp;
    tmp_hp = 20;
    tmp_mp = 10;
    if(p->tours_potion_regen <=0){
        p->hp_actuel += tmp_hp;
        p->mp_actuel += tmp_mp;
        p->tours_potion_regen=30;
        if (p->hp_actuel > p->hp_max)
            p->hp_actuel = p->hp_max;

        if (p->mp_actuel> p->mp_max)
            p->mp_actuel = p->mp_max;


    }

}

void utilise_potion_precision( Personnage *p) {
    if(p->tours_potionprecision <=0){
        p->chance_critplus = (rand()%10)+5;
        p->tours_potionprecision = 30;
    }
}

void utilise_potion_exp( Personnage *p) {
    if(p->tours_potionexp <= 0){
        p->boostxp=1;
        p->tours_potionexp = 30;
    }
}


void utilise_potion(Objets * inventaire[SLOT_INVENTAIRE],Personnage *p, int emplacement ){
    switch(inventaire[emplacement]->type_objet){
        case POTION_SOIN: utilise_potion_soin(p);break;
        case POTION_MANA: utilise_potion_mana(p);break;
        case POTION_REGEN: utilise_potion_regen(p);break;
        case POTION_PRECISION: utilise_potion_precision(p);break;
        case POTION_EXP: utilise_potion_exp(p);break;
        default:break;
    }
}