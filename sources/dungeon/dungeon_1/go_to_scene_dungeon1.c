/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon_mechanics.c
*/

#include "my.h"

void 				go_to_scene_10(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	if (STEP_NOT_QUEST) {
		reset_scene_dungeon(all, 10);
		spawn_hospital_1(all);
		all->old_scene = all->current_scene;
		all->current_scene = 10;
	} else if (STEP_QUEST)
		put_one_warning_quest(all);
}

void 				go_to_scene_13(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	if (there_is_zombie(all) == 0) {
		reset_scene_dungeon(all, 13);
		spawn_hospital_2(all);
		all->old_scene = all->current_scene;
		all->current_scene = 13;
	} else
		display_kaz(all);
}

void 				go_to_scene_14(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	if (there_is_zombie(all) == 0) {
		reset_scene_dungeon(all, 14);
		spawn_hospital_3(all);
		all->old_scene = all->current_scene;
		all->current_scene = 14;
	} else
		display_kaz(all);
}