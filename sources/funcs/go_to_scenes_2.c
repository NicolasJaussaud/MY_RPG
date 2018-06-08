/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** go_to_scenes_2.c
*/

#include "my.h"

void 				go_to_scene_5(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 5;
}

void 				go_to_scene_4(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 4;
}

void 				go_to_scene_7(all_t *all)
{
	if (all->current_scene != 7)
		all->old_scene = all->current_scene;
	all->current_scene = 7;
}

void 				go_to_scene_9(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 9;
}

void 				go_to_scene_11(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 11;
}