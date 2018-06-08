/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** create.c
*/

#include "my.h"

void initshoptext2(all_t *all)
{
	char *text = malloc(sizeof(char) * 100);
	char *tmptext = malloc(sizeof(char) * 100);
	sfVector2f pos = {180, 126};
	sfVector2f posprice = {400, 126};

	for (int i = 0; i != 4; i++) {
		my_getcharstar(all->shop2[i].price, text);
		tmptext = my_strcat(" ", text);
		sfText_setString(all->shop2[i].textprice, tmptext);
		sfText_setString(all->shop2[i].text, all->shop2[i].name);
		sfText_setFont(all->shop2[i].text, all->inv.font);
		sfText_setFont(all->shop2[i].textprice, all->inv.font);
		sfText_setCharacterSize(all->shop2[i].text, 22);
		sfText_setCharacterSize(all->shop2[i].textprice, 22);
		pos.y = pos.y + 49;
		sfText_setPosition(all->shop2[i].text, pos);
		posprice.y = posprice.y + 49;
		sfText_setPosition(all->shop2[i].textprice, posprice);
	}
}

void initshop2(all_t *all)
{
	all->shop2 = malloc(sizeof(shop2_t) * 4);
	for (int i = 0; i != 4; i++) {
		all->shop2[i].text = sfText_create();
		all->shop2[i].textprice = sfText_create();
		all->shop2[i].name = malloc(sizeof(char) * 100);
	}
	all->shop2[0].name = "Pomme";
	all->shop2[0].price = 10;
	all->shop2[0].select = 1;
	all->shop2[1].name = "Barre de cereale";
	all->shop2[1].price = 20;
	all->shop2[1].select = 0;
	all->shop2[2].name = "boite de conserve";
	all->shop2[2].price = 50;
	all->shop2[2].select = 0;
	all->shop2[3].name = "steak";
	all->shop2[3].price = 80;
	all->shop2[3].select = 0;
	initshoptext2(all);
}