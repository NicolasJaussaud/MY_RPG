/*
** EPITECH PROJECT, 2018
** funcs_inventory
** File description:
** funcs_inventory
*/

#include "my.h"

void 				inventory_use(all_t *all)
{
	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].select == 1
		&& all->inv.tabfood[i].nb > 0 &&
		all->player.drink < 100 &&
		all->player.food < 100) {
			all->inv.tabfood[i].nb = all->inv.tabfood[i].nb - 1;
			switchitem(all, i);
		}
	}
}

void 				inventory_button4(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 4) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}

void 				inventory_button3(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 3) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}

void 				inventory_button2(all_t *all)
{
	int a = 0;
	int count = 0;

	for (int i = 0; i != 7; i++) {
		if (all->inv.tabfood[i].nb > 0)
			count++;
		if (count == 2) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}

void 				inventory_button1(all_t *all)
{
	int a = 0;

	for (int i = 0; i != 7; i++)
		if (all->inv.tabfood[i].nb > 0) {
			all->inv.tabfood[i].select = 1;
			a = i;
			break;
		}
	for (int i = 0; i != 7; i++)
		if (i != a)
			all->inv.tabfood[i].select = 0;
}