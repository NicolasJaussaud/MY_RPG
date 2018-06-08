/*
** EPITECH PROJECT, 3018
** my_rpg_30130
** File description:
** gestion_mobs.c
*/

#include "my.h"

int 			collision_mob_obj_right(all_t *all, mob_t *mob)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (mob->pos.x + mob->rect.width + 10 > obj->pos.x &&
			mob->pos.x < obj->pos.x + obj->rect.width &&
			mob->pos.y + mob->rect.height > obj->pos.y &&
			mob->pos.y < obj->pos.y + mob->rect.height)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

int 			collision_mob_obj_left(all_t *all, mob_t *mob)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (mob->pos.x + mob->rect.width > obj->pos.x &&
			mob->pos.x < obj->pos.x + obj->rect.width + 5 &&
			mob->pos.y + mob->rect.height > obj->pos.y &&
			mob->pos.y < obj->pos.y + mob->rect.height)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

int 			collision_mob_obj_down(all_t *all, mob_t *mob)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (mob->pos.x + mob->rect.width > obj->pos.x &&
			mob->pos.x < obj->pos.x + obj->rect.width &&
			mob->pos.y + mob->rect.height + 5 > obj->pos.y &&
			mob->pos.y < obj->pos.y + mob->rect.height)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

int 			collision_mob_obj_up(all_t *all, mob_t *mob)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (mob->pos.x + mob->rect.width > obj->pos.x &&
			mob->pos.x < obj->pos.x + obj->rect.width &&
			mob->pos.y + mob->rect.height > obj->pos.y &&
			mob->pos.y < obj->pos.y + mob->rect.height + 5)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

int 			collision_mobs(all_t *all, mob_t *mob)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (mob->pos.x + mob->rect.width + 5 > obj->pos.x &&
			mob->pos.x < obj->pos.x + obj->rect.width + 5 &&
			mob->pos.y + mob->rect.height + 5 > obj->pos.y &&
			mob->pos.y < obj->pos.y + mob->rect.height + 5)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}
