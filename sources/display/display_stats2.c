/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_stats.c
*/

#include "my.h"

void 				display_agility(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == AGILITY) {
			my_getcharstar(all->player.stat.agility, tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}

void 				display_thirst(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == THIRST) {
			my_getcharstar(all->player.stat.thirst, tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}

void 				display_precision(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == PRECISION) {
			my_getcharstar(all->player.stat.stat_precision, \
			tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}
