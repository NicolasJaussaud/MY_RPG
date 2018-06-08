/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** display_string.c
*/

#include "my.h"

void		display_string(all_t *all, char *string)
{
	sfTexture* texture;
	sfSprite* sprite = sfSprite_create();
	sfText* text = sfText_create();
	sfVector2f postext = {1560, 100};

	texture = sfTexture_createFromFile("assets/imgs/bg.png", NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfText_setString(text, string);
	sfText_setFont(text, all->inv.font);
	sfText_setCharacterSize(text, 24);
	sfText_setPosition(text, postext);
	sfRenderWindow_drawSprite(all->window.window, sprite, NULL);
	sfRenderWindow_drawText(all->window.window, text, NULL);
}