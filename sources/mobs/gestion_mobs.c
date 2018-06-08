/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** gestion_mobs.c
*/

#include "my.h"

int 				management_bar_life_mob(all_t *all)
{
	mob_t *mob = all->scenes[all->current_scene].mob;
	float h = 0;
	float hm = 0;
	float fper = 0;
	int per = 0;

	while (mob) {
		h = mob->health;
		hm = mob->health_max;
		fper = (h / hm) * 100;
		per = fper;
		mob->rect_bar_life.width = 0.31 * per;
		sfSprite_setTextureRect(mob->bar_life, mob->rect_bar_life);
		mob->pos_bar_life.x = mob->pos.x;
		mob->pos_bar_life.y = mob->pos.y - 10;
		sfSprite_setPosition(mob->bar_life, mob->pos_bar_life);
		mob = mob->next;
	}
	return (0);
}

void 				accros_wall(all_t *all, mob_t *mob)
{
	if (mob->speed.x > 0 && collision_mob_obj_right(all, mob) == 0)
		mob->pos.x += 2;
	if (mob->speed.x < 0 && collision_mob_obj_left(all, mob) == 0)
		mob->pos.x -= 2;
	if (mob->speed.y > 0 && collision_mob_obj_down(all, mob) == 0)
		mob->pos.y += 2;
	if (mob->speed.y < 0 && collision_mob_obj_up(all, mob) == 0)
		mob->pos.y -= 2;
	sfSprite_setPosition(mob->sprite, mob->pos);
}

void				pathfinding_mob_1(mob_t *mob, sfVector2f posf,
int *angle, object_t *player)
{
	posf.x = mob->pos.x - player->pos.x;
	posf.y = mob->pos.y - player->pos.y;
	if ((posf.x == 0) && (posf.y > 0))
		*angle = M_PI/2;
	else if ((posf.x == 0) && (posf.y < 0))
		*angle = (3 * M_PI) / 2;
	if (posf.x > 0 && posf.y >= 0)
		*angle = atan(posf.y/posf.x) * (180/M_PI);
	else if (posf.x > 0 && posf.y < 0)
		*angle = (atan(posf.y/posf.x) + 2 * M_PI) * (180/M_PI);
	else if (posf.x < 0)
		*angle = (atan(posf.y/posf.x) + M_PI) * (180/M_PI);
	mob->speed.x = cos((180-(*angle))*M_PI / 180.)*2;
	mob->speed.y = -sin((180-(*angle))*M_PI / 180.)*2;
	mob->pos.x += mob->speed.x;
	mob->pos.y += mob->speed.y;
}

void				pathfinding_mob_2(all_t *all, mob_t *mob)
{
	if (collision_mobs(all, mob) == 1) {
		mob->pos.x -= mob->speed.x;
		mob->pos.y -= mob->speed.y;
		accros_wall(all, mob);
	}
	mob->pos_bar_life.x = mob->pos.x;
	mob->pos_bar_life.y = mob->pos.y + 10;
	sfSprite_setPosition(mob->sprite, mob->pos);
	sfSprite_setPosition(mob->bar_life, mob->pos_bar_life);
}

void				pathfinding_mob(all_t *all)
{
	mob_t *mob = all->scenes[all->current_scene].mob;
	object_t *player = all->scenes[all->current_scene].obj;
	sfVector2f posf = {0, 0};
	int angle = 0;

	if (NOT_PLAYING_SCENE)
		return;
	while (player && player->type != PLAYER)
		player = player->next;
	while (mob) {
		pathfinding_mob_1(mob, posf, &angle, player);
		pathfinding_mob_2(all, mob);
		mob = mob->next;
	}
}
