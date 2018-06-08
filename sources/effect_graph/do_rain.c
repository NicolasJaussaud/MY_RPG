/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** do_rain.c
*/

#include "my.h"

void 				do_rain(all_t *all)
{
	for (object_t *tmp = all->scenes[all->current_scene].obj;
	tmp; tmp = tmp->next) {
		if (tmp->type == RAIN) {
			tmp->rect.top -= 5;
			if (tmp->rect.top <= 0)
				tmp->rect.top = 1080;
			sfSprite_setTextureRect(tmp->sprite, tmp->rect);
		}
	}
}