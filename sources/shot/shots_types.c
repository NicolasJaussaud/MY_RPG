/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** shots_type.c
*/

#include "my.h"

void 				three_shot(all_t *all, sfVector2f speed)
{
	static int a = 0;
	static int b = 0;

	if (all->clicking == 1)
		b = 1;
	if (all->shotted_one == 0 && a < 3 && all->clock.n % \
		all->player.wp.cadence == 0 && b == 1) {
		sfMusic_play(all->sounds[7]);
		add_new_shot(all, speed);
		a++;
	}
	if (a == 3) {
		b = 0;
		a = 0;
		all->shotted_one = 1;
	}

}

void 				unlimited_shot(all_t *all, sfVector2f speed)
{
	if (all->clicking == 1 && all->clock.n % all->player.wp.cadence == 0) {
		if (all->clock.n % (all->player.wp.cadence * 3) == 0)
			sfMusic_play(all->sounds[7]);
		add_new_shot(all, speed);
	}
}

void 				one_shot(all_t *all, sfVector2f speed)
{
	if (all->shotted_one == 0 && all->clicking == 1) {
		sfMusic_play(all->sounds[8]);
		add_new_shot(all, speed);
		all->shotted_one = 1;
	}
}