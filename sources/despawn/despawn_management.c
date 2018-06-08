/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** despawn.c
*/

#include "my.h"


void 				despawn_management(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	while (tmp->next) {
		if (all->clock.n % 10 == 0 && tmp->next->type == BLOOD)
			tmp->next->spawned += 1;
		if (tmp->next->spawned >= tmp->next->despawn
		&& tmp->next->type == BLOOD) {
			free(tmp->next);
			tmp->next = tmp->next->next;
			return;
		}
		tmp = tmp->next;
	}
}
