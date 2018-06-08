/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** collision_management.c
*/

#include "my.h"

int 				collision_left(object_t *player, all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj->next;

	while (tmp != NULL) {
		if (tmp->type == OBJ) {
			if (player->pos.x + player->rect.width >
			tmp->pos.x && player->pos.x - all->player.speed_w <
			tmp->pos.x + tmp->rect.width &&
			player->pos.y + player->rect.height >
			tmp->pos.y && player->pos.y < tmp->pos.y +
			tmp->rect.height)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 				collision_right(object_t *player, all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj->next;

	while (tmp != NULL) {
		if (tmp->type == OBJ) {
			if (player->pos.x + all->player.speed_w +
			player->rect.width > tmp->pos.x && player->pos.x <
			tmp->pos.x + tmp->rect.width &&
			player->pos.y + player->rect.height > tmp->pos.y &&
			player->pos.y < tmp->pos.y + tmp->rect.height)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 				collision_up(object_t *player, all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj->next;

	while (tmp != NULL) {
		if (tmp->type == OBJ) {
			if (player->pos.x + player->rect.width > tmp->pos.x &&
			player->pos.x < tmp->pos.x + tmp->rect.width &&
			player->pos.y + player->rect.height > tmp->pos.y &&
			player->pos.y - all->player.speed_w < tmp->pos.y +
			tmp->rect.height)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 				collision_down(object_t *player, all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj->next;

	while (tmp != NULL) {
		if (tmp->type == OBJ) {
			if (player->pos.x + player->rect.width > tmp->pos.x &&
			player->pos.x < tmp->pos.x + tmp->rect.width &&
			player->pos.y + all->player.speed_w +
			player->rect.height > tmp->pos.y && player->pos.y <
			tmp->pos.y + tmp->rect.height)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}