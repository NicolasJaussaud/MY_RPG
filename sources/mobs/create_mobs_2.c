/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** create_mobs_2.c
*/

#include "my.h"

void 	create_mobs_core(mob_t *mob, int pos[2], int health, int id)
{
	mob->sprite = sfSprite_create();
	mob->bar_life = sfSprite_create();
	mob->pos_bar_life = (sfVector2f){500, 490};
	mob->pos = (sfVector2f){pos[0], pos[1]};
	mob->speed = (sfVector2f){0, 0};
	mob->rect = (sfIntRect){0, 0, 31, 70};
	mob->rect_bar_life = (sfIntRect){0, 0, 31, 4};
	mob->offset = 31;
	mob->size_max = 92;
	mob->damage = 10;
	mob->health = health;
	mob->health_max = mob->health;
	mob->type = ZOMBIE;
	mob->id = id;
	mob->next = NULL;
}

void 	create_mobs(all_t *all, int scene, int pos[2], int health)
{
	mob_t *mob = malloc(sizeof(*mob));
	mob_t *tmp = all->scenes[scene].mob;
	static int id = 0;

	create_mobs_core(mob, pos, health, id);
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