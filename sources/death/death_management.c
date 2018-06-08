/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** death_management.c
*/

#include "my.h"

void 				reset_obj(all_t *all)
{
	object_t *obj = all->scenes[1].obj;

	while (obj->type != OBJ && obj)
		obj = obj->next;

	for (int y = 0; y < all->map.len_y; y++) {
		for (int x = 0; x < all->map.len_x; x++) {
			reset_obj_core(all, x ,y, &obj);
		}
	}
}

void 				reset_btn_txt(all_t *all)
{
	button_t *btn = all->scenes[1].btn;
	text_t *txt = all->scenes[1].txt;

	while (txt) {
		if (txt->type != MONEY && txt->type != TXT_CARAC &&
		txt->type != QUEST_1) {
			txt->pos = txt->old_pos;
			txt->pos.y -= 3000;
			sfText_setPosition(txt->text, txt->pos);
		}
		txt = txt->next;
	}
	while (btn) {
		btn->pos = btn->old_pos;
		btn->pos.y -= 3000;
		sfRectangleShape_setPosition(btn->shape, btn->pos);
		btn = btn->next;
	}
}

void 				kill_all_zombies(all_t *all)
{
	for (mob_t *mob = all->scenes[1].mob; mob; mob = mob->next)
		mob->health = -100000;
}


void 				death_management(all_t *all)
{
	object_t *player = all->scenes[1].obj;
	object_t *bg = all->scenes[1].obj;

	if (all->player.health <= 0) {
		sfMusic_play(all->sounds[6]);
		reset_obj(all);
		reset_btn_txt(all);
		kill_all_zombies(all);
		reset_pos_player_in_labo(all);
		reset_player_and_bg(all, &player, &bg);
	}
}
