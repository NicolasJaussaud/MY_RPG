/*
** EPITECH PROJECT, 2018
** create_struct2
** File description:
** create_struct2
*/

#include "my.h"

void				init_texture_inventory(all_t *all)
{
	for (int i = 0; i != 7; i++)
		all->inv.sitem[i] = sfSprite_create();
	all->inv.titem[0] =
	sfTexture_createFromFile("assets/imgs/icon/apple.png", NULL);
	all->inv.titem[1] =
	sfTexture_createFromFile("assets/imgs/icon/cereal.png", NULL);
	all->inv.titem[2] =
	sfTexture_createFromFile("assets/imgs/icon/canned.png", NULL);
	all->inv.titem[3] =
	sfTexture_createFromFile("assets/imgs/icon/steak.png", NULL);
	all->inv.titem[4] =
	sfTexture_createFromFile("assets/imgs/icon/water.png", NULL);
	all->inv.titem[5] =
	sfTexture_createFromFile("assets/imgs/icon/milk.png", NULL);
	all->inv.titem[6] =
	sfTexture_createFromFile("assets/imgs/icon/redbull.png", NULL);
}

void				initinventory(all_t *all)
{
	init_tab_food(all);
	init_tabweapon(all);
	inittext(all);
	initweapon(all);
	init_texture_inventory(all);
	for (int i = 0; i != 7; i++)
		sfSprite_setTexture(all->inv.sitem[i], all->inv.titem[i],
		sfTrue);
	all->inv.weapon_select = 0;
	initinventory2(all);
}