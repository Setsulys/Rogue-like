#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

#include "../includes/labyrinthe_expand.h"
#include "../includes/labyrinthe_creation.h"
#include "../includes/Personnage.h"
#include "../includes/Inventaire.h"
#include "../includes/objetslab.h"
#include "../includes/etage.h"
#include "../includes/save.h"
#include "../includes/load.h"

#include "../includes/devtools.h"
#include "../includes/graphique.h"


int main(int argc, char const *argv[]){
	Labyrinthe l;

	Floors etage = NULL;
	Floors etageact /*= NULL*/;
	Personnage perso;
	Objets *inventaire[SLOT_INVENTAIRE];


	int pourcentage = 4;

	int x = (NB_LIG/2);
	int y = (NB_COL/2);
	int numeroetage;
	int Direction=0;
	int sound=0;
	int randfloor;
	int randwall;
	int title=0;

	int xmouse;
	int ymouse;
	MLV_Keyboard_button touche = 0;
	int labcreate = -1;
	/*int partiecharge=0;*/

	srand(time(NULL));
	
	MLV_create_window("Rogue like","Game",HEIGHT,WIDTH);
	MLV_init_audio();

	/*Loading sure*/
	/*From Other directory*/

	MLV_Image * Tool = MLV_load_image("src/Sprite/Other/iud.png");
	MLV_Image * Black = MLV_load_image("src/Sprite/Other/black.png");
	MLV_Image * Inventory = MLV_load_image("src/Sprite/Other/inventory.png");
	MLV_Image * Save = MLV_load_image("src/Sprite/Other/save.png");
	MLV_Image * Sound = MLV_load_image("src/Sprite/Other/sound.png");
	MLV_Image * NoSound = MLV_load_image("src/Sprite/Other/nosound.png");
	MLV_Image * Xp = MLV_load_image("src/Sprite/Other/Xp.png");
	MLV_Image * Hp = MLV_load_image("src/Sprite/Other/Hp.png");
	MLV_Image * Mp = MLV_load_image("src/Sprite/Other/Mp.png");
	MLV_Image * Point = MLV_load_image("src/Sprite/Other/Points.png");
	MLV_Image * Interface = MLV_load_image("src/Sprite/Other/interface.png");

	/*Objects directory*/
	MLV_Image * Slime = MLV_load_image("src/Sprite/mob/Slime.png");
	MLV_Image * Bleeder = MLV_load_image("src/Sprite/mob/bleeder.png");
	MLV_Image * Chest = MLV_load_image("src/Sprite/chest/Chest.png");
	MLV_Image * ChestO = MLV_load_image("src/Sprite/chest/Open_Chest.png");

	MLV_Image * Armor = MLV_load_image("src/Sprite/Objects/Armor.png");
	MLV_Image * Grimoire = MLV_load_image("src/Sprite/Objects/Grimoire.png");
	MLV_Image * Sword= MLV_load_image("src/Sprite/Objects/Sword.png");

	MLV_Image * Potion = MLV_load_image("src/Sprite/Objects/Potion_regen.png");
	MLV_Image * Potion_hp = MLV_load_image("src/Sprite/Objects/Potion_soin.png");
	MLV_Image * Potion_mp = MLV_load_image("src/Sprite/Objects/Potion_mana.png");
	MLV_Image * Potion_xp = MLV_load_image("src/Sprite/Objects/Potion_exp.png");
	MLV_Image * Potion_precision = MLV_load_image("src/Sprite/Objects/Potion_precision.png");
	


	/*Character directory*/
	MLV_Image * Face = MLV_load_image("src/Sprite/Character/face.png");
	MLV_Image * Rear = MLV_load_image("src/Sprite/Character/rear.png");
	MLV_Image * RSide = MLV_load_image("src/Sprite/Character/Rside.png");
	MLV_Image * LSide = MLV_load_image("src/Sprite/Character/Lside.png");


	/*animation*/
	MLV_Image * Up = MLV_load_image("src/Sprite/Up/up.png");
	MLV_Image * Up1 = MLV_load_image("src/Sprite/Up/up1.png");
	MLV_Image * Up2 = MLV_load_image("src/Sprite/Up/up2.png");
	MLV_Image * Up3 = MLV_load_image("src/Sprite/Up/up3.png");
	MLV_Image * Up4 = MLV_load_image("src/Sprite/Up/up4.png");
	MLV_Image * Up5 = MLV_load_image("src/Sprite/Up/up5.png");

	MLV_Image * Down = MLV_load_image("src/Sprite/Down/down.png");
	MLV_Image * Down1 = MLV_load_image("src/Sprite/Down/down1.png");
	MLV_Image * Down2 = MLV_load_image("src/Sprite/Down/down2.png");
	MLV_Image * Down3 = MLV_load_image("src/Sprite/Down/down3.png");
	MLV_Image * Down4 = MLV_load_image("src/Sprite/Down/down4.png");
	MLV_Image * Down5 = MLV_load_image("src/Sprite/Down/down5.png");


	MLV_Image * Floor; 
	MLV_Image * RWall;
	MLV_Image * UWall;
	MLV_Image * LWall;
	MLV_Image * Wall; 
	MLV_Image * StairD; 
	MLV_Image * StairU; 

	MLV_Music * bgm = MLV_load_music("src/sound/BGM2.mp3");
	MLV_Font * police = MLV_load_font("src/font/OMEGLE.ttf",15);
	MLV_Font * police2 = MLV_load_font("src/font/OMEGLE.ttf",30);
	MLV_Font * policeNiveau = MLV_load_font("src/font/OMEGLE.ttf",60);

	MLV_Image * credits = MLV_load_image("src/Sprite/Other/credits.png");
	MLV_draw_image(credits,0,0);
	MLV_actualise_window();
	MLV_wait_keyboard_or_mouse_or_seconds(&touche,NULL,NULL,&xmouse,&ymouse,4);	
	MLV_free_image(credits);

	do{
		title = DisplayTitle();
		if(title==0)
			return 0;
		else if(title==2){
			printf("Chargement de la derniere sauvegarde");
			/*etage = chargeDonjon(etage);
			affiche_labyrinthe(etage->terrain);
			printf("\nchargé etage %d \ncouleur 1 %d couleur 2 %d \n ",etage->numetage, etage->colorfloor,etage->colorwall);
			etageact = etage_actuel(etage,0);

			l = etage->terrain;
			labcreate =1;
			partiecharge =1;
			printf("aa\n");
			affiche_etage(etage);*/
		}
		else
			printf("nouvelle partie\n");

		numeroetage = 0;
		/*if(partiecharge == 0)*/
			labcreate =-1;
		/*else{}*/
			init_attribut_perso_lvl1(&perso);
			init_inventaire(inventaire);


		do{
			
			if(labcreate ==-1){
				labyrinthe_creation(&l,pourcentage,numeroetage);
				randfloor = rand()%3;
				randwall = rand()%3;
				etage = alloue_etage(etage,l,numeroetage,randwall,randfloor);
				etageact = etage_actuel(etage,numeroetage);
				x = (NB_LIG/2);
				y = (NB_COL/2);
			}
			printf("etage, %d\n", numeroetage);
			
		/*Color loading*/
			/*Map directory*/

			switch(randfloor){
				case 1: Floor = MLV_load_image("src/Sprite/blue/Floor.png");break;
				case 2: Floor = MLV_load_image("src/Sprite/red/Floor.png");break;
				case 0: Floor = MLV_load_image("src/Sprite/green/Floor.png");break;
				default:  Floor = MLV_load_image("src/Sprite/blue/Floor.png");break;
			}
			switch(randwall){
				case 1:{
					RWall = MLV_load_image("src/Sprite/green/R_Wall.png");
					UWall = MLV_load_image("src/Sprite/green/U_Wall.png");
					LWall = MLV_load_image("src/Sprite/green/L_Wall.png");
					Wall = MLV_load_image("src/Sprite/green/Wall.png");
					StairD = MLV_load_image("src/Sprite/green/StairDown.png");
					StairU = MLV_load_image("src/Sprite/green/StairUp.png");
				}break;
				case 2:{
				 	RWall = MLV_load_image("src/Sprite/blue/R_Wall.png");
				 	UWall = MLV_load_image("src/Sprite/blue/U_Wall.png");
				 	LWall = MLV_load_image("src/Sprite/blue/L_Wall.png");
				 	Wall = MLV_load_image("src/Sprite/blue/Wall.png");
				 	StairD = MLV_load_image("src/Sprite/blue/StairDown.png");
				 	StairU = MLV_load_image("src/Sprite/blue/StairUp.png");
				}break;
				case 0:{
					RWall = MLV_load_image("src/Sprite/red/R_Wall.png");
					UWall = MLV_load_image("src/Sprite/red/U_Wall.png");
					LWall = MLV_load_image("src/Sprite/red/L_Wall.png");
					Wall = MLV_load_image("src/Sprite/red/Wall.png");
					StairD = MLV_load_image("src/Sprite/red/StairDown.png");
					StairU = MLV_load_image("src/Sprite/red/StairUp.png");
				}break;
				default:{
					RWall = MLV_load_image("src/Sprite/green/R_Wall.png");
					UWall = MLV_load_image("src/Sprite/green/U_Wall.png");
					LWall = MLV_load_image("src/Sprite/green/L_Wall.png");
					Wall = MLV_load_image("src/Sprite/green/Wall.png");
					StairD = MLV_load_image("src/Sprite/green/StairDown.png");
					StairU = MLV_load_image("src/Sprite/green/StairUp.png");

				}
			}
			


		/*Resize and First Display*/	
			resize_sprite(Tool, Black, Inventory, Save, Sound, NoSound,
				Xp, Hp, Mp, Point,
				Floor, RWall, UWall, LWall, Wall, StairD, StairU,
				Slime, Bleeder, Chest, ChestO, 
				Armor, Grimoire, Potion, Sword,
				Face, Rear, RSide, LSide,
				Potion_hp,Potion_mp,Potion_xp,Potion_precision);
			
			Display(l, Tool, Black, Inventory, Save, Sound, NoSound,
				Xp, Hp, Mp, Point,
				Floor, RWall, UWall, LWall, Wall, StairD, StairU,
				Slime, Bleeder, Chest, ChestO,
				Face, Rear, RSide, LSide, 
				x, y, Direction, sound);
			Display_point(perso.exp,perso.expmax,perso.hp_actuel,perso.hp_max,perso.mp_actuel,perso.mp_max,perso.lvl,perso.pts,perso.atk,perso.intel,perso.def,police, police2);
			Display_item(Armor, Grimoire,  Sword, Potion,Potion_hp,Potion_mp,Potion_xp,Potion_precision, inventaire);
			MLV_actualise_window();
			if(sound==0){
				bgm = MLV_load_music("src/sound/BGM2.mp3");
				MLV_play_music(bgm,0.5,-1);
			}

		/*Principal*/
			int act = 0;
			do{
			act = Action(&l, &x, &y, &Direction, &sound,bgm, &perso, inventaire,Interface,police2);
			if( act == 20){
				etage =modifetage(etage,etageact,numeroetage);
				sauvegardeDonjon(etage);
			}
			Display(l, Tool, Black, Inventory, Save, Sound, NoSound,
				Xp, Hp, Mp, Point,
				Floor, RWall, UWall, LWall, Wall, StairD, StairU,
				Slime, Bleeder, Chest, ChestO,
				Face, Rear, RSide, LSide, 
				x, y,Direction, sound);
			resize_point(Xp, Hp, Mp,xp_act(perso.exp, perso.expmax),hp_act(perso.hp_actuel,perso.hp_max),mp_act(perso.mp_actuel,perso.mp_max));
			Display_point(perso.exp,perso.expmax,perso.hp_actuel,perso.hp_max,perso.mp_actuel,perso.mp_max,perso.lvl,perso.pts,perso.atk,perso.intel,perso.def,police, police2);
			Display_item(Armor, Grimoire,  Sword, Potion,Potion_hp,Potion_mp,Potion_xp,Potion_precision, inventaire);
			MLV_actualise_window();
			if(mort_personnage(&perso)==0)
				act =3;
			}while(act != 2 && act != 1 && act != 3);

			MLV_stop_music();
			if(act==1 || act==2){
				if(act==1){
					animationUp(Up,Up1,Up2,Up3,Up4,Up5,numeroetage,policeNiveau);
					etageact->terrain = l;
					Direction = 3;
					printf("bbb\n");
					etage = modifetage(etage,etageact,numeroetage);
					numeroetage--;
					labcreate = 1;
					if(numeroetage < 0 ){
						MLV_Image * deserted = MLV_load_image("src/Sprite/Other/deserted.png");
						MLV_Music * leave = MLV_load_music("src/sound/musicdeserted.mp3");
						MLV_draw_image(deserted,0,0);
						MLV_actualise_window();
						if(sound==0)
							MLV_play_music(leave,1.0,1);
						MLV_wait_keyboard_or_mouse_or_seconds(&touche,NULL,NULL,&xmouse,&ymouse,17);
						MLV_stop_music();
						MLV_free_image(deserted);
						MLV_free_music(leave);
						break;
					}
					else{
						etageact = etage_actuel(etage,numeroetage);
						printf("%d\n",etageact->numetage );
						l = etageact->terrain;
						randfloor = etageact->colorfloor;
						randwall = etageact->colorwall;	
						for(int a=0; a < NB_LIG; a++){
							for(int b=0; b < NB_COL; b++){
								if(l.floor[a][b].type == STAIR_DOWN){
									x = a;
									y = b;
								}
							}
						}
					}
				}
				else if(act == 2){	
					animationDown(Down,Down1,Down2,Down3,Down4,Down5,numeroetage,policeNiveau);
					etageact->terrain = l;
					Direction = 3;
					etage = modifetage(etage,etageact,numeroetage);
					printf("eaifaef\n");
					numeroetage++;	
					printf("aaaaaa\n");
					if(numeroetage < taille_donjon(etage)){
						printf("aaa\n");
						labcreate=1;
						etageact = etage_actuel(etage,numeroetage);
						l=etageact->terrain;
						randfloor = etageact->colorfloor;
						randwall = etageact->colorwall;	
						printf("on cree pas on reviens\n");	
					}
					else{
						labcreate =-1;	
						printf("creation nouvel etage\n");

					}
					x = NB_LIG/2;
					y = NB_COL/2;
					
					
				}
			}
			else{
					MLV_Image * Dead = MLV_load_image("src/Sprite/Other/Mort.png");
					MLV_Music * leave = MLV_load_music("src/sound/Death.mp3");
					MLV_draw_image(Dead,0,0);
					MLV_actualise_window();
					if(sound==0)
						MLV_play_music(leave,1.0,1);
					MLV_wait_keyboard_or_mouse_or_seconds(&touche,NULL,NULL,&xmouse,&ymouse,17);
					MLV_stop_music();
					MLV_free_image(Dead);
					MLV_free_music(leave);
					break;
				}
		}while(1);
	}while(title != 0);
	effacelisteetage(etage);
	etage=NULL;
	etageact=NULL;
	MLV_free_music(bgm);
	free_images(Tool, Black, Inventory, Save, Sound, NoSound,
		Xp, Hp, Mp, Point,
		Floor, RWall, UWall, LWall, Wall, StairD, StairU,
		Slime, Bleeder, Chest, ChestO,
		Armor, Grimoire, Potion, Sword,
		Face, Rear, RSide, LSide,Interface,
		Potion_hp,Potion_mp,Potion_xp,Potion_precision);
	MLV_free_window();


	return 0;
}