/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** display_player.c
*/

#include "my.h"

void 				get_object(object_t **cursor,
object_t **minimap, object_t **map, object_t **player)
{
	while (*cursor) {
		if ((*cursor)->type == CURSOR_PLAYER)
			break;
		*cursor = (*cursor)->next;
	}
	while (*minimap) {
		if ((*minimap)->type == MINIMAP)
			break;
		*minimap = (*minimap)->next;
	}
	while (*map) {
		if ((*map)->type == BG)
			break;
		*map = (*map)->next;
	}
	while (*player) {
		if ((*player)->type == PLAYER)
			break;
		*player = (*player)->next;
	}
}

void 				minimap_ig(all_t *all)
{
	object_t *minimap = all->scenes[1].obj;
	object_t *map = all->scenes[1].obj;
	object_t *player = all->scenes[1].obj;
	object_t *cursor = all->scenes[1].obj;

	get_object(&cursor, &minimap, &map, &player);
	minimap->rect.top = ((map->pos.y * (-1)) / 10) + 200;
	minimap->rect.left = ((map->pos.x * (-1)) / 10) + 200;
	cursor->pos.x = 1496 - 8 + player->pos.x / 10;
	cursor->pos.y = 50 - 8 + player->pos.y / 10;
	sfSprite_setTextureRect(minimap->sprite, minimap->rect);
	sfSprite_setPosition(cursor->sprite, cursor->pos);
}
