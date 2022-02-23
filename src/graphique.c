#include "../includes/labyrinthe_expand.h"
#include "../includes/Personnage.h"
#include "../includes/Inventaire.h"
#include "../includes/Potion.h"	
#include "../includes/Combat.h"
#include "../includes/graphique.h"


void resize_sprite( MLV_Image * Tool, MLV_Image * Black, MLV_Image * Inventory, 
	MLV_Image * Save, MLV_Image * Sound, MLV_Image * NoSound,
	MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp, MLV_Image * Point,
	MLV_Image *Floor, MLV_Image * RWall, MLV_Image *UWall, 
	MLV_Image * LWall, MLV_Image * Wall,MLV_Image * StairD, MLV_Image * StairU, 
	MLV_Image *Slime, MLV_Image * Bleeder, MLV_Image * Chest, MLV_Image * ChestO,
	MLV_Image * Armor, MLV_Image * Grimoire, MLV_Image * Potion, MLV_Image * Sword,
	MLV_Image * Face, MLV_Image * Rear, MLV_Image * RSide, MLV_Image * LSide,
	MLV_Image * Potion_hp, MLV_Image * Potion_mp, MLV_Image * Potion_xp, MLV_Image * Potion_precision){

	MLV_resize_image(Tool, 540, 200);
	MLV_resize_image(Black, 540, 200);
	MLV_resize_image(Inventory, 600, 150);
	MLV_resize_image(Save, 50, 50);
	MLV_resize_image(Sound, 50, 50);
	MLV_resize_image(NoSound, 50, 50);
	MLV_resize_image(Xp,0,15);
	MLV_resize_image(Hp,221,15);
	MLV_resize_image(Mp,221,15);
	MLV_resize_image(Point,444,70);

	MLV_resize_image(Floor, 100, 100);
	MLV_resize_image(RWall, 100, 100);
	MLV_resize_image(UWall, 100, 100);
	MLV_resize_image(LWall, 100, 100);
	MLV_resize_image(Wall, 100, 100);
	MLV_resize_image(StairD, 100, 100);
	MLV_resize_image(StairU, 100, 100);

	MLV_resize_image(Chest, 100, 100);
	MLV_resize_image(ChestO, 100, 100);
	MLV_resize_image(Slime, 100, 100);
	MLV_resize_image(Bleeder,100,100);

	MLV_resize_image(Armor,50,50);
	MLV_resize_image(Grimoire,50,50);
	MLV_resize_image(Sword,50,50);

	MLV_resize_image(Potion,50,50);
	MLV_resize_image(Potion_hp,50,50);
	MLV_resize_image(Potion_mp,50,50);
	MLV_resize_image(Potion_xp,50,50);
	MLV_resize_image(Potion_precision,50,50);

	MLV_resize_image(Face, 100, 100);
	MLV_resize_image(Rear, 100, 100);
	MLV_resize_image(RSide, 100, 100);
	MLV_resize_image(LSide, 100, 100);
}

void free_images(MLV_Image * Tool, MLV_Image * Black, MLV_Image * Inventory, 
	MLV_Image * Save, MLV_Image * Sound, MLV_Image * NoSound,
	MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp, MLV_Image * Point,
	MLV_Image *Floor, MLV_Image * RWall, MLV_Image *UWall, 
	MLV_Image * LWall, MLV_Image * Wall,MLV_Image * StairD, MLV_Image * StairU, 
	MLV_Image *Slime, MLV_Image * Bleeder, MLV_Image * Chest,MLV_Image * ChestO,
	MLV_Image * Armor, MLV_Image * Grimoire, MLV_Image * Potion, MLV_Image * Sword,
	MLV_Image * Face, MLV_Image * Rear, MLV_Image * RSide, MLV_Image * LSide,  MLV_Image * Interface,
	MLV_Image * Potion_hp, MLV_Image * Potion_mp, MLV_Image * Potion_xp, MLV_Image * Potion_precision){

	MLV_free_image(Tool);
	MLV_free_image(Black);
	MLV_free_image(Inventory);
	MLV_free_image(Save);
	MLV_free_image(Sound);
	MLV_free_image(NoSound);
	MLV_free_image(Xp);
	MLV_free_image(Hp);
	MLV_free_image(Mp);
	MLV_free_image(Point);
	MLV_free_image(Interface);

	MLV_free_image(Floor);
	MLV_free_image(RWall);
	MLV_free_image(LWall);
	MLV_free_image(Wall);
	MLV_free_image(StairD);
	MLV_free_image(StairU);

	MLV_free_image(Chest);
	MLV_free_image(ChestO);
	MLV_free_image(Slime);
	MLV_free_image(Bleeder);

	MLV_free_image(Armor);
	MLV_free_image(Grimoire);
	MLV_free_image(Sword);
	MLV_free_image(Potion);
	MLV_free_image(Potion_hp);
	MLV_free_image(Potion_mp);
	MLV_free_image(Potion_xp);
	MLV_free_image(Potion_precision);


	MLV_free_image(Face);
	MLV_free_image(Rear);
	MLV_free_image(RSide);
	MLV_free_image(LSide);

}

