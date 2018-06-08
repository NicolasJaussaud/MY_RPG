/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** spawn_dungeon2.c
*/

#include "my.h"

void 				spawn_pharmacie_1(all_t *all)
{
	create_mobs(all, 18, (int [2]){900, 500}, 70);
	create_mobs(all, 18, (int [2]){800, 400}, 70);
	create_mobs(all, 18, (int [2]){900, 900}, 70);
	create_mobs(all, 18, (int [2]){1000, 400}, 70);
}

void 				spawn_pharmacie_2(all_t *all)
{
	create_mobs(all, 19, (int [2]){300, 150}, 90);
	create_mobs(all, 19, (int [2]){900, 150}, 90);
	create_mobs(all, 19, (int [2]){1200, 500}, 90);
	create_mobs(all, 19, (int [2]){1100, 700}, 90);
	create_mobs(all, 19, (int [2]){1600, 900}, 90);
	create_mobs(all, 19, (int [2]){1600, 400}, 90);
}

void 				spawn_pharmacie_3(all_t *all)
{
	create_mobs(all, 20, (int [2]){200, 700}, 110);
	create_mobs(all, 20, (int [2]){450, 500}, 110);
	create_mobs(all, 20, (int [2]){800, 800}, 110);
	create_mobs(all, 20, (int [2]){1000, 200}, 110);
	create_mobs(all, 20, (int [2]){1000, 800}, 110);
	create_mobs(all, 20, (int [2]){1400, 200}, 110);
	create_mobs(all, 20, (int [2]){1400, 700}, 110);
	create_mobs(all, 20, (int [2]){200, 170}, 110);
}