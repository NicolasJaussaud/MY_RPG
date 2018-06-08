/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_linked_list.c
*/

#include "my.h"

object_t 			*init_list_object(void)
{
	object_t *obj = malloc(sizeof(*obj));

	obj->sprite = sfSprite_create();
	obj->next = NULL;
	obj->type = 999;
	return (obj);
}

button_t 			*init_list_btn(void)
{
	button_t *button = malloc(sizeof(*button));

	button->shape = sfRectangleShape_create();
	button->callback = NULL;
	button->next = NULL;
	return (button);
}

text_t 				*init_list_text(void)
{
	text_t *text = malloc(sizeof(*text));

	text->text = sfText_create();
	text->next = NULL;
	text->type = 999;
	return (text);
}

mob_t 				*init_list_mob(void)
{
	mob_t *mob = malloc(sizeof(*mob));
	mob->sprite = sfSprite_create();
	mob->bar_life = sfSprite_create();
	mob->pos = (sfVector2f){-10000, -10000};
	mob->health = 100;
	mob->next = NULL;
	return (mob);
}

shot_t 				*init_shots(void)
{
	shot_t *shot = malloc(sizeof(*shot));

	shot->sprite = sfSprite_create();
	shot->next = NULL;
	shot->hit = 0;
	return (shot);
}
