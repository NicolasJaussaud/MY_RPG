/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display.c
*/

#include "my.h"

void 				shop1_button3(all_t *all)
{
	all->shop1[0].select = 0;
	all->shop1[1].select = 0;
	all->shop1[2].select = 1;
}

void 				shop1_button2(all_t *all)
{
	all->shop1[0].select = 0;
	all->shop1[1].select = 1;
	all->shop1[2].select = 0;
}

void 				shop1_button1(all_t *all)
{
	all->shop1[0].select = 1;
	all->shop1[1].select = 0;
	all->shop1[2].select = 0;
}

void 				shop1_close(all_t *all)
{
	all->current_scene = 8;
}

void 				shop1_buy(all_t *all)
{
	int i = 0;

	while (i != 3) {
		if (all->shop1[i].select == 1)
			break;
		i++;
	}
	if (all->player.money >= all->shop1[i].price) {
		all->inv.tabfood[i + 4].nb += 1;
		all->player.money -= all->shop1[i].price;
	} else
		display_string(all, "Vous n avez pas assez \nd argent !\n");
	sfMusic_play(all->sounds[0]);
}