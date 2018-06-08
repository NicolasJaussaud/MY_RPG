/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display.c
*/

#include "my.h"

void 				shop2_button4(all_t *all)
{
	all->shop2[0].select = 0;
	all->shop2[1].select = 0;
	all->shop2[2].select = 0;
	all->shop2[3].select = 1;
}
void 				shop2_button3(all_t *all)
{
	all->shop2[0].select = 0;
	all->shop2[1].select = 0;
	all->shop2[2].select = 1;
	all->shop2[3].select = 0;
}

void 				shop2_button2(all_t *all)
{
	all->shop2[0].select = 0;
	all->shop2[1].select = 1;
	all->shop2[2].select = 0;
	all->shop2[3].select = 0;
}

void 				shop2_button1(all_t *all)
{
	all->shop2[0].select = 1;
	all->shop2[1].select = 0;
	all->shop2[2].select = 0;
	all->shop2[3].select = 0;
}

void 				shop2_buy(all_t *all)
{
	int i = 0;

	while (i != 4) {
		if (all->shop2[i].select == 1)
			break;
		i++;
	}
	if (all->player.money >= all->shop2[i].price) {
		all->inv.tabfood[i].nb += 1;
		all->player.money -= all->shop2[i].price;
	} else
		display_string(all, "Vous n avez pas assez\nd argent !\n");
	sfMusic_play(all->sounds[0]);
}