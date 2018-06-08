/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** go_to_dungeon_2.c
*/

#include "my.h"

void 				go_to_dungeon_2(all_t *all)
{
	if (all->his.step_h >= 4 && (STEP_NOT_QUEST)) {
		reset_scene_dungeon(all, 18);
		spawn_pharmacie_1(all);
		all->old_scene = all->current_scene;
		all->current_scene = 18;
	} else if (STEP_QUEST) {
		put_one_warning_quest(all);
	} else if (all->his.step_h < 4)
		put_one_warning_not_yet_dungeon(all);
}

void 				go_to_dungeon_2_2(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	if (there_is_zombie(all) == 0) {
		reset_scene_dungeon(all, 19);
		spawn_pharmacie_2(all);
		all->old_scene = all->current_scene;
		all->current_scene = 19;
	} else
		display_kaz(all);
}

void 				go_to_dungeon_2_3(all_t *all)
{
	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	if (there_is_zombie(all) == 0) {
		reset_scene_dungeon(all, 20);
		spawn_pharmacie_3(all);
		all->old_scene = all->current_scene;
		all->current_scene = 20;
	} else
		display_kaz(all);
}