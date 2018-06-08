/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** warning.c
*/

#include "my.h"

void 				put_one_warning_quest(all_t *all)
{
	object_t *tmp = all->scenes[1].obj;

	while (tmp && tmp->type != YOU_QUEST)
		tmp = tmp->next;
	tmp->display = 1;
	tmp->despawn = 100;
}

void 				put_one_warning_not_yet_dungeon(all_t *all)
{
	object_t *tmp = all->scenes[1].obj;

	while (tmp && tmp->type != NOT_YET_DUNGEON)
		tmp = tmp->next;
	tmp->display = 1;
	tmp->despawn = 100;
}

void 				gestion_warning_quest(all_t *all)
{
	object_t *tmp = all->scenes[1].obj;

	while (tmp && tmp->type != YOU_QUEST)
		tmp = tmp->next;
	if (tmp->despawn > 0)
		tmp->despawn -= 1;
	if (tmp->despawn <= 0)
		tmp->display = 0;
	tmp = all->scenes[1].obj;
	while (tmp && tmp->type != NOT_YET_DUNGEON)
		tmp = tmp->next;
	if (tmp->despawn > 0)
		tmp->despawn -= 1;
	if (tmp->despawn <= 0)
		tmp->display = 0;
}