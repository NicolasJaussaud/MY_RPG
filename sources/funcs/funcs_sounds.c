/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** funcs_sound.c
*/

#include "my.h"

void 				sound_plus_one(all_t *all)
{
	if (all->settings_sound.sound_env < 97)
		all->settings_sound.sound_env += 4;
	set_volume(all);
}

void 				sound_less_one(all_t *all)
{
	if (all->settings_sound.sound_env > 3)
		all->settings_sound.sound_env -= 4;
	set_volume(all);
}