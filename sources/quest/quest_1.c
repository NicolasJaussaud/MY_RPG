/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** quest_1.c
*/

#include "my.h"

void 				quest_1_management(all_t *all)
{
	if (STEP == 2)
		all->his.quest_1 += 1;
	if (all->his.quest_1 == 30 && STEP == 2)
		STEP = 3;
}

void 				display_quest_only_when_active(all_t *all)
{
	text_t *tmp = all->scenes[1].txt;

	while (tmp && tmp->type != QUEST_1)
		tmp = tmp->next;
	if (all->his.step_h == 2)
		tmp->display = 1;
	else
		tmp->display = 0;
}

void 				quest_1_display_string(all_t *all)
{
	text_t *tmp = all->scenes[1].txt;

	display_quest_only_when_active(all);
	while (tmp) {
		if (tmp->type == QUEST_1)
			break;
		tmp = tmp->next;
	}
	my_getcharstar(30 - all->his.quest_1, tmp->str);
	tmp->str = my_strcat(tmp->str, " zombies restants");
	sfText_setString(tmp->text, tmp->str);
}