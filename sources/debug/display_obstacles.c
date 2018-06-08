/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_obstacles.c
*/

#include "my.h"

void 					display_obstacles(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	while (tmp) {
		if (tmp->type == OBJ) {
			if (tmp->display == 1)
				tmp->display = 0;
			else
				tmp->display = 1;
		}
		tmp = tmp->next;
	}
}