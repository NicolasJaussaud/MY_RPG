/*
** EPITECH PROJECT, 2018
** inventory2
** File description:
** inventory2
*/

#include "my.h"

void displaybar2(all_t *all)
{
	sfVector2f pfood = {206, 58};
	sfVector2f pwater = {211, 101};

	sfText_setPosition(all->inv.food, pfood);
	sfText_setPosition(all->inv.water, pwater);
	sfRenderWindow_drawText(all->window.window, all->inv.food, NULL);
	sfRenderWindow_drawText(all->window.window, all->inv.water, NULL);
}

void displaybar(all_t *all)
{
	sfVector2f posfood = {26, 62};
	sfVector2f poswater = {26, 105};

	all->inv.rfood.width = 420 * all->player.food / 100;
	all->inv.rfood.height = 26;
	all->inv.rwater.width = 420 * all->player.drink / 100;
	all->inv.rwater.height = 26;
	sfSprite_setTextureRect(all->inv.sfood, all->inv.rfood);
	sfSprite_setTextureRect(all->inv.swater, all->inv.rwater);
	sfSprite_setPosition(all->inv.sfood, posfood);
	sfSprite_setPosition(all->inv.swater, poswater);
	sfRenderWindow_drawSprite(all->window.window, all->inv.sfood, NULL);
	sfRenderWindow_drawSprite(all->window.window, all->inv.swater, NULL);
	displaybar2(all);
}

void displayweapon2(all_t *all, int a, sfVector2f *possprite,
sfVector2f *postext)
{
	static int count = 0;

	if (all->inv.tabweapon[a].draw == 1) {
		possprite->y = possprite->y + (75 * count);
		postext->y = postext->y + (75 * count);
		sfSprite_setPosition(all->inv.sweapon[a], *possprite);
		sfText_setPosition (all->inv.textweapon[a], *postext);
		sfRenderWindow_drawSprite(all->window.window,
		all->inv.sweapon[a], NULL);
		sfRenderWindow_drawText(all->window.window,
		all->inv.textweapon[a], NULL);
		count++;
		possprite->y = 440;
		postext->y = 465;
	}
}

void displayweapon(all_t *all)
{
	sfVector2f possprite = {755, 440};
	sfVector2f postext = {870, 465};
	sfVector2f posselect = {1210, 550};

	for (int a = 0; a != 11; a++) {
		if (all->inv.weapon_select == a) {
			sfSprite_setPosition(all->inv.sweapon[a], posselect);
			sfRenderWindow_drawSprite(all->window.window,
			all->inv.sweapon[a], NULL);
		}
		displayweapon2(all, a, &postext, &possprite);
	}
}

void displaycoins(all_t *all)
{
	char *text = malloc(sizeof(char) * 100);
	char *tmptext = malloc(sizeof(char) * 100);
	sfVector2f postext = {1737, 55};

	my_getcharstar(all->player.money, text);
	tmptext = my_strcat(" ", text);
	sfText_setString(all->inv.textmoney, tmptext);
	sfText_setPosition (all->inv.textmoney, postext);
	sfRenderWindow_drawText(all->window.window, all->inv.textmoney, NULL);
}