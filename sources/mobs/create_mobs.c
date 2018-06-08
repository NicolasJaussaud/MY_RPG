/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create_mobs.c
*/

#include "my.h"

int 		collision_mobs_random_spawn(all_t *all, sfVector2f rp)
{
	object_t *obj = all->scenes[all->current_scene].obj;

	while (obj) {
		if (obj->type == OBJ) {
			if (rp.x + 100 > obj->pos.x && rp.x < obj->pos.x + \
			obj->rect.width + 100 && rp.y + 50 > obj->pos.y && \
			rp.y < obj->pos.y + obj->rect.height + 50)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

object_t 	*get_bg(all_t *all)
{
	object_t *bg = all->scenes[1].obj;

	for (; bg && bg->type != BG; bg = bg->next);
	return (bg);
}

sfVector2f 	get_random_pos(all_t *all)
{
	sfVector2f rp = {0,0};
	object_t *bg = get_bg(all);

	do {
		rp.x = rand_a_b(bg->pos.x + 100, bg->pos.x + 4200);
		rp.y = rand_a_b(bg->pos.y + 100, bg->pos.y + 3700);
	} while (collision_mobs_random_spawn(all, rp) == 1);
	return (rp);
}

void		create_mobs_random_core(mob_t *mob, all_t *all)
{
	sfVector2f random_pos = get_random_pos(all);

	mob->sprite = sfSprite_create();
	mob->bar_life = sfSprite_create();
	mob->pos_bar_life = (sfVector2f){500, 490};
	mob->pos = random_pos;
	mob->speed = (sfVector2f){3, 0};
	mob->rect = (sfIntRect){0, 0, 31, 70};
	mob->rect_bar_life = (sfIntRect){0, 0, 31, 4};
	mob->offset = 0;
	mob->size_max = 0;
	mob->damage = all->player.lvl * 5;
	mob->health = all->player.lvl * 20;
	mob->health_max = mob->health;
	mob->type = ZOMBIE;
	mob->next = NULL;
}

void 		create_mobs_random(all_t *all)
{
	mob_t *mob = malloc(sizeof(*mob));
	mob_t *tmp = all->scenes[1].mob;
	static int id = 0;

	create_mobs_random_core(mob, all);
	mob->id = id;
	id++;
	sfSprite_setTexture(mob->sprite, all->textures[20], sfTrue);
	sfSprite_setTexture(mob->bar_life, all->textures[21], sfTrue);
	sfSprite_setPosition(mob->sprite, mob->pos);
	sfSprite_setPosition(mob->bar_life, mob->pos_bar_life);
	sfSprite_setTextureRect(mob->sprite, mob->rect);
	sfSprite_setTextureRect(mob->bar_life, mob->rect_bar_life);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = mob;
}
