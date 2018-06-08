/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init.c
*/

#include "my.h"

fptr_t				*init_fptr(void)
{
	fptr_t *f = malloc(sizeof(fptr_t) * 1000);

	f[0].fptr = &my_exit;
	f[1].fptr = &go_to_scene_1;
	f[2].fptr = &add_agility;
	f[3].fptr = &add_precision;
	f[4].fptr = &add_thirst;
	f[5].fptr = &add_hunger;
	f[6].fptr = &inventory_use;
	f[7].fptr = &inventory_button1;
	f[8].fptr = &inventory_button2;
	f[9].fptr = &inventory_button3;
	f = init_fptr1(f);
	f = init_fptr2(f);
	f = init_fptr3(f);
	f = init_fptr4(f);
	f = init_fptr5(f);
	return (f);
}