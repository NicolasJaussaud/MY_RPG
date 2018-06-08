/*
** EPITECH PROJECT, 2018
** funcs_inventory2
** File description:
** funcs_pause.c
*/

#include "my.h"

void 				go_to_continuepause(all_t *all)
{
	all->current_scene = all->pause.old_scene;
}

void 				go_to_htppause(all_t *all)
{
	all->htp.old_scene = all->current_scene;
	all->current_scene = 15;
}