void DisplayFloor(Labyrinthe l, const MLV_Image * floor, const MLV_Image * chest, const MLV_Image * ChestO,
	const MLV_Image * Slime, const MLV_Image * Bleeder, const MLV_Image * StairD, const MLV_Image * StairU, int x, int y){
	int i,j;
	for(i = x; i < x + 9; i++){
		for(j = y; j < y + 13; j++){
			if(i > 0 && j > 0 && i <= NB_LIG && j <= NB_COL ){
				if(l.floor[i][j].type != WALL )
					MLV_draw_image(floor,(j-y)*100,(i-x)*100);
				if(l.floor[i][j].type == TREASURE)
					MLV_draw_image(chest,(j-y)*100,(i-x)*100);
				if(l.floor[i][j].type == STAIR_DOWN)
					MLV_draw_image(StairD,(j-y)*100,(i-x)*100);
				if(l.floor[i][j].type == MONSTER)
					MLV_draw_image(Bleeder,(j-y)*100,(i-x)*100);
				if(l.floor[i][j].type == STAIR_UP)
					MLV_draw_image(StairU,(j-y)*100,(i-x)*100);
				if(l.floor[i][j].type == TREASUREO)
					MLV_draw_image(ChestO,(j-y)*100,(i-x)*100);
			}

		}
	}
}

void DisplayWall(Labyrinthe l,const MLV_Image * RWall, const MLV_Image * LWall, 
	const MLV_Image * UWall,const MLV_Image * Wall, int x,int y){
	int i,j;
	for(i = x; i < x + 9; i++){
		for(j = y; j < y + 13; j++){
			if(i >= 0 && j >= 0 && i <= NB_LIG && j <= NB_COL ){
				if(l.floor[i - 1][j].type != WALL && l.floor[i][j].type == WALL ){
					MLV_draw_image(UWall,(j-y)*100 ,(i-x)*100 - (230/10));
				}
				if(l.floor[i][j - 1].type != WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(LWall,(j-y)*100,(i-x)*100 );
				}
				if(l.floor[i][j + 1].type !=WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(RWall,(j-y)*100,(i-x)*100);
				}	
				if(l.floor[i+1][j-1].type != WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(LWall,(j-y)*100,(i-x)*100);
				}
				if(l.floor[i + 1][j - 1].type != WALL && l.floor[i - 1][j].type == WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(LWall,(j-y)*100,(i-x)*100);
				}
				if(l.floor[i + 1][j + 1].type !=WALL && l.floor[i + 1][j].type == WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(RWall,(j-y)*100,(i-x)*100);
				}
				if(l.floor[i + 1][j].type != WALL && l.floor[i][j].type == WALL){
					MLV_draw_image(Wall,(j-y)*100,(i-x)*100);
				}
			}
		}
	}
}

void Display_Character(Labyrinthe l,const MLV_Image * Face, const MLV_Image * Rear, 
	const MLV_Image * RSide, const MLV_Image * LSide, int Direction){
	switch(Direction){
		case 1:MLV_draw_image(Rear,(6)*100,(4)*100);break;
		case 3:MLV_draw_image(Face,(6)*100,(4)*100);break;
		case 4:MLV_draw_image(LSide,(6)*100,(4)*100);break;
		case 2:MLV_draw_image(RSide,(6)*100,(4)*100);break;
		default:MLV_draw_image(Face,(6)*100,(4)*100);break;
	}	
}

void DisplayTool(const MLV_Image * Tool,const MLV_Image * Black, 
	const MLV_Image * Inventory, const MLV_Image * Save, 
	const MLV_Image * Sound, const MLV_Image * NoSound,
	const MLV_Image * Xp, const MLV_Image * Hp, const MLV_Image * Mp, const MLV_Image *Point,
	int sound){
	MLV_draw_image(Black, 0, 0);
	MLV_draw_image(Xp,220,36);
	MLV_draw_image(Hp,220,60);
	MLV_draw_image(Mp,220,80);	
	MLV_draw_image(Tool, 0, 0);

	MLV_draw_image(Point,HEIGHT-444,WIDTH-70);

	MLV_draw_image(Inventory, 350, 750);
	MLV_draw_image(Save, HEIGHT - 75, 25);
	if(sound==0){
		MLV_draw_image(Sound, HEIGHT - 75, 100);
	}
	else{
		MLV_draw_image(NoSound, HEIGHT - 75, 100);
	}
}

