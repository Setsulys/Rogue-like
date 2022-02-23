#include "../includes/labyrinthe_expand.h"
#include "../includes/etage.h"
#include "../includes/load.h"

Floors ajouteEnFin(Floors liste, Labyrinthe l, int etage, int colorfloor, int colorwall){
	Floors element;
	Floors tmp;

	element = malloc(sizeof(struct floors));

	element->terrain = l;
	element->numetage = etage;
	element->colorwall = colorwall;
	element->colorfloor = colorfloor;

	if(liste == NULL)
		return element;
	tmp = liste;
	while(tmp->suivant != NULL)
		tmp = tmp->suivant;
	tmp->suivant = element;
	return liste;
}


Floors chargeDonjon(Floors etage){
	FILE * loadfile = NULL;
	Labyrinthe l;
	int buffer;
	int Tdonjon;
	int i,j;
	int floorcolor,wallcolor;

	loadfile = fopen("src/saves/save1.bin","rb");

	if(loadfile != NULL){
		fread(&buffer,sizeof(int),1,loadfile);
		Tdonjon = buffer;
		while(fread(&buffer,sizeof(int),1,loadfile)){
			l.floor[i][j].type = buffer;
			j++;
			if(j == NB_COL){
				j = 0;
				i++;
			}
			if(i == NB_LIG){
				i = 0;
				Tdonjon--;
				fread(&buffer,sizeof(int),1,loadfile);
				floorcolor = buffer;
				fread(&buffer,sizeof(int),1,loadfile);
				wallcolor = buffer;
				etage = ajouteEnFin(etage,l,Tdonjon,floorcolor,wallcolor);
			}

		}
		printf("..............................Donjon Chargé\n");
	}
	
	else{
		printf("Impossible d'ouvrir le fichier\n");
		printf("NOUVELLE PARTIE\n");
		return NULL;
	}
	fclose(loadfile);
	return etage;
}