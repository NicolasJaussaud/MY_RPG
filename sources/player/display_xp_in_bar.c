/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_xp_in_bar.c
*/

#include "my.h"

void 				display_xp_in_bar(all_t *all)
{
	text_t *tmp = all->scenes[2].txt;
	char *s = malloc(sizeof(char) * 1000);

	while (tmp != NULL) {
		if (tmp->type == TXT_CARAC)
			break;
		tmp = tmp->next;
	}

	my_getcharstar(all->player.xp, s);
	tmp->str = my_strcpy(s);
	tmp->str = my_strcat(tmp->str, "/");
	my_getcharstar(all->info.next_lvl_xp, s);
	tmp->str = my_strcat(tmp->str, s);
	tmp->str = my_strcat(tmp->str, " xp");
	sfText_setString(tmp->text, tmp->str);
}