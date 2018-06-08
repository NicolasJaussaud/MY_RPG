/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** spawning_management.c
*/

#include "my.h"

void 				spawning_management(all_t *all)
{
	if (all->clock.n % 100 == 0 && all->current_scene == 1)
		create_mobs_random(all);
}
