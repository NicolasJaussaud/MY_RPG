/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** core_2.c
*/

#include "my.h"

void				core_3(all_t *all)
{
	hunger_thirst(all);
	animation_mob(all);
	weapon_management(all);
	dialog_management(all);
	kaz_management(all);
	rect_sound_management(all);
	obj_recup_management(all);
	quest_1_display_string(all);
	gestion_warning_quest(all);
}