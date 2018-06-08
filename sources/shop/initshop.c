/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** create.c
*/

#include "my.h"

void initshoptext(all_t *all)
{
	char *text = malloc(sizeof(char) * 100);
	char *tmptext = malloc(sizeof(char) * 100);
	sfVector2f pos = {180, 126};
	sfVector2f posprice = {400, 126};

	for (int i = 0; i != 3; i++) {
		my_getcharstar(all->shop1[i].price, text);
		tmptext = my_strcat(" ", text);
		sfText_setString(all->shop1[i].textprice, tmptext);
		sfText_setString(all->shop1[i].text, all->shop1[i].name);
		sfText_setFont(all->shop1[i].text, all->inv.font);
		sfText_setFont(all->shop1[i].textprice, all->inv.font);
		sfText_setCharacterSize(all->shop1[i].text, 22);
		sfText_setCharacterSize(all->shop1[i].textprice, 22);
		pos.y = pos.y + 49;
		sfText_setPosition(all->shop1[i].text, pos);
		posprice.y = posprice.y + 49;
		sfText_setPosition(all->shop1[i].textprice, posprice);
	}
}

void initshop(all_t *all)
{
	all->shop1 = malloc(sizeof(shop1_t) * 3);
	for (int i = 0; i != 3; i++) {
		all->shop1[i].text = sfText_create();
		all->shop1[i].textprice = sfText_create();
		all->shop1[i].name = malloc(sizeof(char) * 100);
	}
	all->shop1[0].name = "Bouteille d eau";
	all->shop1[0].price = 10;
	all->shop1[0].select = 1;
	all->shop1[1].name = "Brique de lait";
	all->shop1[1].price = 20;
	all->shop1[1].select = 0;
	all->shop1[2].name = "Redbull";
	all->shop1[2].price = 50;
	all->shop1[2].select = 0;
	initshoptext(all);
}