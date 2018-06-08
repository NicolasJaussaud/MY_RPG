/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** create_history.c
*/

#include "my.h"

void 			create_history_2(history_t *his)
{
	his->dialog[1].str = DIAL_1;
	his->dialog[3].str = DIAL_2;
	his->dialog[5].str = DIAL_3;
	his->dialog[7].str = DIAL_4;
	his->dialog[9].str = DIAL_5;
	his->dialog[11].str = DIAL_6;
	his->dialog[13].str = DIAL_7;
}

history_t 		create_history(void)
{
	history_t his;

	his.step_h = 0;
	his.quest_1 = 0;
	his.dialog = malloc(sizeof(dialog_t) * 100);
	create_history_2(&his);
	his.dialog[0].str = DIAL_1;
	his.dialog[2].str = DIAL_2;
	his.dialog[4].str = DIAL_3;
	his.dialog[6].str = DIAL_4;
	his.dialog[8].str = DIAL_5;
	his.dialog[10].str = DIAL_6;
	his.dialog[12].str = DIAL_7;
	his.dialog[14].str = DIAL_8;
	return (his);
}