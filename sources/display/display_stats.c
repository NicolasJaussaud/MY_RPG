/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_stats.c
*/

#include "my.h"

void 				display_hunger(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == HUNGER) {
			my_getcharstar(all->player.stat.hunger, tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}

void 				display_toshare(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == TO_SHARE) {
			my_getcharstar(all->player.stat.to_share, tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}

void 				display_plus_stats(all_t *all)
{
	button_t *tmp = all->scenes[2].btn;

	if (all->player.stat.to_share < 1) {
		while (tmp != NULL) {
			if (tmp->type == ADD_CARAC) {
				tmp->display = 0;
			}
			tmp = tmp->next;
		}
	} else if (all->player.stat.to_share >= 1) {
		while (tmp != NULL) {
			if (tmp->type == ADD_CARAC)
				tmp->display = 1;
			tmp = tmp->next;
		}
	}
}

void 				display_stats(all_t *all)
{
	if (all->current_scene == 2) {
		display_agility(all);
		display_thirst(all);
		display_precision(all);
		display_hunger(all);
		display_toshare(all);
		display_plus_stats(all);
	}
}
