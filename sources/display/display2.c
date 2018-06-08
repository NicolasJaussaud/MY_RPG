/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** display2.c
*/

#include "my.h"

void 			display_shot(all_t *all)
{
	shot_t *tmp = all->shots;

	while (tmp != NULL) {
		if (all->current_scene == tmp->scene)
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
		tmp = tmp->next;
	}
}

void 			display_obj(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	while (tmp != NULL) {
		if (tmp->display == 1 && tmp->type != HALO)
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
		tmp = tmp->next;
	}
}

void 			display_txt(all_t *all)
{
	text_t *tmp = all->scenes[all->current_scene].txt;

	while (tmp != NULL) {
		if (tmp->display == 1)
			sfRenderWindow_drawText(all->window.window,
			tmp->text, NULL);
		tmp = tmp->next;
	}
}

void 			display_btn(all_t *all)
{
	button_t *tmp = all->scenes[all->current_scene].btn;

	while (tmp != NULL) {
		if (tmp->display == 1)
			sfRenderWindow_drawRectangleShape(all->window.window,
			tmp->shape, NULL);
		tmp = tmp->next;
	}
}

void 			display_mobs(all_t *all)
{
	mob_t *tmp = all->scenes[all->current_scene].mob;

	while (tmp != NULL) {
		sfRenderWindow_drawSprite(all->window.window,
		tmp->sprite, NULL);
		sfRenderWindow_drawSprite(all->window.window,
		tmp->bar_life, NULL);
		tmp = tmp->next;
	}
}