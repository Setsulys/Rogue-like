#ifndef __GRAPHIQUE_H__
#define __GRAPHIQUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

void resize_sprite( MLV_Image * Tool, MLV_Image * Black, MLV_Image * Inventory, 
	MLV_Image * Save, MLV_Image * Sound, MLV_Image * NoSound,
	MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp, MLV_Image * Point,
	MLV_Image *Floor, MLV_Image * RWall, MLV_Image *UWall, 
	MLV_Image * LWall, MLV_Image * Wall,MLV_Image * StairD, MLV_Image * StairU, 
	MLV_Image *Slime, MLV_Image * Bleeder, MLV_Image * Chest, MLV_Image * ChestO,
	MLV_Image * Armor, MLV_Image * Grimoire, MLV_Image * Potion, MLV_Image * Sword,
	MLV_Image * Face, MLV_Image * Rear, MLV_Image * RSide, MLV_Image * LSide,
	MLV_Image * Potion_hp, MLV_Image * Potion_mp, MLV_Image * Potion_xp,MLV_Image * Potion_precision);

void free_images(MLV_Image * Tool, MLV_Image * Black, MLV_Image * Inventory, 
	MLV_Image * Save, MLV_Image * Sound, MLV_Image * NoSound,
	MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp, MLV_Image * Point,
	MLV_Image *Floor, MLV_Image * RWall, MLV_Image *UWall, 
	MLV_Image * LWall, MLV_Image * Wall,MLV_Image * StairD, MLV_Image * StairU, 
	MLV_Image *Slime, MLV_Image * Bleeder, MLV_Image * Chest,MLV_Image * ChestO,
	MLV_Image * Armor, MLV_Image * Grimoire, MLV_Image * Potion, MLV_Image * Sword,
	MLV_Image * Face, MLV_Image * Rear, MLV_Image * RSide, MLV_Image * LSide,  MLV_Image * Interface,
	MLV_Image * Potion_hp, MLV_Image * Potion_mp, MLV_Image * Potion_xp,MLV_Image * Potion_precision);

void DisplayFloor(Labyrinthe l, const MLV_Image * floor, const MLV_Image * chest, const MLV_Image * ChestO,
	const MLV_Image * Slime, const MLV_Image * Bleeder, const MLV_Image * StairD, const MLV_Image * StairU, int x, int y);

void DisplayWall(Labyrinthe l,const MLV_Image * RWall, const MLV_Image * LWall, 
	const MLV_Image * UWall,const MLV_Image * Wall, int x,int y);

void Display_Character(Labyrinthe l,const MLV_Image * Face, const MLV_Image * Rear, 
	const MLV_Image * RSide, const MLV_Image * LSide, int Direction);

void DisplayTool(const MLV_Image * Tool,const MLV_Image * Black, 
	const MLV_Image * Inventory, const MLV_Image * Save, 
	const MLV_Image * Sound, const MLV_Image * NoSound, 
	const MLV_Image * Xp, const MLV_Image * Hp, const MLV_Image * Mp, const MLV_Image * Point,
	int mouse);

void Display_point(int xp, int xpmax, int hp, int hpmax, int mp, int mpmax, int lv,int point, int atk, int intel, int def, MLV_Font * police, MLV_Font * police2);

void Display(Labyrinthe l, const MLV_Image * Tool, const MLV_Image * Black, const MLV_Image * Inventory, 
	const MLV_Image * Save, const MLV_Image * Sound, const MLV_Image * NoSound,
	const MLV_Image * Xp, const MLV_Image * Hp, const MLV_Image * Mp, const MLV_Image * Point,
	const MLV_Image *Floor, const MLV_Image * RWall, const MLV_Image *UWall, 
	const MLV_Image * LWall, const MLV_Image * Wall, const MLV_Image * StairD, const MLV_Image * StairU,
	const MLV_Image *Slime, const MLV_Image * Bleeder, const MLV_Image * Chest, const MLV_Image * ChestO,
	const MLV_Image * Face, const MLV_Image * Rear, const MLV_Image * RSide, const MLV_Image * LSide, 
	int x, int y, int Direction, int sound);

void resize_point(MLV_Image * Xp, MLV_Image * Hp, MLV_Image * Mp, int experience, int health, int mana);

void sound_mod(int x, int y, int * mouse , MLV_Music * bgm);

void Display_item(const MLV_Image * Armor, const MLV_Image * Grimoire,  const MLV_Image * Sword, const MLV_Image * Potion, 
	const MLV_Image * Potion_hp, const MLV_Image * Potion_mp , const MLV_Image * Potion_xp,	
	const MLV_Image * Potion_precision, Objets * inventaire[SLOT_INVENTAIRE]);

void affiche_interface(Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2, int i);

void affiche_interfacetresor(int tresor, const MLV_Image * Interface, MLV_Font * police2);

void click_item(int x, int y,Personnage * p,Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2);

void item_supprime_affiche(int i,const MLV_Image * Interface, MLV_Font * police2);

void supprime_item(int x, int y,Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2);

void click_stat(int x, int y, Personnage * p);

void attaque_mele(Labyrinthe * l,Personnage * p,int * x, int * y, int * Direction);

void attaque_magique(Labyrinthe * l,Personnage * p,int * x, int * y, int * Direction);

int Action(Labyrinthe * l, int * x, int * y, int * Direction, int * mouse, MLV_Music * bgm, Personnage * p, Objets * inventaire[SLOT_INVENTAIRE], const MLV_Image * Interface, MLV_Font * police2);

void animationUp(const MLV_Image * Up, const MLV_Image * Up1, const MLV_Image * Up2, 
	const MLV_Image * Up3, const MLV_Image * Up4, const MLV_Image * Up5,
	int niveau, MLV_Font * Policeniveau);

void animationDown(const MLV_Image * Down, const MLV_Image * Down1, const MLV_Image * Down2, 
	const MLV_Image * Down3, const MLV_Image * Down4, const MLV_Image * Down5, 
	int niveau, MLV_Font * Policeniveau);

int EcranTitre(const MLV_Image * Titre, const MLV_Image * Jouer, 
	const MLV_Image * Charger, const MLV_Image * Quitter, 
	const MLV_Image * Sound, const MLV_Image * NoSound, MLV_Music * bgmtitle,int * music);

int DisplayTitle();

#endif