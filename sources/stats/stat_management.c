/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** stat_mamagement.c
*/

#include "my.h"

void 				stat_management(all_t *all)
{
	if (all->player.food == 0)
		all->player.speed_w = 2.3;
	else
		all->player.speed_w = all->player.speed_w_base +
		(all->player.stat.agility / 50);
}