/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** camera_down.c
*/

#include "my.h"

void 				camera_move_down_1(all_t *all, object_t *tmp,
shot_t *tmp_s, mob_t *mob)
{
	while (tmp != NULL) {
		if (NOT_MOVABLE_WITH_CAMERA) {
			tmp->pos.y += all->player.speed_w;
			sfSprite_setPosition(tmp->sprite, tmp->pos);
		}
		tmp = tmp->next;
	}
	while (tmp_s != NULL) {
		tmp_s->pos.y += all->player.speed_w;
		sfSprite_setPosition(tmp_s->sprite, tmp_s->pos);
		tmp_s = tmp_s->next;
	}
	while (mob) {
		mob->pos.y += all->player.speed_w;
		sfSprite_setPosition(mob->sprite, mob->pos);
		mob = mob->next;
	}
}

void 				camera_move_down_2(all_t *all, button_t *btn,
text_t *txt)
{
	while (btn) {
		if (BTN_MOVABLE_CAM) {
			btn->pos.y += all->player.speed_w;
			sfRectangleShape_setPosition(btn->shape, btn->pos);
		}
		btn = btn->next;
	}
	while (txt) {
		if (txt->type == TP_TXT) {
			txt->pos.y += all->player.speed_w;
			sfText_setPosition(txt->text, txt->pos);
		}
		txt = txt->next;
	}
}

void 				camera_move_down(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;
	shot_t *tmp_s = all->shots;
	mob_t *mob = all->scenes[all->current_scene].mob;
	button_t *btn = all->scenes[all->current_scene].btn;
	text_t *txt = all->scenes[all->current_scene].txt;

	if (all->player.walking == 1) {
		camera_move_down_1(all, tmp, tmp_s, mob);
		camera_move_down_2(all, btn, txt);
	}
}
