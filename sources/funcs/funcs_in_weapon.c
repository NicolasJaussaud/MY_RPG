/*
** EPITECH PROJECT, 2018
** funcs_in_weapon
** File description:
** funcs_in_weapon
*/

#include "my.h"

void 				weapon_button5(all_t *all)
{
	int count = 0;
	int a = 0;

	for (int i = 0; i != 11; i++) {
		if (all->inv.tabweapon[i].draw == 1)
			count++;
		if (count == 5) {
			all->inv.tabweapon[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 11; i++)
		if (i != a)
			all->inv.tabweapon[i].select = 0;
}

void 				weapon_button4(all_t *all)
{
	int count = 0;
	int a = 0;

	for (int i = 0; i != 11; i++) {
		if (all->inv.tabweapon[i].draw == 1)
			count++;
		if (count == 4) {
			all->inv.tabweapon[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 11; i++)
		if (i != a)
			all->inv.tabweapon[i].select = 0;
}

void 				weapon_button3(all_t *all)
{
	int count = 0;
	int a = 0;

	for (int i = 0; i != 11; i++) {
		if (all->inv.tabweapon[i].draw == 1)
			count++;
		if (count == 3) {
			all->inv.tabweapon[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 11; i++)
		if (i != a)
			all->inv.tabweapon[i].select = 0;
}

void 				weapon_button2(all_t *all)
{
	int count = 0;
	int a = 0;

	for (int i = 0; i != 11; i++) {
		if (all->inv.tabweapon[i].draw == 1)
			count++;
		if (count == 2) {
			all->inv.tabweapon[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 11; i++)
		if (i != a)
			all->inv.tabweapon[i].select = 0;
}

void 				weapon_button1(all_t *all)
{
	int a = 0;

	for (int i = 0; i != 11; i++) {
		if (all->inv.tabweapon[i].draw == 1) {
			all->inv.tabweapon[i].select = 1;
			a = i;
			break;
		}
	}
	for (int i = 0; i != 11; i++)
		if (i != a)
			all->inv.tabweapon[i].select = 0;
}