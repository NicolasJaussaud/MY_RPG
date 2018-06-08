/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** take_item.c
*/

#include "my.h"

void 				take_item_hospital(all_t *all)
{
	STEP = 1;
	all->old_scene = all->current_scene;
	all->current_scene = 22;
}

void 				take_item_pharmacie(all_t *all)
{
	STEP = 5;
	all->old_scene = all->current_scene;
	all->current_scene = 22;
}