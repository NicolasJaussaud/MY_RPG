/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** animation.c
*/

#include "my.h"

void			animation_player_core(object_t *tmp)
{
	if (tmp->type == PLAYER) {
		tmp->rect.left += tmp->offset;
		if (tmp->rect.left > tmp->size_max)
			tmp->rect.left = 0;
		sfSprite_setTextureRect(tmp->sprite, tmp->rect);
	}
}

void 			animation_player(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (all->clock.n % 10 == 0 && all->player.walking == 1) {
		while (tmp != NULL) {
			animation_player_core(tmp);
			tmp = tmp->next;
		}
	}
}