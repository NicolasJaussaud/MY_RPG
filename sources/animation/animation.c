/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animation.c
*/

#include "my.h"

void 				gestion_animation_rect_core(all_t *all,
object_t *tmp)
{
	if (all->clock.n % 10 == 0) {
		tmp->rect.left += tmp->offset;
		if (tmp->rect.left >= tmp->size_max)
			tmp->rect.left = 0;
		sfSprite_setTextureRect(tmp->sprite, tmp->rect);
	}
}

void 				gestion_animation_rect(all_t *all)
{
	for (object_t *tmp = all->scenes[all->current_scene].obj; tmp;
		tmp = tmp->next)
		if (tmp->type != PLAYER && tmp->type != MINIMAP
		&& tmp->type != BG)
			gestion_animation_rect_core(all, tmp);
}