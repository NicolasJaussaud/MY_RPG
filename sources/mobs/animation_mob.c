/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animation_mob.c
*/

#include "my.h"

void 				rotation_mob(mob_t *mob)
{
	if (mob->speed.x > mob->speed.y && mob->speed.x > 0) {
		mob->rect.top = 71;
	} else if (mob->speed.x < mob->speed.y && mob->speed.y < 0) {
		mob->rect.top = 142;
	} else if (mob->speed.y > mob->speed.x && mob->speed.y > 0) {
		mob->rect.top = 0;
	} else if (mob->speed.y < mob->speed.x && mob->speed.y < 0) {
		mob->rect.top = 213;
	}
}

void 				animation_mob(all_t *all)
{
	mob_t *mob = all->scenes[all->current_scene].mob;

	while (mob) {
		if (all->clock.n % 10 == 0) {
			mob->rect.left += 31;
			if (mob->rect.left >= 92)
				mob->rect.left = 0;
		}
		rotation_mob(mob);
		sfSprite_setTextureRect(mob->sprite, mob->rect);
		mob = mob->next;
	}
}