void Display_point(int xp, int xpmax, int hp, int hpmax, int mp, int mpmax, int lv,int point, int atk, int intel, int def, MLV_Font * police, MLV_Font * police2){
	MLV_draw_adapted_text_box_with_font(315,38,"%d/%d",police,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_ORANGE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,xp,xpmax);
	MLV_draw_adapted_text_box_with_font(315,61,"%d/%d",police,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARKBLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,hp,hpmax);
	MLV_draw_adapted_text_box_with_font(315,80,"%d/%d",police,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARKRED,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,mp,mpmax);
	MLV_draw_adapted_text_box_with_font(477,35,"%d",police,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_ORANGE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,lv);

	MLV_draw_adapted_text_box_with_font(940,850,"%d",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,point);
	MLV_draw_adapted_text_box_with_font(1045,850,"%d",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,atk);
	MLV_draw_adapted_text_box_with_font(1132,850,"%d",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,intel);
	MLV_draw_adapted_text_box_with_font(1219,850,"%d",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,def);


}

void Display(Labyrinthe l, const MLV_Image * Tool, const MLV_Image * Black, const MLV_Image * Inventory, 
	const MLV_Image * Save, const MLV_Image * Sound, const MLV_Image * NoSound,
	const MLV_Image * Xp, const MLV_Image * Hp, const MLV_Image * Mp, const MLV_Image * Point,
	const MLV_Image *Floor, const MLV_Image * RWall, const MLV_Image *UWall, 
	const MLV_Image * LWall, const MLV_Image * Wall, const MLV_Image * StairD, const MLV_Image * StairU,
	const MLV_Image *Slime, const MLV_Image * Bleeder, const MLV_Image * Chest, const MLV_Image * ChestO,
	const MLV_Image * Face, const MLV_Image * Rear, const MLV_Image * RSide, const MLV_Image * LSide, 
	int x, int y, int Direction, int sound){
	int x1,y1;
	x1=x-4;
	y1=y-6;
	MLV_clear_window(MLV_COLOR_DARKGRAY);
	DisplayFloor(l, Floor, Chest, ChestO, Slime, Bleeder, StairD, StairU, x1 , y1);
	Display_Character(l,Face, Rear, RSide, LSide,Direction);
	DisplayWall(l, RWall, LWall, UWall, Wall, x1, y1);
	DisplayTool(Tool, Black, Inventory, Save, Sound, NoSound, Xp, Hp, Mp,Point, sound);
}



void resize_point(MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp,int experience, int health, int mana){

	experience = (experience*221)/100;
	health = (health*221)/100;
	mana = (mana*221)/100;
	if(experience < 0)
		experience = 0;
	if(health < 0)
		health = 0;
	if(mana < 0)
		mana = 0;

	MLV_resize_image(Xp,experience,15);
	MLV_resize_image(Hp,health,15);
	MLV_resize_image(Mp,mana,15);
}


void sound_mod(int x, int y, int * mouse , MLV_Music * bgm){
	
	if(*mouse == 1 ){
		*mouse=0;
		bgm = MLV_load_music("src/sound/BGM2.mp3");
		MLV_play_music(bgm,0.5,-1);
	}
	else{
		*mouse=1;
		MLV_stop_music();
	}
}

void Display_item(const MLV_Image * Armor, const MLV_Image * Grimoire,  const MLV_Image * Sword, const MLV_Image * Potion, 
	const MLV_Image * Potion_hp, const MLV_Image * Potion_mp , const MLV_Image * Potion_xp,
	const MLV_Image * Potion_precision, Objets * inventaire[SLOT_INVENTAIRE]){
	int i;
	int y,x;
	for(i = 0 ; i < SLOT_INVENTAIRE; i++){
		x=i%6;
		if(i < 6 )
			y = 773;
		else
			y = 832;	
		switch(inventaire[i]->type_objet){
			case EPEE : MLV_draw_image(Sword,460+(64*x),y);break;
			case ARMURE : MLV_draw_image(Armor,460+(64*x),y);break;
			case GRIMOIRE:MLV_draw_image(Grimoire,460+(64*x),y);break;
			case POTION_MANA:MLV_draw_image(Potion_mp,460+(64*x),y);break;
			case POTION_SOIN:MLV_draw_image(Potion_hp,460+(64*x),y);break;
			case POTION_REGEN:MLV_draw_image(Potion,460+(64*x),y);break;
			case POTION_PRECISION:MLV_draw_image(Potion_precision,460+(64*i),y);break;
			case POTION_EXP:MLV_draw_image(Potion_xp,460+(64*x),y);break;
			default:break;
		}
	}

}

