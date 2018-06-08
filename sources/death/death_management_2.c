/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** death_management.c
*/

#include "my.h"

void 				reset_pos_player_in_labo(all_t *all)
{
	for (object_t *obj = all->scenes[12].obj; obj; obj = obj->next) {
		if (obj->type == PLAYER) {
			obj->pos.x = 500;
			obj->pos.y = 500;
			sfSprite_setPosition(obj->sprite, obj->pos);
		}
	}
}

void 				reset_player_and_bg(all_t *all,
object_t **player, object_t **bg)
{
	for (; (*player) && (*player)->type != PLAYER;
	(*player) = (*player)->next);
	for (; (*bg) && (*bg)->type != BG; (*bg) = (*bg)->next);
	go_to_scene_11(all);
	all->player.health = 100;
	all->player.drink = 100;
	all->player.food = 100;
	(*player)->pos.x = 360;
	(*player)->pos.y = 700;
	sfSprite_setPosition((*player)->sprite, (*player)->pos);
	(*bg)->pos.x = 0;
	(*bg)->pos.y = -3000;
	sfSprite_setPosition((*bg)->sprite, (*bg)->pos);
}

void 				reset_obj_core(all_t *all, int x, int y,
object_t **obj)
{
	if (all->map.map[y][x] == 1) {
		if ((*obj)->type == OBJ) {
			(*obj)->pos.x = x * 32;
			(*obj)->pos.y = y * 32 - 3000;
			sfSprite_setPosition((*obj)->sprite, (*obj)->pos);
			(*obj) = (*obj)->next;
		}
	}
}