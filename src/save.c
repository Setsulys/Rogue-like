
#include "../includes/labyrinthe_expand.h"
#include "../includes/etage.h"
#include "../includes/Personnage.h"
#include "../includes/save.h"

int sauvegardeDonjon(Floors etage){

	FILE * Savefile = NULL;
	int Tdonjon = taille_donjon(etage); 
	int i,j;


	Savefile = fopen("src/saves/save1.bin","wb+");
	if(Savefile != NULL){
		fwrite(&Tdonjon, sizeof(int),1,Savefile);
		while(etage != NULL){
			for(i = 0; i < NB_LIG; i++ ){
				for(j = 0; j < NB_COL; j++){
					fwrite(&etage->terrain.floor[i][j].type,sizeof(int),1,Savefile);
					fwrite(&etage->terrain.floor[i][j].entity.hp, sizeof(int),4,Savefile);
					fwrite(&etage->terrain.floor[i][j].entity.exp, sizeof(int),4,Savefile);
					fwrite(&etage->terrain.floor[i][j].entity.atk, sizeof(int),4,Savefile);

				}
			}
			fwrite(&etage->colorfloor,sizeof(int),1,Savefile);
			fwrite(&etage->colorwall,sizeof(int),1,Savefile);
			etage = etage->suivant;
		}
	}
	else{
		printf("Impossible d'ouvrir le fichier\n");
		return 1;
	}
	fclose(Savefile);
	return 0;
}

int sauvegarde_perso(Personnage p){
	FILE * Savefile = NULL;
	Savefile = fopen("src/saves/save2.bin","wb+");
	if(Savefile != NULL){
		fwrite(&p.atk, sizeof(int),4,Savefile);
		fwrite(&p.intel, sizeof(int),4,Savefile);
		fwrite(&p.def, sizeof(int),4,Savefile);
		fwrite(&p.hp_max, sizeof(int),4,Savefile);
		fwrite(&p.mp_max, sizeof(int),4,Savefile);
		fwrite(&p.chance_crit, sizeof(int),4,Savefile);
		fwrite(&p.chance_critplus, sizeof(int),4,Savefile);
		fwrite(&p.exp, sizeof(int),4,Savefile);
		fwrite(&p.expmax, sizeof(int),4,Savefile);
		fwrite(&p.lvl, sizeof(int),4,Savefile);
		fwrite(&p.pts, sizeof(int),4,Savefile);
		fwrite(&p.tours_potionexp, sizeof(int),4,Savefile);
		fwrite(&p.tours_potionprecision, sizeof(int),4,Savefile);
		fwrite(&p.tours_potion_regen, sizeof(int),4,Savefile);
		fwrite(&p.boostxp, sizeof(int),4,Savefile);
	}
	else{
		printf("Impossible d'ouvrir le fichier\n");
		return 1;
	}
	fclose(Savefile);
	return 0;
}	