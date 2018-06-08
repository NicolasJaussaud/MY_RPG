/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** funcs_htp.c
*/

#include "my.h"

void 				go_to_htp2(all_t *all)
{
	all->current_scene = 24;
}

void 				go_to_htp(all_t *all)
{
	all->current_scene = 16;
}

void 				quit_htp(all_t *all)
{
	all->current_scene = all->pause.old_scene;
	display_scenes(all);
	all->current_scene = all->htp.old_scene;
}