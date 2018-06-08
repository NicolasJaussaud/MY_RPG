/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** display_player.c
*/

#include "my.h"

void 				get_player_cursor_map(object_t **cursor,
object_t **map, object_t **player)
{
	while ((*player)) {
		if ((*player)->type == PLAYER)
			break;
		*player = (*player)->next;
	}
	while ((*cursor)) {
		if ((*cursor)->type == CURSOR_PLAYER)
			break;
		*cursor = (*cursor)->next;
	}
	while ((*map)) {
		if ((*map)->type == BG)
			break;
		*map = (*map)->next;
	}
}

void 				minimap_management(all_t *all)
{
	object_t *cursor = all->scenes[7].obj;
	object_t *map = all->scenes[1].obj;
	object_t *player = all->scenes[1].obj;

	get_player_cursor_map(&cursor, &map, &player);
	cursor->pos.x = (((map->pos.x * (-1)) / 7680) * 768) + 576 - 8 +\
	(player->pos.x/10);
	cursor->pos.y = (((map->pos.y * (-1)) / 7680) * 768) + 324 - 30 +\
	(player->pos.y/10);
	sfSprite_setPosition(cursor->sprite, cursor->pos);
	minimap_ig(all);
}
