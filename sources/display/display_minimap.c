/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** display_minimap.c
*/

#include "my.h"

void			display_minimap_2(all_t *all)
{
	object_t *map = all->scenes[all->current_scene].obj;

	while (map) {
		if (map->type == MINIMAP) {
			sfRenderWindow_drawSprite(all->window.window,
			map->sprite, NULL);
			break;
		}
		map = map->next;
	}
	map = all->scenes[all->current_scene].obj;
	while (map) {
		if (map->type == CURSOR_PLAYER) {
			sfRenderWindow_drawSprite(all->window.window,
			map->sprite, NULL);
			break;
		}
		map = map->next;
	}
}

void 			display_minimap(all_t *all)
{
	object_t *map = all->scenes[all->current_scene].obj;

	minimap_ig(all);
	while (map) {
		if (map->type == HUD_BAR) {
			sfRenderWindow_drawSprite(all->window.window,
			map->sprite, NULL);
			break;
		}
		map = map->next;
	}
	display_minimap_2(all);
}