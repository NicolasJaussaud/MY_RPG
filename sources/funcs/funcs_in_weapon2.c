/*
** EPITECH PROJECT, 2018
** funcs_in_weapon
** File description:
** funcs_in_weapon
*/

#include "my.h"

void 				weapon_buttonselect(all_t *all)
{
	int tmpweapon = all->inv.weapon_select;

	for (int a = 0; a != 11; a++) {
		if (all->inv.tabweapon[a].select == 1) {
			all->inv.tabweapon[a].draw = 0;
			all->inv.weapon_select = a;
			all->inv.tabweapon[tmpweapon].draw = 1;
		}
	}
	for (int i = 0; i != 11; i++)
		all->inv.tabweapon[i].select = 0;
}