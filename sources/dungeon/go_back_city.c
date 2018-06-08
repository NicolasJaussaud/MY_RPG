/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** go_back_city.c
*/

#include "my.h"

void				from_scene_14(all_t *all)
{
	if (all->current_scene == 14) {
		if (there_is_zombie(all) == 0 && STEP == 1) {
			all->old_scene = all->current_scene;
			all->current_scene = 1;
		} else if (there_is_zombie(all) == 1) {
			display_kaz(all);
		} else if (STEP == 0) {
			display_recup_obj(all);
		}
	}
}

void				from_scene_12(all_t *all,
object_t *player, object_t *bg)
{
	if (all->current_scene == 12) {
		reset_obj(all);
		reset_btn_txt(all);
		reset_player_and_bg(all, &player, &bg);
		all->current_scene = 1;
		all->old_scene = all->current_scene;

	}
}

void 				go_to_scene_1(all_t *all)
{
	object_t *player= all->scenes[1].obj;
	object_t *bg = all->scenes[1].obj;

	if (OLD_PLAYING_SCENE)
		sfMusic_play(all->sounds[1]);
	from_scene_12(all, player, bg);
	from_scene_14(all);
	if (all->current_scene == 20) {
		if (there_is_zombie(all) == 0 && STEP == 5) {
			all->old_scene = all->current_scene;
			all->current_scene = 1;
		} else if (there_is_zombie(all) == 1) {
			display_kaz(all);
		} else if (STEP == 4) {
			display_recup_obj(all);
		}
	} else
		all->current_scene = 1;
}