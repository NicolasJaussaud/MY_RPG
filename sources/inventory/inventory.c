/*
** EPITECH PROJECT, 2018
** inventory
** File description:
** inventory
*/

#include "my.h"

void inittextinv2(all_t *all, char *text, char *tmptext)
{
	my_getcharstar(all->inv.tabfood[5].nb, text);
	tmptext = my_strcat("Lait  x", text);
	sfText_setString(all->inv.text[5], tmptext);
	my_getcharstar(all->inv.tabfood[6].nb, text);
	tmptext = my_strcat("Redbull  x", text);
	sfText_setString(all->inv.text[6], tmptext);
}

void inittextinv(all_t *all)
{
	char *text = malloc(sizeof(char) * 100);
	char *tmptext = malloc(sizeof(char) * 100);

	my_getcharstar(all->inv.tabfood[0].nb, text);
	tmptext = my_strcat("Pomme  x", text);
	sfText_setString(all->inv.text[0], tmptext);
	my_getcharstar(all->inv.tabfood[1].nb, text);
	tmptext = my_strcat("Cereale  x", text);
	sfText_setString(all->inv.text[1], tmptext);
	my_getcharstar(all->inv.tabfood[2].nb, text);
	tmptext = my_strcat("Conserve  x", text);
	sfText_setString(all->inv.text[2], tmptext);
	my_getcharstar(all->inv.tabfood[3].nb, text);
	tmptext = my_strcat("Steack  x", text);
	sfText_setString(all->inv.text[3], tmptext);
	my_getcharstar(all->inv.tabfood[4].nb, text);
	tmptext = my_strcat("Eau  x", text);
	sfText_setString(all->inv.text[4], tmptext);
	inittextinv2(all, text, tmptext);
}

void displayitem(all_t *all)
{
	sfVector2f possprite = {420, 470};
	sfVector2f postext = {490, 480};
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0) {
			possprite.y = possprite.y + (55 * count);
			postext.y = postext.y + (55 * count);
			sfSprite_setPosition(all->inv.sitem[i], possprite);
			sfText_setPosition (all->inv.text[i], postext);
			sfRenderWindow_drawSprite(all->window.window,
			all->inv.sitem[i], NULL);
			sfRenderWindow_drawText(all->window.window,
			all->inv.text[i], NULL);
			count++;
			possprite.y = 470;
			postext.y = 480;
		}
	}
}

void displayinventory(all_t *all)
{
	inittextinv(all);
	displaybar(all);
	displaycoins(all);
	displayitem(all);
	displayweapon(all);
}