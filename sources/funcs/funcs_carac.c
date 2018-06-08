/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** funcs_carac.c
*/

#include "my.h"

void 				add_agility(all_t *all)
{
	if (all->player.stat.to_share > 0) {
		all->player.stat.agility++;
		all->player.stat.to_share--;
	}
}

void 				add_hunger(all_t *all)
{
	if (all->player.stat.to_share > 0) {
		all->player.stat.hunger++;
		all->player.stat.to_share--;
	}
}

void 				add_thirst(all_t *all)
{
	if (all->player.stat.to_share > 0) {
		all->player.stat.thirst++;
		all->player.stat.to_share--;
	}
}

void 				add_precision(all_t *all)
{
	if (all->player.stat.to_share > 0) {
		all->player.stat.precision++;
		all->player.stat.to_share--;
	}
}