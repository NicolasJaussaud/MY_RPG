/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** hover_management.c
*/

#include "my.h"

int 				button_is_clicked(button_t *tmp,
sfVector2i click_position)
{
	return (click_position.x < (tmp->pos.x + tmp->size.x) &&
		click_position.x > tmp->pos.x &&
		click_position.y < tmp->pos.y + tmp->size.y &&
		click_position.y > tmp->pos.y);
}

void 				gestion_click_btn(all_t *all)
{
	button_t *tmp = all->scenes[all->current_scene].btn;

	while (tmp) {
		if (button_is_clicked(tmp, sfMouse_getPosition
			((const sfWindow*)all->window.window)) == 1 &&
			tmp->state == 1) {
			tmp->rect.left = tmp->offset * 2;
		}
		tmp = tmp->next;
	}
}

void 				set_rect_btn(all_t *all)
{
	button_t *tmp = all->scenes[all->current_scene].btn;

	while (tmp) {
		sfRectangleShape_setTextureRect(tmp->shape, tmp->rect);
		tmp = tmp->next;
	}
}

void 				gestion_hover(all_t *all)
{
	button_t *tmp = all->scenes[all->current_scene].btn;

	while (tmp != NULL) {
		if (button_is_clicked(tmp,
		sfMouse_getPosition((const sfWindow*)\
		all->window.window)) == 1) {
			tmp->rect.left = tmp->offset;
		} else {
			tmp->rect.left = 0;
		}
		sfRectangleShape_setTextureRect(tmp->shape, tmp->rect);
		tmp = tmp->next;
	}
}