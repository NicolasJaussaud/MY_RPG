/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** go_to_scenes_1.c
*/

#include "my.h"

void 				my_exit(all_t *all)
{
	(void)all;
	exit(834);
}

void 				go_to_scene_2(all_t *all)
{
	if (all->current_scene != 2)
		all->old_scene = all->current_scene;
	all->current_scene = 2;
}

void 				go_to_scene_3(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 3;
	if ((INTERMEDIATE_STEP) && STEP != 0) {
		STEP += 1;
	}
}

void 				go_to_scene_8(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	all->old_scene = all->current_scene;
	all->current_scene = 8;
}

void 				go_to_scene_6(all_t *all)
{
	all->old_scene = all->current_scene;
	all->current_scene = 6;
}