void affiche_interface(Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2, int i){
	MLV_Keyboard_button touche=0;
	int xmouse=0,ymouse=0;
	MLV_draw_image(Interface,488,338);
	switch(inventaire[i]->type_objet){
		case POTION_MANA: MLV_draw_adapted_text_box_with_font(520,370,"POTION_MANA",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);	
			MLV_draw_adapted_text_box_with_font(510,400,"restaure 10%% des MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		
		case POTION_SOIN: MLV_draw_adapted_text_box_with_font(520,370,"POTION_SOIN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"restaure 10%% des MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);	break;
		case POTION_REGEN: MLV_draw_adapted_text_box_with_font(520,370,"POTION_REGEN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"restaure",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"20MP et 10MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"toutles 3 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_PRECISION: MLV_draw_adapted_text_box_with_font(520,370,"POTION_PRECISION",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"Augmente la",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"probabilité d'attaque",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"critique de",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"5pct-15pct",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,520,"pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_EXP: MLV_draw_adapted_text_box_with_font(520,370,"POTION_EXP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"Augmente les",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"points d'exp",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"gagnés de 30prct",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"Pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		default:break;
	}
	MLV_actualise_window();
	MLV_wait_keyboard_or_mouse_or_seconds(&touche, NULL, NULL, &xmouse, &ymouse,5);	
}

void affiche_interfacetresor(int tresor, const MLV_Image * Interface, MLV_Font * police2){
	MLV_Keyboard_button touche=0;
	int xmouse=0,ymouse=0;
	
	switch(tresor){
		case EPEE: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(600,370,"EPEE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case ARMURE: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(580,370,"ARMURE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case GRIMOIRE: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(570,370,"GRIMOIRE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_MANA: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(520,370,"POTION_MANA",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);	
			MLV_draw_adapted_text_box_with_font(510,400,"restaure 10%% des MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_SOIN: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(520,370,"POTION_SOIN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"restaure 10%% des MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);	break;
		case POTION_REGEN: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(520,370,"POTION_REGEN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"restaure",	police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"20MP et 10MP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"tout les 3 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			break;
		case POTION_PRECISION: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(520,370,"POTION_PRECISION",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"Augmente la",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"probabilité d'attaque",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"critique de",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"5pct-15pct",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,520,"pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			break;
		case POTION_EXP: MLV_draw_image(Interface,488,338);
			MLV_draw_adapted_text_box_with_font(520,370,"POTION_EXP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,400,"Augmente les",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,430,"points d'exp",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,460,"gagnés de 30prct",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			MLV_draw_adapted_text_box_with_font(510,490,"Pendant 30 tours",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
			break;
		case VIDE: break;
		default:break;
	}
	MLV_actualise_window();
	MLV_wait_keyboard_or_mouse_or_seconds(&touche, NULL, NULL, &xmouse, &ymouse,5);		
}

void click_item(int x, int y,Personnage * p,Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2){
	if( x >= 460 && y >= 773  && x <= 515 && y <= 823){
		utilise_potion(inventaire,p,0);
		if(inventaire[0]->type_objet != VIDE && inventaire[0]->type_objet != ARMURE && inventaire[0]->type_objet != EPEE && inventaire[0]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,0);
			supprime_item_inventaire(inventaire,0);
		}
	}
	if( x >= 523 && y >= 773  && x <= 578 && y <= 823){
		utilise_potion(inventaire,p,1);
		if(inventaire[1]->type_objet != VIDE && inventaire[1]->type_objet != ARMURE && inventaire[1]->type_objet != EPEE && inventaire[1]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,1);
			supprime_item_inventaire(inventaire,1);
		}
	}
	if( x >= 587 && y >= 773  && x <= 642 && y <= 823){
		utilise_potion(inventaire,p,2);
		if(inventaire[2]->type_objet != VIDE && inventaire[2]->type_objet != ARMURE && inventaire[2]->type_objet != EPEE && inventaire[2]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,2);
			supprime_item_inventaire(inventaire,2);
		}
	}
	if(x >= 652 && y >= 773  && x <= 706 && y <= 823){
		utilise_potion(inventaire,p,3);
		if(inventaire[3]->type_objet != VIDE && inventaire[3]->type_objet != ARMURE && inventaire[3]->type_objet != EPEE && inventaire[3]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,3);
			supprime_item_inventaire(inventaire,3);
		}
	}
	if(x >= 716 && y >= 773  && x <= 771 && y <= 823){
		utilise_potion(inventaire,p,4);
		if(inventaire[4]->type_objet != VIDE && inventaire[4]->type_objet != ARMURE && inventaire[4]->type_objet != EPEE && inventaire[4]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,4);
			supprime_item_inventaire(inventaire,4);
		}
	}
	if(x >= 780 && y >= 773  && x <= 837 && y <= 823){
		utilise_potion(inventaire,p,5);
		if(inventaire[5]->type_objet != VIDE && inventaire[5]->type_objet != ARMURE && inventaire[5]->type_objet != EPEE && inventaire[5]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,5);
			supprime_item_inventaire(inventaire,5);
		}
	}

	if(x >= 460 && y >= 832  && x <= 515 && y <= 880){
		utilise_potion(inventaire,p,6);
		if(inventaire[6]->type_objet != VIDE && inventaire[6]->type_objet != ARMURE && inventaire[6]->type_objet != EPEE && inventaire[6]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,6);
			supprime_item_inventaire(inventaire,6);
		}
	}
	if(x >= 523 && y >= 832  && x <= 578 && y <= 880){
		utilise_potion(inventaire,p,7);
		if(inventaire[7]->type_objet != VIDE && inventaire[7]->type_objet != ARMURE && inventaire[7]->type_objet != EPEE && inventaire[7]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,7);
			supprime_item_inventaire(inventaire,7);
		}
	}
	if(x >= 587 && y >= 832  && x <= 642 && y <= 880){
		utilise_potion(inventaire,p,8);
		if(inventaire[8]->type_objet != VIDE && inventaire[8]->type_objet != ARMURE && inventaire[8]->type_objet != EPEE && inventaire[8]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,8);
			supprime_item_inventaire(inventaire,8);
		}
	}
	if(x >= 652 && y >= 832  && x <= 706 && y <= 880){
		printf("10\n");
		utilise_potion(inventaire,p,9);
		if(inventaire[9]->type_objet != VIDE && inventaire[9]->type_objet != ARMURE && inventaire[9]->type_objet != EPEE && inventaire[9]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,9);
			supprime_item_inventaire(inventaire,9);
		}
	}
	if(x >= 716 && y >= 832  && x <= 771 && y <= 880){
		printf("11\n");
		utilise_potion(inventaire,p,10);
		if(inventaire[10]->type_objet != VIDE && inventaire[10]->type_objet != ARMURE && inventaire[10]->type_objet != EPEE && inventaire[10]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,10);
			supprime_item_inventaire(inventaire,10);
		}
	}	
	if(x >= 780 && y >= 832  && x <= 837 && y <= 880){
		printf("12\n");
		utilise_potion(inventaire,p,11);
		if(inventaire[11]->type_objet != VIDE && inventaire[11]->type_objet != ARMURE && inventaire[11]->type_objet != EPEE && inventaire[11]->type_objet != GRIMOIRE){
			affiche_interface(inventaire,Interface,police2,11);
			supprime_item_inventaire(inventaire,11);
		}
	}
}

