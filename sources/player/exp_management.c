/*
** EPITECH PROJECT, 2018
** my_rpg_2018
** File description:
** exp_management.c
*/

#include "my.h"

void 				display_xp_bar(all_t *all, int percentage)
{
	int rect_to_display = 418/100 * percentage;
	object_t *tmp = all->scenes[2].obj;
	while (tmp != NULL) {
		if (tmp->type == XP_BAR) {
			if (rect_to_display > 418)
				rect_to_display = 0;
			tmp->rect.width = rect_to_display;
			sfSprite_setTextureRect(tmp->sprite, tmp->rect);
		}
		tmp = tmp->next;
	}
}

void 				display_level_inventory(all_t *all)
{
	char *lvl = malloc(sizeof(char) * 10);
	text_t *tmp = all->scenes[2].txt;

	while (tmp != NULL) {
		if (tmp->type == LEVEL) {
			my_getcharstar(all->player.lvl, lvl);
			tmp->str = my_strcat("Level ", lvl);
			sfText_setString(tmp->text, tmp->str);
		}
		tmp = tmp->next;
	}
}

void 				exp_management(all_t *all)
{
	float percentage = 0;
	float xp = all->player.xp;
	float nxp;
	int percentage_int;

	all->info.next_lvl_xp = 150;
	for (int i = 0; i < all->player.lvl; i++)
		all->info.next_lvl_xp = all->info.next_lvl_xp *\
		all->info.cst_xp;
	nxp = all->info.next_lvl_xp;
	if (all->player.xp > all->info.next_lvl_xp) {
		all->player.lvl++;
		all->player.stat.to_share += 10;
		all->player.xp = 1;
	}
	percentage = (xp / nxp) * 100;
	percentage_int = percentage;
	display_xp_bar(all, percentage_int);
	display_xp_in_bar(all);
	display_level_inventory(all);
}