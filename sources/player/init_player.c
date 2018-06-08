/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_player.c
*/

#include "my.h"

stats_t 			init_stats(void)
{
	stats_t stat;

	stat.agility = 0;
	stat.thirst = 0;
	stat.hunger = 0;
	stat.precision = 0;
	stat.stat_precision = 0;
	stat.to_share = 10;
	return (stat);
}

player_t 			init_player(all_t *all)
{
	player_t player;

	player.walking = 0;
	player.speed_w = 5;
	player.speed_w_base = 5;
	player.health = 100;
	player.health_max = 100;
	player.drink = 50;
	player.food = 50;
	player.lvl = 1;
	player.xp = 1;
	player.direction = DOWN;
	player.wp = all->wp[0];
	player.money = 1000000;
	player.stat = init_stats();
	return (player);
}

info_t 				init_info(void)
{
	info_t info;

	info.next_lvl_xp = 100;
	info.cst_xp = 1.4;
	return (info);
}
