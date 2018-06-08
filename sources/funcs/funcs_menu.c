/*
** EPITECH PROJECT, 2018
** funcs_inventory2
** File description:
** funcs_menu.c
*/

#include "my.h"

void 				go_to_htpmenu(all_t *all)
{
	all->htp.old_scene = all->current_scene;
	all->current_scene = 15;
}