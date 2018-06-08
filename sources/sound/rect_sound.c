/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** rect_sound.c
*/

#include "my.h"

void 				rect_sound_management(all_t *all)
{
	object_t *tmp =all->scenes[21].obj;

	while (tmp && tmp->type != SOUND1)
		tmp = tmp->next;

	if (tmp->type == SOUND1) {
		sfSprite_setTextureRect(tmp->sprite, \
		(sfIntRect){0, 0, (204 * all->settings_sound.sound_env)/100, 21});
	}
}

void 				quit_scene_settings_sound(all_t *all)
{
	if (all->old_scene == 0) {
		all->current_scene = 0;
	} else
		all->current_scene = all->pause.old_scene;
}

void				set_volume(all_t *all)
{
	for (int i = 0; i < all->nb_sounds; i++)
		sfMusic_setVolume(all->sounds[i],
		all->settings_sound.sound_env);
}