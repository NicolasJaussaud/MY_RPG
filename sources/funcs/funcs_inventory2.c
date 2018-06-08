/*
** EPITECH PROJECT, 2018
** funcs_inventory2
** File description:
** funcs_inventory2s
*/

#include "my.h"

void				switchitem2(all_t *all, int a)
{
	switch (a) {
	case 4:
		all->player.drink = all->player.drink + 5;
		sfMusic_play(all->sounds[2]);
		break;
	case 5:
		all->player.drink = all->player.drink + 15;
		sfMusic_play(all->sounds[2]);
		break;
	case 6:
		all->player.drink = all->player.drink + 25;
		sfMusic_play(all->sounds[2]);
		break;
	}
}

void				switchitem(all_t *all, int a)
{
	switch (a) {
	case 0:
		all->player.food = all->player.food + 5;
		sfMusic_play(all->sounds[3]);
		break;
	case 1:
		all->player.food = all->player.food + 10;
		sfMusic_play(all->sounds[3]);
		break;
	case 2:
		all->player.food = all->player.food + 25;
		sfMusic_play(all->sounds[3]);
		break;
	case 3:
		all->player.food = all->player.food + 50;
		sfMusic_play(all->sounds[3]);
		break;
	}
	switchitem2(all, a);
}

void 				inventory_button7(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 7) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}

void 				inventory_button6(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 6) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}

void 				inventory_button5(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 5) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}
