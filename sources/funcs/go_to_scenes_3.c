/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** go_to_scenes_3.c
*/

#include "my.h"

void 				go_to_scene_0(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 0;
}

void 				go_to_scene_12(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	all->current_scene = 12;
}

void 				go_to_scene_21(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 21;
}

void 				go_to_scene_23(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 12;
}

void				go_to_old_scene(all_t *all)
{
	all->current_scene = all->old_scene;
}