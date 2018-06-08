/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** hud_management_2.c
*/

#include "my.h"

void 				life_hud_management(all_t *all)
{
	object_t *tmp;
	float h = all->player.health;
	float hm = all->player.health_max;
	float fper = (h / hm) * 100;
	int per = fper;

	if (PLAYING_SCENE) {
		tmp = all->scenes[all->current_scene].obj;
		while (tmp) {
			if (tmp->type == LIFE_BAR) {
				tmp->rect.width = per;
				if (tmp->rect.width < 0)
					tmp->rect.width = 0;
				sfSprite_setTextureRect(tmp->sprite, tmp->rect);
			}
			tmp = tmp->next;
		}
	}
}

void 				level_hud_management(all_t *all)
{
	text_t *tmp;

	if (PLAYING_SCENE || CST == NOURRITURES
	|| CST == ARMES || CST == BOISSONS) {
		tmp = all->scenes[all->current_scene].txt;
		while (tmp && tmp->type != MONEY)
			tmp = tmp->next;
		if (tmp->type == MONEY) {
			my_getcharstar(all->player.money, tmp->str);
			sfText_setString(tmp->text, tmp->str);
		}
	}
}

void 			hud_management(all_t *all)
{
	thirst_hud_management(all);
	hunger_hud_management(all);
	level_hud_management(all);
	life_hud_management(all);
	xp_hud_management(all);
}
