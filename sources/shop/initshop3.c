/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** create.c
*/

#include "my.h"

void initshoptext3(all_t *all)
{
	char *text = malloc(sizeof(char) * 100);
	char *tmptext = malloc(sizeof(char) * 100);
	sfVector2f pos = {180, 130};
	sfVector2f posprice = {400, 130};

	for (int i = 0; i != 11; i++) {
		my_getcharstar(all->shop3[i].price, text);
		tmptext = my_strcat(" ", text);
		sfText_setString(all->shop3[i].textprice, tmptext);
		sfText_setString(all->shop3[i].text, all->shop3[i].name);
		sfText_setFont(all->shop3[i].text, all->inv.font);
		sfText_setFont(all->shop3[i].textprice, all->inv.font);
		sfText_setCharacterSize(all->shop3[i].text, 22);
		sfText_setCharacterSize(all->shop3[i].textprice, 22);
		pos.y = pos.y + 40;
		sfText_setPosition(all->shop3[i].text, pos);
		posprice.y = posprice.y + 40;
		sfText_setPosition(all->shop3[i].textprice, posprice);
	}
}

void initshop_a(all_t*all)
{
	all->shop3[1].name = "Tec 9";
	all->shop3[1].price = 50;
	all->shop3[1].select = 0;
	all->shop3[1].level = 2;
	all->shop3[2].name = "Uzi";
	all->shop3[2].price = 150;
	all->shop3[2].select = 0;
	all->shop3[2].level = 4;
	all->shop3[3].name = "Beretta 692";
	all->shop3[3].price = 200;
	all->shop3[3].select = 0;
	all->shop3[3].level = 6;
}

void initshop_b(all_t *all)
{
	all->shop3[4].name = "Famas";
	all->shop3[4].price = 300;
	all->shop3[4].select = 0;
	all->shop3[4].level = 8;
	all->shop3[5].name = "fn fal";
	all->shop3[5].price = 400;
	all->shop3[5].select = 0;
	all->shop3[5].level = 10;
	all->shop3[6].name = "Scar h";
	all->shop3[6].price = 500;
	all->shop3[6].select = 0;
	all->shop3[6].level = 12;
	all->shop3[7].name = "Spas 12";
	all->shop3[7].price = 800;
	all->shop3[7].select = 0;
	all->shop3[7].level = 14;
}

void initshop_c(all_t *all)
{
	all->shop3[8].name = "Aug";
	all->shop3[8].price = 1000;
	all->shop3[8].select = 0;
	all->shop3[8].level = 16;
	all->shop3[9].name = "M4A1";
	all->shop3[9].price = 5000;
	all->shop3[9].select = 0;
	all->shop3[9].level = 18;
	all->shop3[10].name = "RPG";
	all->shop3[10].price = 20000;
	all->shop3[10].select = 0;
	all->shop3[10].level = 20;
}

void initshop3(all_t *all)
{
	all->shop3 = malloc(sizeof(shop3_t) * 11);
	for (int i = 0; i != 11; i++) {
		all->shop3[i].text = sfText_create();
		all->shop3[i].textprice = sfText_create();
		all->shop3[i].name = malloc(sizeof(char) * 100);
	}
	all->shop3[0].name = "Glock";
	all->shop3[0].price = 0;
	all->shop3[0].select = 1;
	all->shop3[0].level = 0;
	initshop_a(all);
	initshop_b(all);
	initshop_c(all);
	initshoptext3(all);
}