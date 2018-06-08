/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hunger_thirst.c
*/

#include "my.h"

void 				hunger_thirst(all_t *all)
{
	if (all->player.food <= 0)
		all->player.stat.stat_precision = -99;
	else
		all->player.stat.stat_precision = all->player.stat.precision;
	if (all->clock.n % 300 + (all->player.stat.hunger * 10) == 0 &&
	(PLAYING_SCENE)) {
		if (all->player.food > 0)
			all->player.food--;
	}
	if (all->clock.n % 300 + (all->player.stat.thirst * 10) == 0 &&
	(PLAYING_SCENE)) {
		if (all->player.drink > 0)
			all->player.drink--;
	}
}