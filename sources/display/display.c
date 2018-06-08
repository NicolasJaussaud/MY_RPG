/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display.c
*/

#include "my.h"

void 			display_inventory_shop(all_t *all)
{
	if (all->current_scene == 2)
		displayinventory(all);
	if (all->current_scene == 4)
		displayshop(all);
	if (all->current_scene == 5)
		displayshop2(all);
	if (all->current_scene == 6)
		displayshop3(all);
}

void 			display_txt_hud(all_t *all)
{
	text_t *txt = all->scenes[all->current_scene].txt;

	while (txt) {
		if ((txt->type == MONEY || txt->type == TXT_CARAC ||
		txt->type == QUEST_1) && txt->display == 1) {
			sfRenderWindow_drawText(all->window.window,
			txt->text, NULL);
		}
		txt = txt->next;
	}
}

void 			display_warnings(all_t *all)
{
	object_t *tmp = all->scenes[1].obj;

	while (tmp) {
		if ((tmp->type == YOU_QUEST || tmp->type == NOT_YET_DUNGEON)
		&& tmp->display == 1) {
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
			break;
		}
		tmp = tmp->next;
	}
}

void 			display_scenes(all_t *all)
{
	if (CST != GAME && CST != HOSPITAL && CST != PHARMACIE)
		display_shot(all);
	display_obj(all);
	display_btn(all);
	display_txt(all);
	if (CST == GAME || CST == HOSPITAL || CST == PHARMACIE)
		display_shot(all);
	display_stats(all);
	display_mobs(all);
	display_halo(all);
	display_player(all);
	display_rain(all);
	display_inventory_shop(all);
	display_hud(all);
	display_txt_hud(all);
	display_minimap(all);
	display_warnings(all);
	sfRenderWindow_display(all->window.window);
}
