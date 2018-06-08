/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** spawn_dungeon1.c
*/

#include "my.h"

void 				spawn_hospital_1(all_t *all)
{
	create_mobs(all, 10, (int [2]){900, 500}, 50);
	create_mobs(all, 10, (int [2]){800, 400}, 50);
	create_mobs(all, 10, (int [2]){900, 900}, 50);
	create_mobs(all, 10, (int [2]){1000, 400}, 50);
}

void 				spawn_hospital_2(all_t *all)
{
	create_mobs(all, 13, (int [2]){300, 150}, 70);
	create_mobs(all, 13, (int [2]){900, 150}, 70);
	create_mobs(all, 13, (int [2]){1200, 500}, 70);
	create_mobs(all, 13, (int [2]){1100, 700}, 70);
	create_mobs(all, 13, (int [2]){1600, 900}, 70);
	create_mobs(all, 13, (int [2]){1600, 400}, 70);
}

void 				spawn_hospital_3(all_t *all)
{
	create_mobs(all, 14, (int [2]){200, 700}, 90);
	create_mobs(all, 14, (int [2]){450, 500}, 90);
	create_mobs(all, 14, (int [2]){800, 800}, 90);
	create_mobs(all, 14, (int [2]){1000, 200}, 90);
	create_mobs(all, 14, (int [2]){1000, 800}, 90);
	create_mobs(all, 14, (int [2]){1400, 200}, 90);
	create_mobs(all, 14, (int [2]){1400, 700}, 90);
	create_mobs(all, 14, (int [2]){200, 170}, 90);
}