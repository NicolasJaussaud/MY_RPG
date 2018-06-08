/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** .c
*/

#include "my.h"

void				search_quest_2(all_t *all)
{
	STEP += 1;
	all->old_scene = all->current_scene;
	all->current_scene = 22;
}

void				quest_2_management(all_t *all)
{
	button_t *qo = all->scenes[1].btn;
	button_t *qt = all->scenes[1].btn;
	button_t *qth = all->scenes[1].btn;

	for (; qo && qo->type != Q21; qo = qo->next);
	for (; qt && qt->type != Q22; qt = qt->next);
	for (; qth && qth->type != Q23; qth = qth->next);

	if (STEP == 6) {
		qo->display = 1;
	} else
		qo->display = 0;
	if (STEP == 8) {
		qt->display = 1;
	} else
		qt->display = 0;
	if (STEP == 10) {
		qth->display = 1;
	} else
		qth->display = 0;
}