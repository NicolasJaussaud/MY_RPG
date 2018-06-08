/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon_mechanics.c
*/

#include "my.h"

void 				reset_obj_dungeon(all_t *all, int scene)
{
	object_t *obj = all->scenes[scene].obj;

	while (obj) {
		obj->pos = obj->old_pos;
		sfSprite_setPosition(obj->sprite, obj->pos);
		obj = obj->next;
	}
}

void 				reset_btn_dungeon(all_t *all, int scene)
{
	button_t *btn = all->scenes[scene].btn;

	while (btn) {
		btn->pos = btn->old_pos;
		sfRectangleShape_setPosition(btn->shape, btn->pos);
		btn = btn->next;
	}
}

void 				reset_txt_dungeon(all_t *all, int scene)
{
	text_t *txt = all->scenes[scene].txt;

	while (txt) {
		if (txt->type != MONEY && txt->type != TXT_CARAC) {
			txt->pos = txt->old_pos;
			sfText_setPosition(txt->text, txt->pos);
		}
		txt = txt->next;
	}
}

void 				kill_all_zombies_dungeon(all_t *all, int scene)
{
	mob_t *mob = all->scenes[scene].mob;

	while (mob) {
		mob->health = -100000;
		mob = mob->next;
	}
}

void 				reset_scene_dungeon(all_t *all, int scene)
{
	reset_obj_dungeon(all, scene);
	reset_btn_dungeon(all, scene);
	reset_txt_dungeon(all, scene);
	kill_all_zombies_dungeon(all, scene);
}