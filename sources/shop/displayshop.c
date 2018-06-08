/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** displayshop
*/

#include "my.h"

void displayshop3(all_t *all)
{
	for (int i = 0; i != 11; i++) {
		if (all->shop3[i].select == 1)
			sfText_setColor	(all->shop3[i].text,
			(sfColor){174, 0, 0, 255});
		else
			sfText_setColor	(all->shop3[i].text, sfWhite);
		sfRenderWindow_drawText(all->window.window,
		all->shop3[i].text, NULL);
		sfRenderWindow_drawText(all->window.window,
		all->shop3[i].textprice, NULL);
	}
}

void displayshop2(all_t *all)
{
	for (int i = 0; i != 4; i++) {
		if (all->shop2[i].select == 1)
			sfText_setColor	(all->shop2[i].text,
			(sfColor){0, 174, 0, 255});
		else
			sfText_setColor	(all->shop2[i].text, sfWhite);
		sfRenderWindow_drawText(all->window.window,
		all->shop2[i].text, NULL);
		sfRenderWindow_drawText(all->window.window,
		all->shop2[i].textprice, NULL);
	}
}

void displayshop(all_t *all)
{
	for (int i = 0; i != 3; i++) {
		if (all->shop1[i].select == 1)
			sfText_setColor	(all->shop1[i].text,
			(sfColor){0, 131, 174, 255});
		else
			sfText_setColor	(all->shop1[i].text, sfWhite);
		sfRenderWindow_drawText(all->window.window,
		all->shop1[i].text, NULL);
		sfRenderWindow_drawText(all->window.window,
		all->shop1[i].textprice, NULL);
	}
}