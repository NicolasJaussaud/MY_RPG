/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** HUD_management.c
*/

#include "my.h"

void 				thirst_hud_management(all_t *all)
{
	object_t *tmp;
	float h = all->player.drink;
	float hm = 100;
	float fper = (h / hm) * 100;
	int per = fper;

	if (PLAYING_SCENE) {
		tmp = all->scenes[all->current_scene].obj;
		while (tmp) {
			if (tmp->type == THIRST_BAR) {
				tmp->rect.width = per;
				if (tmp->rect.width < 0)
					tmp->rect.width = 0;
				sfSprite_setTextureRect(tmp->sprite, tmp->rect);
			}
			tmp = tmp->next;
		}
	}
}

void 				hunger_hud_management(all_t *all)
{
	object_t *tmp;
	float h = all->player.food;
	float hm = 100;
	float fper = (h / hm) * 100;
	int per = fper;

	if (PLAYING_SCENE) {
		tmp = all->scenes[all->current_scene].obj;
		while (tmp) {
			if (tmp->type == HUNGER_BAR) {
				tmp->rect.width = per;
				if (tmp->rect.width < 0)
					tmp->rect.width = 0;
				sfSprite_setTextureRect(tmp->sprite, tmp->rect);
			}
			tmp = tmp->next;
		}
	}
}

void 				xp_hud_management(all_t *all)
{
	object_t *tmp;
	float xp = all->player.xp;
	float nxp = all->info.next_lvl_xp;
	float fper = (xp / nxp) * 100;
	int per = fper;

	if (PLAYING_SCENE) {
		tmp = all->scenes[all->current_scene].obj;
		while (tmp) {
			if (tmp->type == XP_BAR) {
				tmp->rect.width = per;
				sfSprite_setTextureRect(tmp->sprite, tmp->rect);
			}
			tmp = tmp->next;
		}
	}
}