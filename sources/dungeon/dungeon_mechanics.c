/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon_mechanics.c
*/

#include "my.h"

int				there_is_zombie(all_t *all)
{
	mob_t *mob = all->scenes[all->current_scene].mob->next;

	if (mob == NULL)
		return (0);
	return (1);
}

void 				display_kaz(all_t *all)
{
	object_t *kaz = all->scenes[all->current_scene].obj;

	while (kaz) {
		if (kaz->type == KAZ) {
			kaz->display = 1;
			kaz->despawn = 200;
		}
		kaz = kaz->next;
	}
}

void 				display_recup_obj(all_t *all)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == RECUP_OBJ) {
			obj->display = 1;
			obj->despawn = 200;
		}
		obj = obj->next;
	}
}

void 				obj_recup_management(all_t *all)
{
	object_t *obj_recup = all->scenes[all->current_scene].obj;

	while (obj_recup) {
		if (obj_recup->type == RECUP_OBJ && obj_recup->despawn > 0) {
			obj_recup->despawn--;
		}
		if (obj_recup->type == RECUP_OBJ && obj_recup->despawn == 0) {
			obj_recup->display = 0;
		}
		obj_recup = obj_recup->next;
	}
}

void 				kaz_management(all_t *all)
{
	object_t *kaz = all->scenes[all->current_scene].obj;

	while (kaz) {
		if (kaz->type == KAZ && kaz->despawn > 0) {
			kaz->despawn--;
		}
		if (kaz->type == KAZ && kaz->despawn == 0) {
			kaz->display = 0;
		}
		kaz = kaz->next;
	}
}