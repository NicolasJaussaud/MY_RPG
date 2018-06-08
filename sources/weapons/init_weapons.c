/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_weapons.c
*/

#include "my.h"

/*
0 : GLOCK
1 : TEC-9
2 : UZI
3 : BERETTA
4 : FAMAS
5 : FN
6 : SCAR H
7 : SPAS12
8 : AUG
9 : M4A1
10: RPG
*/

void 				init_wp_1(wp_t **wp)
{
	(*wp)[0].degat = 3;
	(*wp)[0].range_max = 80;
	(*wp)[0].type = ONE;
	(*wp)[0].cadence = 1;
	(*wp)[1].degat = 6;
	(*wp)[1].range_max = 40;
	(*wp)[1].type = ONE;
	(*wp)[1].cadence = -1;
	(*wp)[2].degat = 5;
	(*wp)[2].range_max = 50;
	(*wp)[2].type = UNLIMITED;
	(*wp)[2].cadence = 5;
	(*wp)[3].degat = 13;
	(*wp)[3].range_max = 20;
	(*wp)[3].type = ONE;
	(*wp)[3].cadence = -1;
	(*wp)[4].degat = 10;
	(*wp)[4].range_max = 90;
	(*wp)[4].type = THREE;
	(*wp)[4].cadence = 5;
}

void 				init_wp_2(wp_t **wp)
{
	(*wp)[5].degat = 15;
	(*wp)[5].range_max = 90;
	(*wp)[5].type = ONE;
	(*wp)[5].cadence = -1;
	(*wp)[6].degat = 20;
	(*wp)[6].range_max = 90;
	(*wp)[6].type = UNLIMITED;
	(*wp)[6].cadence = 5;
	(*wp)[7].degat = 25;
	(*wp)[7].range_max = 30;
	(*wp)[7].type = ONE;
	(*wp)[7].cadence = -1;
	(*wp)[8].degat = 22;
	(*wp)[8].range_max = 100;
	(*wp)[8].type = UNLIMITED;
	(*wp)[8].cadence = 4;
	(*wp)[9].degat = 28;
	(*wp)[9].range_max = 120;
	(*wp)[9].type = UNLIMITED;
	(*wp)[9].cadence = 3;
}

wp_t 				*init_wp(void)
{
	wp_t *wp = malloc(sizeof(wp_t) * 15);

	init_wp_1(&wp);
	init_wp_2(&wp);
	wp[10].degat = 100;
	wp[10].range_max = 150;
	wp[10].type = ONE;
	wp[10].cadence = -1;
	return (wp);
}

void 				weapon_management(all_t *all)
{
	all->player.wp = all->wp[all->inv.weapon_select];
}