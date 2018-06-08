/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** halo_centered_on_player.c
*/

#include "my.h"

void 				halo_centered_on_player(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;
	object_t *p = all->scenes[all->current_scene].obj;

	if (CST != GAME)
		return;
	while (p) {
		if (p->type == PLAYER)
			break;
		p = p->next;
	}
	while (tmp) {
		if (tmp->type == HALO) {
			tmp->pos.x = p->pos.x - 1700;
			tmp->pos.y = p->pos.y - 1700;
			sfSprite_setPosition(tmp->sprite, tmp->pos);
		}
		tmp = tmp->next;
	}
}