void item_supprime_affiche(int i,const MLV_Image * Interface, MLV_Font * police2){
	MLV_Keyboard_button touche=0;
	int xmouse=0,ymouse=0;
	MLV_draw_image(Interface,488,338);
	switch(i){
		case EPEE:MLV_draw_adapted_text_box_with_font(600,370,"EPEE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case ARMURE:MLV_draw_adapted_text_box_with_font(580,370,"ARMURE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case GRIMOIRE:MLV_draw_adapted_text_box_with_font(580,370,"ARMURE",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;		
		case POTION_SOIN:MLV_draw_adapted_text_box_with_font(520,370,"POTION_SOIN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_MANA:MLV_draw_adapted_text_box_with_font(520,370,"POTION_MANA",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_REGEN:MLV_draw_adapted_text_box_with_font(520,370,"POTION_REGEN",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_EXP:MLV_draw_adapted_text_box_with_font(520,370,"POTION_EXP",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		case POTION_PRECISION:MLV_draw_adapted_text_box_with_font(520,370,"POTION_PRECISION",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);
		MLV_draw_adapted_text_box_with_font(600,400,"jeté",police2,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER);break;
		default:break;
	}
	MLV_actualise_window();
	MLV_wait_keyboard_or_mouse_or_seconds(&touche, NULL, NULL, &xmouse, &ymouse,5);	
}

void supprime_item(int x, int y,Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2){
	if( x >= 460 && y >= 773  && x <= 515 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,0),Interface,police2);
	if( x >= 523 && y >= 773  && x <= 578 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,1),Interface,police2);
	if( x >= 587 && y >= 773  && x <= 642 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,2),Interface,police2);
	if(x >= 652 && y >= 773  && x <= 706 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,3),Interface,police2);
	if(x >= 716 && y >= 773  && x <= 771 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,4),Interface,police2);
	if(x >= 780 && y >= 773  && x <= 837 && y <= 823)
		item_supprime_affiche(supprime_item_inventaire(inventaire,5),Interface,police2);
	if(x >= 460 && y >= 832  && x <= 515 && y <= 880)
		item_supprime_affiche(supprime_item_inventaire(inventaire,6),Interface,police2);
	if(x >= 523 && y >= 832  && x <= 578 && y <= 880)
		item_supprime_affiche(supprime_item_inventaire(inventaire,7),Interface,police2);
	if(x >= 587 && y >= 832  && x <= 642 && y <= 880)
		item_supprime_affiche(supprime_item_inventaire(inventaire,8),Interface,police2);
	if(x >= 652 && y >= 832  && x <= 706 && y <= 880)
		item_supprime_affiche(supprime_item_inventaire(inventaire,9),Interface,police2);
	if(x >= 716 && y >= 832  && x <= 771 && y <= 880)
		item_supprime_affiche(supprime_item_inventaire(inventaire,10),Interface,police2);
	if(x >= 780 && y >= 832  && x <= 837 && y <= 880)	
		item_supprime_affiche(supprime_item_inventaire(inventaire,11),Interface,police2);
	
}

