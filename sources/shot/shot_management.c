/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** shot_management.c
*/

#include "my.h"

void 				add_new_shot_core(all_t *all, shot_t *n,
object_t *obj_tmp, sfVector2f speed)
{
	n->scene = all->current_scene;
	n->sprite = sfSprite_create();
	if (all->rotation_player == 1) {
		n->pos = (sfVector2f){obj_tmp->pos.x + 42, obj_tmp->pos.y + 31};
	} else if (all->rotation_player == 0) {
		n->pos = (sfVector2f){obj_tmp->pos.x - 19, obj_tmp->pos.y + 31};
	} else if (all->rotation_player == -1) {
		n->pos = (sfVector2f){obj_tmp->pos.x + 16, obj_tmp->pos.y + 31};
	}
	n->random_pres.x = frand_a_b(RANDOM_SHOTS);
	n->random_pres.y = frand_a_b(RANDOM_SHOTS);
	n->actual_range = 0;
	n->speed = speed;
	n->hit = 0;
	sfSprite_setTexture(n->sprite, all->textures[9], sfTrue);
	sfSprite_setPosition(n->sprite, n->pos);
	n->next = NULL;
}

void 				add_new_shot(all_t *all, sfVector2f speed)
{
	shot_t *n = malloc(sizeof(*n));
	shot_t *tmp = all->shots;
	object_t *obj_tmp = all->scenes[all->current_scene].obj;

	while (obj_tmp) {
		if (obj_tmp->type == PLAYER) {
			break;
		}
		obj_tmp = obj_tmp->next;
	}
	add_new_shot_core(all, n, obj_tmp, speed);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = n;
}

void 				fire_shot(all_t *all)
{
	sfVector2f speed;

	if (CST == GAME || CST == HOSPITAL || CST == PHARMACIE) {
		speed.x = cos((180 - all->player.angle) * M_PI / 180.) * 8;
		speed.y = -sin((180 - all->player.angle) * M_PI / 180.) * 8;
		if (all->player.wp.type == UNLIMITED)
			unlimited_shot(all, speed);
		else if (all->player.wp.type == THREE)
			three_shot(all, speed);
		else if (all->player.wp.type == ONE)
			one_shot(all, speed);
	}
}

void 				shot_management(all_t *all)
{
	shot_t *tmp = all->shots;

	if (CST != GAME && CST != HOSPITAL && CST != PHARMACIE)
		return;
	while (tmp != NULL) {
		tmp->actual_range += 1;
		if (tmp->actual_range > all->player.wp.range_max)
			tmp->hit = 1;
		tmp->pos.x += tmp->speed.x + tmp->random_pres.x;
		tmp->pos.y += tmp->speed.y + tmp->random_pres.y;
		sfSprite_setPosition(tmp->sprite, tmp->pos);
		tmp = tmp->next;
	}
	collision_shots(all);
	delete_hitted_shots(all);
	delete_dead_zombies(all);
}
