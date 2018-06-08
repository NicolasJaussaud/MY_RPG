/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main_clock.c
*/

#include "my.h"

my_clock_t 			create_clock(void)
{
	my_clock_t my_clock;

	my_clock.clock = sfClock_create();
	my_clock.time = sfClock_getElapsedTime(my_clock.clock);
	my_clock.n = 0;
	my_clock.n2 = 0;
	my_clock.seconds = 0;
	return (my_clock);
}

void				main_clock_management(all_t *all)
{
	all->clock.time = sfClock_getElapsedTime(all->clock.clock);
	all->clock.seconds = all->clock.time.microseconds / 1000000.0;
	if (all->clock.seconds > 0.001) {
		all->clock.n += 1;
		all->clock.n2 += 1;
		sfClock_restart(all->clock.clock);
	}
}