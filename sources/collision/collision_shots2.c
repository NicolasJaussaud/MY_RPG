/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** collision_shots.c
*/

#include "my.h"

int 			delete_hitted_shots(all_t *all)
{
	shot_t *tmp = all->shots;

	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL) {
		if (tmp->next->hit == 1) {
			free(tmp->next);
			tmp->next = tmp->next->next;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void 			create_blood_tache(all_t *all, mob_t *mob)
{
	obj_val_t ov;

	ov.display = 1;
	ov.pos = mob->pos;
	ov.rect = (sfIntRect){0, 0, 75, 64};
	ov.offset = 0;
	ov.size_max = 0;
	ov.texture = all->textures[33];
	ov.opacity = 200;
	ov.type = BLOOD;
	ov.despawn = 20;
	create_object(all, ov);
}

int 			delete_dead_zombies(all_t *all)
{
	mob_t *mob = all->scenes[all->current_scene].mob;

	if (mob == NULL)
		return (0);
	while (mob->next != NULL) {
		if (mob->next->health <= 0 && mob->next->health != -100000) {
			quest_1_management(all);
			create_blood_tache(all, mob->next);
			all->player.xp += 10;
			all->player.money += 3;
		}
		if (mob->next->health <= 0) {
			free(mob->next);
			mob->next = mob->next->next;
			return (0);
		}
		mob = mob->next;
	}
	return (1);
}