/*
** EPITECH PROJECT, 2018
** create_structweapon
** File description:
** create_structweapon
*/

#include "my.h"

void inittextweapon(all_t *all)
{
	sfText_setString(all->inv.textweapon[0], "Glock");
	sfText_setString(all->inv.textweapon[1], "Tec-9");
	sfText_setString(all->inv.textweapon[2], "Uzi");
	sfText_setString(all->inv.textweapon[3], "Beretta");
	sfText_setString(all->inv.textweapon[4], "Famas");
	sfText_setString(all->inv.textweapon[5], "Fn-fal");
	sfText_setString(all->inv.textweapon[6], "Scar-h");
}

void inittextureweapon(all_t *all)
{
	all->inv.tweapon[0] =
	sfTexture_createFromFile("assets/imgs/wp/glock2.png", NULL);
	all->inv.tweapon[1] =
	sfTexture_createFromFile("assets/imgs/wp/tec-92.png", NULL);
	all->inv.tweapon[2] =
	sfTexture_createFromFile("assets/imgs/wp/uzi2.png", NULL);
	all->inv.tweapon[3] =
	sfTexture_createFromFile("assets/imgs/wp/beretta.png", NULL);
	all->inv.tweapon[4] =
	sfTexture_createFromFile("assets/imgs/wp/famas.png", NULL);
	all->inv.tweapon[5] =
	sfTexture_createFromFile("assets/imgs/wp/fn-fal.png", NULL);
	all->inv.tweapon[6] =
	sfTexture_createFromFile("assets/imgs/wp/scar.png", NULL);
}

void initweapon(all_t *all)
{
	for (int i = 0; i != 11; i++)
		all->inv.textweapon[i] = sfText_create();
	for (int i = 0; i != 7; i++) {
		sfText_setFont(all->inv.textweapon[i], all->inv.font);
		sfText_setCharacterSize(all->inv.textweapon[i], 25);
	}
	for (int i = 0; i != 11; i++)
		all->inv.sweapon[i] = sfSprite_create();
	inittextureweapon(all);
	for (int i = 0; i != 7; i++)
		sfSprite_setTexture(all->inv.sweapon[i], all->inv.tweapon[i],
		sfTrue);
	inittextweapon(all);
}