void click_stat(int x, int y, Personnage  * p){
	if(x >= 1089 && y >= 865  && x <= 1114 && y <= 887){
		attribution_pts_atk(p);
		return;
	}
	if(x >= 1174 && y >= 865  && x <= 1200 && y <= 887){
		attribution_pts_intel(p);
		return;
	}
	if(x >= 1260 && y >= 865  && x <= 1287 && y <= 887){
		attribution_pts_def(p);
		return;
	}
}

void attaque_mele(Labyrinthe * l,Personnage * p,int * x, int * y, int * Direction){
    int tmp_hp, tmp_mp;
    tmp_hp = 20;
    tmp_mp = 10;


	if(l->floor[*x-1][*y].type == MONSTER && *Direction ==1){/*rear*/
		joueur_attaque_mele(p, l, *x-1, *y);
		if(monstrevie(l,*x-1,*y)!=0)
			monstre_attaque_mele(p,l,*x-1,*y);
		else{
			gagne_exp(p,*l,*x-1,*y);
			l->floor[*x-1][*y].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);

	}
	if(l->floor[*x][*y-1].type == MONSTER && *Direction ==2){/*right*/
		joueur_attaque_mele(p, l, *x, *y-1);
		if(monstrevie(l,*x,*y-1)!=0)
			monstre_attaque_mele(p,l,*x,*y-1);
		else{
			gagne_exp(p,*l,*x,*y-1);
			l->floor[*x][*y-1].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);
	}
	if(l->floor[*x+1][*y].type == MONSTER && *Direction ==3){/*face*/
		joueur_attaque_mele(p, l, *x+1, *y);
		if(monstrevie(l,*x+1,*y)!=0)
			monstre_attaque_mele(p,l,*x+1,*y);
		else{			
			gagne_exp(p,*l,*x+1,*y);
			l->floor[*x+1][*y].type = ROOM;
		}
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);
	}
	if(l->floor[*x][*y+1].type == MONSTER && *Direction ==4){/*left*/
		joueur_attaque_mele(p, l, *x, *y+1);
		if(monstrevie(l,*x,*y+1)!=0)
			monstre_attaque_mele(p,l,*x,*y+1);
		else{
			gagne_exp(p,*l,*x,*y+1);
			l->floor[*x][*y+1].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
	}
	p->tours_potionexp--;
	p->tours_potionprecision--; 
	p->tours_potion_regen--;
	if(p->tours_potionprecision<=0)
		p->chance_critplus=0;
	if(p->tours_potionexp<=0)
		p->boostxp=0;
	if(p->tours_potion_regen>=0){
		if (p->hp_actuel + tmp_hp > p->hp_max)
			p->hp_actuel = p->hp_max;
        if (p->mp_actuel + tmp_mp > p->mp_max)
            p->mp_actuel = p->mp_max;

        p->hp_actuel += tmp_hp;
        p->mp_actuel += tmp_mp;
    }

}

void attaque_magique(Labyrinthe * l,Personnage * p,int * x, int * y, int * Direction){
	int tmp_hp, tmp_mp;
    tmp_hp = 20;
    tmp_mp = 10;

	if(l->floor[*x-1][*y].type == MONSTER && *Direction ==1){/*rear*/
		joueur_attaque_magique(p, l, *x-1, *y);
		if(monstrevie(l,*x-1,*y)!=0)
			monstre_attaque_mele(p,l,*x-1,*y);
		else{
			gagne_exp(p,*l,*x-1,*y);
			l->floor[*x-1][*y].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);

	}
	if(l->floor[*x][*y-1].type == MONSTER && *Direction ==2){/*right*/
		joueur_attaque_magique(p, l, *x, *y-1);
		if(monstrevie(l,*x,*y-1)!=0)
			monstre_attaque_mele(p,l,*x,*y-1);
		else{			
			gagne_exp(p,*l,*x,*y-1);
			l->floor[*x][*y-1].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);
	}
	if(l->floor[*x+1][*y].type == MONSTER && *Direction ==3){/*face*/
		joueur_attaque_magique(p, l, *x+1, *y);
		if(monstrevie(l,*x+1,*y)!=0)
			monstre_attaque_mele(p,l,*x+1,*y);
		else{
			gagne_exp(p,*l,*x+1,*y);
			l->floor[*x+1][*y].type = ROOM;
		}
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x][*y+1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y+1);
	}
	if(l->floor[*x][*y+1].type == MONSTER && *Direction ==4){/*left*/
		joueur_attaque_magique(p, l, *x, *y+1);
		if(monstrevie(l,*x,*y+1)!=0){
			monstre_attaque_mele(p,l,*x,*y+1);

		}
		else{
			gagne_exp(p,*l,*x,*y+1);
			l->floor[*x][*y+1].type = ROOM;
		}
		if(l->floor[*x+1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x+1,*y);
		if(l->floor[*x][*y-1].type == MONSTER)
			monstre_attaque_mele(p,l,*x,*y-1);
		if(l->floor[*x-1][*y].type == MONSTER)
			monstre_attaque_mele(p,l,*x-1,*y);
	}
	p->tours_potionexp--;
	p->tours_potionprecision--; 
	p->tours_potion_regen--;
	if(p->tours_potionprecision<=0)
		p->chance_critplus=0;
	if(p->tours_potionexp<=0)
		p->boostxp=0;
	if(p->tours_potion_regen>=0){
		if (p->hp_actuel + tmp_hp > p->hp_max)
			p->hp_actuel = p->hp_max;
        if (p->mp_actuel + tmp_mp > p->mp_max)
            p->mp_actuel = p->mp_max;

        p->hp_actuel += tmp_hp;
        p->mp_actuel += tmp_mp;
    }

}

