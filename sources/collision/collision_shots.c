/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** collision_shots.c
*/

#include "my.h"

void 			collision_shots_core_obj(shot_t *tmp_s, object_t *tmp_o)
{
	while (tmp_o != NULL) {
		if (tmp_s->pos.x > tmp_o->pos.x && tmp_s->pos.x <
		tmp_o->pos.x + tmp_o->rect.width &&
		tmp_s->pos.y > tmp_o->pos.y && tmp_s->pos.y < tmp_o->pos.y +
		tmp_o->rect.height) {
			if (tmp_o->type == OBJ) {
				tmp_s->hit = 1;
			}
		}
		tmp_o = tmp_o->next;
	}
}

void 			collision_shots_core_mob(all_t *all, shot_t *tmp_s,
mob_t *mob)
{
	while (mob != NULL) {
		if (tmp_s->pos.x > mob->pos.x && tmp_s->pos.x < mob->pos.x +
		mob->rect.width) {
			if (tmp_s->pos.y > mob->pos.y && tmp_s->pos.y <
			mob->pos.y + mob->rect.height
				&& tmp_s->scene == all->current_scene) {
				tmp_s->hit = 1;
				mob->health -= all->player.wp.degat;
				break;
			}
		}
		mob = mob->next;
	}
}

void 			collision_shots(all_t *all)
{
	object_t *tmp_o = all->scenes[all->current_scene].obj;
	shot_t *tmp_s = all->shots;
	mob_t *mob = all->scenes[all->current_scene].mob->next;

	if (NOT_PLAYING_SCENE)
		return;
	while (tmp_s != NULL) {
		collision_shots_core_obj(tmp_s, tmp_o);
		collision_shots_core_mob(all, tmp_s, mob);
		tmp_s = tmp_s->next;
	}
}
