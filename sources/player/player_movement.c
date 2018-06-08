/*
** EPITECH PROJECT, 2018
** my_rpg_217
** File description:
** player_movement.c
*/

#include "my.h"

void 				move_player_up(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		all->player.walking = 1;
		all->player.direction = UP;
		while (tmp != NULL) {
			if (tmp->type == PLAYER && tmp->pos.y > 180 && \
			(collision_up(tmp, all) == 0)) {
				tmp->pos.y -= all->player.speed_w;
				sfSprite_setPosition(tmp->sprite, tmp->pos);
			} else if (tmp->type == PLAYER && tmp->pos.y < 220 && \
			(collision_up(tmp, all) == 0)) {
				camera_move_down(all);
			}
			tmp = tmp->next;
		}
	}
}

void 				move_player_down(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		all->player.walking = 1;
		all->player.direction = DOWN;
		while (tmp != NULL) {
			if (tmp->type == PLAYER && tmp->pos.y < 800 && \
			(collision_down(tmp, all) == 0)) {
				tmp->pos.y += all->player.speed_w;
				sfSprite_setPosition(tmp->sprite, tmp->pos);
			} else if (tmp->type == PLAYER && tmp->pos.y > 780 \
			&& (collision_down(tmp, all) == 0)) {
				camera_move_up(all);
			}
			tmp = tmp->next;
		}
	}
}

void 				move_player_left(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		all->player.walking = 1;
		all->player.direction = LEFT;
		while (tmp != NULL) {
			if (tmp->type == PLAYER && tmp->pos.x > 400 && \
			(collision_left(tmp, all) == 0)) {
				tmp->pos.x -= all->player.speed_w;
				sfSprite_setPosition(tmp->sprite, tmp->pos);
			} else if (tmp->type == PLAYER && tmp->pos.x < 420 &&
			(collision_left(tmp, all) == 0)) {
				camera_move_right(all);
			}
			tmp = tmp->next;
		}
	}
}

void 				move_player_right(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		all->player.direction = RIGHT;
		all->player.walking = 1;
		while (tmp != NULL) {
			if (tmp->type == PLAYER && tmp->pos.x < 1520 && \
			(collision_right(tmp, all) == 0)) {
				tmp->pos.x += all->player.speed_w;
				sfSprite_setPosition(tmp->sprite, tmp->pos);
			} else if (tmp->type == PLAYER && tmp->pos.x > 1500 \
			&& (collision_right(tmp, all) == 0)) {
				camera_move_left(all);
			}
			tmp = tmp->next;
		}
	}
}

void 				player_movement(all_t *all)
{
	all->player.walking = 0;
	if (PLAYING_SCENE) {
		move_player_up(all);
		move_player_down(all);
		move_player_right(all);
		move_player_left(all);
	}
}