int Action(Labyrinthe * l,int * x, int * y,int * Direction, int * mouse, MLV_Music * bgm, Personnage * p, Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2){
	MLV_Keyboard_button touche=0;
	int item;
    int xmouse=0,ymouse=0;
    int tmp_hp, tmp_mp;
    tmp_hp = 20;
    tmp_mp = 10;

	MLV_wait_keyboard_or_mouse(&touche, NULL, NULL, &xmouse, &ymouse);
	if(xmouse >= HEIGHT - 75 && xmouse <= HEIGHT-25 && ymouse <= 150 && ymouse >= 100){
		sound_mod(xmouse,ymouse,mouse, bgm);	
		return 0;
	}
	if(xmouse >= HEIGHT - 70 && xmouse <= HEIGHT - 30 && ymouse <=75 && ymouse >=25){
		printf("saved\n");
		return 20;
	}
	if(xmouse >= 460 && xmouse <= 833 && ymouse >= 773 && ymouse <= 880){
		click_item(xmouse,ymouse,p,inventaire,Interface,police2);		
		return 0;
	}
	if(xmouse >= 1032 && xmouse <= 1292 && ymouse >= 834 && ymouse <= 895 ){
		click_stat(xmouse,ymouse,p);
		return 0;
	}


	switch(touche){

		/*Directions de deplacement*/
		case MLV_KEYBOARD_z:
		if(l->floor[*x - 1][*y].type != WALL && l->floor[*x - 1][*y].type != MONSTER){
			*Direction = 1;
			*x -= 1;
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 1;
		break;
		case MLV_KEYBOARD_UP: 
		if(l->floor[*x - 1][*y].type != WALL && l->floor[*x - 1][*y].type != MONSTER){
			*Direction = 1;
			*x -= 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}	
		else
			*Direction = 1;
		break;
		case MLV_KEYBOARD_q: 
		if(l->floor[*x][*y - 1].type != WALL && l->floor[*x][*y - 1].type != MONSTER) {
			*Direction = 2;
			*y -= 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 2;
		break;
		case MLV_KEYBOARD_LEFT:
		if(l->floor[*x][*y - 1].type != WALL && l->floor[*x][*y - 1].type != MONSTER) {
			*Direction = 2;
			*y -= 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 2;
		break;
		case MLV_KEYBOARD_s: 
		if(l->floor[*x + 1][*y].type != WALL && l->floor[*x + 1][*y].type != MONSTER) {
			*Direction = 3;
			*x +=1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 3;
		break;
		case MLV_KEYBOARD_DOWN: 
		if(l->floor[*x + 1][*y].type != WALL && l->floor[*x + 1][*y].type != MONSTER) {
			*Direction = 3;
			*x += 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 3;
		break;
		case MLV_KEYBOARD_d: 
		if(l->floor[*x][*y + 1].type != WALL && l->floor[*x][*y + 1].type != MONSTER) {
			*Direction = 4;
			*y += 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 4;

		break;
		case MLV_KEYBOARD_RIGHT: 
		if(l->floor[*x][*y + 1].type != WALL && l->floor[*x][*y + 1].type != MONSTER) {
			*Direction = 4;
			*y += 1; 
			p->tours_potionexp--;
			p->tours_potionprecision--; 
			p->tours_potion_regen--;
			if(p->tours_potionprecision<=0)
				p->chance_critplus=0;
			if(p->tours_potionexp<=0)
				p->boostxp=0;
			if(p->tours_potion_regen>=0){
				if (p->hp_actuel + tmp_hp > p->hp_max)
					p->hp_actuel = p->hp_max;
		        if (p->mp_actuel + tmp_mp > p->mp_max)
		            p->mp_actuel = p->mp_max;

		        p->hp_actuel += tmp_hp;
		        p->mp_actuel += tmp_mp;
			}
		}
		else
			*Direction = 4;
		break;

		case MLV_KEYBOARD_a:
			if(l->floor[*x][*y].type == STAIR_UP){

				printf("Monté\n");
				return 1;
			}
			else if(l->floor[*x][*y].type == STAIR_DOWN){

				printf("déscente\n");
				return 2;
			}

			else if(l->floor[*x][*y].type == TREASURE){
				if((item = ouvre_tresor(inventaire,0))!= -1){
					affiche_interfacetresor(item,Interface,police2);
					l->floor[*x][*y].type = TREASUREO;
				}
			}break;
		case MLV_KEYBOARD_x:
				MLV_wait_keyboard_or_mouse(&touche, NULL, NULL, &xmouse, &ymouse);
				if(xmouse >= 460 && xmouse <= 833 && ymouse >= 773 && ymouse <= 880){
					supprime_item(xmouse,ymouse,inventaire,Interface,police2);
				}break;
		case MLV_KEYBOARD_e:
			attaque_mele(l,p,x,y,Direction);
			break;

		case MLV_KEYBOARD_r:
			attaque_magique(l,p,x,y,Direction);
			break;

		default:Action(l, x, y, Direction, mouse, bgm,p,inventaire,Interface,police2);
	}
	return 0;
}

void animationUp(const MLV_Image * Up, const MLV_Image * Up1, const MLV_Image * Up2, 
	const MLV_Image * Up3, const MLV_Image * Up4, const MLV_Image * Up5, 
	int niveau, MLV_Font * Policeniveau){
	MLV_draw_image(Up,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up1,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up2,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up3,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up4,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up5,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Up,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau-1,niveau);	
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

}

void animationDown(const MLV_Image * Down, const MLV_Image * Down1, const MLV_Image * Down2, 
	const MLV_Image * Down3, const MLV_Image * Down4, const MLV_Image * Down5 , 
	int niveau, MLV_Font * Policeniveau){
	MLV_draw_image(Down,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down1,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down2,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down3,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down4,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down5,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

	MLV_draw_image(Down,0,0);
	MLV_draw_adapted_text_box_with_font(900,50,"Niveau - %d\n    Niveau - %d",Policeniveau,1,MLV_ALPHA_TRANSPARENT,MLV_COLOR_DARK_SLATE_BLUE,MLV_ALPHA_TRANSPARENT,MLV_TEXT_CENTER,niveau,niveau + 1);
	MLV_wait_milliseconds(200);
	MLV_actualise_window();

}


int EcranTitre(const MLV_Image * Titre, const MLV_Image * Jouer, 
	const MLV_Image * Charger, const MLV_Image * Quitter, 
	const MLV_Image * Sound, const MLV_Image * NoSound, MLV_Music * bgmtitle, int * music){
	int x,y;
	MLV_draw_image(Titre,0,0);
	MLV_draw_image(Jouer,490,369);
	MLV_draw_image(Charger,490,542);
	MLV_draw_image(Quitter,490,721);
	if(*music==1)
		MLV_draw_image(Sound, HEIGHT - 75, 25);
	else
		MLV_draw_image(NoSound, HEIGHT - 75, 25);
	MLV_actualise_window();
	MLV_wait_mouse(&x,&y);
	if(x >= HEIGHT - 70 && x <= HEIGHT - 30 && y <= 75 && y >= 25){
		if(*music == 0 ){
			bgmtitle = MLV_load_music("src/sound/BGMTitle.mp3");
			MLV_play_music(bgmtitle,3.0,-1);
			*music =1;
		}
		else if(*music == 1){
			MLV_stop_music();
			*music = 0;
		}
	}
		
	if(x >= 490 && x <= 811 && y >= 369 && y <= 484)
		return 1;
	else if(x >= 490 && x <= 811 && y >= 542 && y <= 661)
		return 2;
	else if(x >= 490 && x <= 811 && y >= 721 && y <= 840)
		return 0;
	else
		return EcranTitre(Titre, Jouer, Charger, Quitter, Sound, NoSound, bgmtitle,music);
}


int DisplayTitle(){
	int act_ecran=0;
	int music = 1;
	
	MLV_Music * bgmtitle = MLV_load_music("src/sound/BGMTitle.mp3");
	MLV_Image * Titre = MLV_load_image("src/Sprite/Other/Titre.png");

	MLV_Image * Jouer = MLV_load_image("src/Sprite/hover/Jouer.png");
	MLV_Image * Charger = MLV_load_image("src/Sprite/hover/Charger.png");
	MLV_Image * Quitter = MLV_load_image("src/Sprite/hover/Quitter.png");
	
	MLV_Image * Sound = MLV_load_image("src/Sprite/Other/sound.png");
	MLV_Image * NoSound = MLV_load_image("src/Sprite/Other/nosound.png");

	

	MLV_resize_image(Sound, 50, 50);
	MLV_resize_image(NoSound, 50, 50);
	MLV_play_music(bgmtitle,3.0,-1);


/*Ecran Titre*/	
	act_ecran = EcranTitre(Titre, Jouer, Charger, Quitter, Sound, NoSound, bgmtitle, &music);
	MLV_stop_music();
	MLV_free_music(bgmtitle);
	MLV_free_image(Titre);
	MLV_free_image(Jouer);
	MLV_free_image(Charger);
	MLV_free_image(Quitter);
	MLV_free_image(Sound);
	MLV_free_image(NoSound);
	return act_ecran;
	
}