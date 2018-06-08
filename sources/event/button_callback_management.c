/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** button_callback_management.c
*/

#include "my.h"

void 				button_callback_management(all_t *all)
{
	button_t *tmp = all->scenes[all->current_scene].btn;

	while (tmp != NULL) {
		if (tmp->enable == 1 && tmp->display == 1 &&
		button_is_clicked(tmp, sfMouse_getPosition((const sfWindow*)\
		all->window.window)) == 1) {
			if (tmp->type == CAR)
				tmp->enable = 0;
			tmp->callback(all);
		}
		tmp = tmp->next;
	}
}