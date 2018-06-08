/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** damage_taken.c
*/

#include "my.h"

int 				collision_player_mobs(object_t *player,
mob_t *mob)
{
	if (player->pos.x + player->rect.width > mob->pos.x &&
	player->pos.x < mob->pos.x + mob->rect.width && player->pos.y + \
	player->rect.height > mob->pos.y && player->pos.y < mob->pos.y + \
	mob->rect.height)
		return (1);
	return (0);
}

void 				damage_taken(all_t *all)
{
	object_t *player = all->scenes[all->current_scene].obj;
	mob_t *tmp;

	if (CST != GAME && CST != HOSPITAL && CST != PHARMACIE)
		return;
	tmp = all->scenes[all->current_scene].mob;
	while (player && player->type != PLAYER)
		player = player->next;
	while (tmp) {
		if (tmp->type == ZOMBIE && collision_player_mobs(player, tmp) \
		== 1 && all->clock.n % 15 == 0) {
			all->player.health -= tmp->damage;
		}
		tmp = tmp->next;
	}
}
