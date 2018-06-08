/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** func_shop3.c
*/

#include "my.h"

void 				shop3_button4(all_t *all)
{
	all->shop3[0].select = 0;
	all->shop3[1].select = 0;
	all->shop3[2].select = 0;
	all->shop3[3].select = 1;
	all->shop3[4].select = 0;
	all->shop3[5].select = 0;
	all->shop3[6].select = 0;
	all->shop3[7].select = 0;
	all->shop3[8].select = 0;
	all->shop3[9].select = 0;
	all->shop3[10].select = 0;
}

void 				shop3_button3(all_t *all)
{
	all->shop3[0].select = 0;
	all->shop3[1].select = 0;
	all->shop3[2].select = 1;
	all->shop3[3].select = 0;
	all->shop3[4].select = 0;
	all->shop3[5].select = 0;
	all->shop3[6].select = 0;
	all->shop3[7].select = 0;
	all->shop3[8].select = 0;
	all->shop3[9].select = 0;
	all->shop3[10].select = 0;
}

void 				shop3_button2(all_t *all)
{
	all->shop3[0].select = 0;
	all->shop3[1].select = 1;
	all->shop3[2].select = 0;
	all->shop3[3].select = 0;
	all->shop3[4].select = 0;
	all->shop3[5].select = 0;
	all->shop3[6].select = 0;
	all->shop3[7].select = 0;
	all->shop3[8].select = 0;
	all->shop3[9].select = 0;
	all->shop3[10].select = 0;
}

void 				shop3_button1(all_t *all)
{
	all->shop3[0].select = 1;
	all->shop3[1].select = 0;
	all->shop3[2].select = 0;
	all->shop3[3].select = 0;
	all->shop3[4].select = 0;
	all->shop3[5].select = 0;
	all->shop3[6].select = 0;
	all->shop3[7].select = 0;
	all->shop3[8].select = 0;
	all->shop3[9].select = 0;
	all->shop3[10].select = 0;
}

void 				shop3_buy(all_t *all)
{
	int i = 0;

	while (i != 11) {
		if (all->shop3[i].select == 1)
			break;
		i++;
	}
	if (all->player.money >= all->shop3[i].price && i != 0) {
		if (all->inv.tabweapon[i].draw == 1)
			display_string(all, "Vous possedez deja\ncette arme !");
		else if (all->player.lvl < all->shop3[i].level)
			display_string(all, "Vous n'avez pas le\nlevel necessaire !");
		else {
			all->inv.tabweapon[i].draw = 1;
			all->player.money -= all->shop3[i].price;
		}
	} else {
		display_string(all, "Vous n avez pas assez\nd argent !\n");
	}
	sfMusic_play(all->sounds[0]);
}