/*
** EPITECH PROJECT, 2018
** create_struct2
** File description:
** create_struct2
*/

#include "my.h"

void inittext(all_t *all)
{
	all->inv.font = sfFont_createFromFile("assets/fonts/ZOMBIE.TTF");
	for (int i = 0; i != 7; i++)
		all->inv.text[i] = sfText_create();
	for (int i = 0; i != 7; i++) {
		sfText_setFont(all->inv.text[i], all->inv.font);
		sfText_setCharacterSize(all->inv.text[i], 25);
	}
	all->inv.textmoney = sfText_create();
	sfText_setFont(all->inv.textmoney, all->inv.font);
	sfText_setCharacterSize(all->inv.textmoney , 34);
}

void initinventory2(all_t *all)
{
	all->inv.food = sfText_create();
	all->inv.water = sfText_create();
	sfText_setFont(all->inv.food, all->inv.font);
	sfText_setFont(all->inv.water, all->inv.font);
	sfText_setCharacterSize(all->inv.food, 31);
	sfText_setCharacterSize(all->inv.water, 31);
	sfText_setString(all->inv.food, "faim");
	sfText_setString(all->inv.water, "soif");
	all->inv.sfood = sfSprite_create();
	all->inv.tfood =
	sfTexture_createFromFile("assets/imgs/inventaire/food.png", NULL);
	all->inv.swater = sfSprite_create();
	all->inv.twater =
	sfTexture_createFromFile("assets/imgs/inventaire/water.png", NULL);
	sfSprite_setTexture(all->inv.sfood, all->inv.tfood, sfTrue);
	sfSprite_setTexture(all->inv.swater, all->inv.twater, sfTrue);
}

void init_tabweapon(all_t *all)
{
	all->inv.tabweapon = malloc(sizeof(tabweapon_t*) * 11);
	for (int i = 0; i != 11; i++) {
		all->inv.tabweapon[i].draw = 0;
		all->inv.tabweapon[i].select = 0;
	}
}

void init_tab_food(all_t *all)
{
	all->inv.tabfood = malloc(sizeof(tabfood_t*) * 7);
	for (int i = 0; i != 7; i++) {
		all->inv.tabfood[i].nb = 0;
		all->inv.tabfood[i].select = 0;
	}
}