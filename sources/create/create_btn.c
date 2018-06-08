/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** create_btn.c
*/

#include "my.h"

void 				create_button_2(all_t *all, button_t *button,
btn_val_t bv)
{
	button->shape = sfRectangleShape_create();
	button->pos = bv.pos;
	button->old_pos = bv.pos;
	button->size = bv.size;
	button->rect = bv.rect;
	button->offset = bv.offset;
	button->state = bv.state;
	button->callback = all->fptr[bv.callback].fptr;
	button->display = bv.display;
}

void				create_button(all_t *all, btn_val_t bv)
{
	button_t *button = malloc(sizeof(*button));
	button_t *tmp = all->scenes[all->current_scene].btn;

	create_button_2(all, button, bv);
	button->type = bv.type;
	button->enable = 1;
	button->next = NULL;
	sfRectangleShape_setTexture(button->shape, bv.texture, sfTrue);
	sfRectangleShape_setTextureRect(button->shape, button->rect);
	sfRectangleShape_setPosition(button->shape, button->pos);
	sfRectangleShape_setSize(button->shape, button->size);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = button;
}

void				create_text(all_t *all, txt_val_t tv)
{
	text_t *text = malloc(sizeof(*text));
	text_t *tmp = all->scenes[all->current_scene].txt;

	text->text = sfText_create();
	text->str = my_strcpy(tv.str);
	text->pos = tv.pos;
	text->old_pos = tv.pos;
	text->size = tv.size;
	text->type = tv.type;
	text->display = tv.display;
	text->next = NULL;
	sfText_setColor(text->text, tv.color);
	sfText_setString(text->text, text->str);
	sfText_setFont(text->text, tv.font);
	sfText_setPosition(text->text, text->pos);
	sfText_setCharacterSize(text->text, text->size);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = text;
}