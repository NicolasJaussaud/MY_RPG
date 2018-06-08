/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** dialog_management.c
*/

#include "my.h"

void 				dialog_management(all_t *all)
{
	text_t *txt = all->scenes[3].txt;

	while (txt && txt->type != DIALOGUE)
		txt = txt->next;
	if (txt->type == DIALOGUE && txt != NULL) {
		txt->str = my_strcpy(all->his.dialog[STEP].str);
		sfText_setString(txt->text, txt->str);
	}
}