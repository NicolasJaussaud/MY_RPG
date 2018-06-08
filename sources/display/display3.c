/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** display3.c
*/

#include "my.h"

void 			display_halo(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (CST != GAME)
		return;

	while (tmp) {
		if (tmp->type == HALO && tmp->display == 1) {
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
		}
		tmp = tmp->next;
	}
}

void 			display_hud(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (CST != GAME && CST != SHOP && CST != HOSPITAL)
		return;
	while (tmp) {
		if (tmp->type > 4 && tmp->type < 8 && tmp->display == 1) {
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
		}
		tmp = tmp->next;
	}
}

void			display_gun(all_t *all, object_t *player)
{
	sfSprite_setTexture(all->gun_s, all->gun_t[all->inv.weapon_select],
	sfTrue);
	if (all->rotation_player == 0) {
		sfSprite_setTextureRect(all->gun_s, (sfIntRect)\
		{71, 0, 71, 57});
		sfSprite_setPosition(all->gun_s,
		(sfVector2f){player->pos.x - 36, player->pos.y + 9});
		sfRenderWindow_drawSprite(all->window.window, all->gun_s,
		NULL);
	} else if (all->rotation_player == 1) {
		sfSprite_setTextureRect(all->gun_s, (sfIntRect){0, 0, 71, 57});
		sfSprite_setPosition(all->gun_s, (sfVector2f)
		{player->pos.x - 4, player->pos.y + 9});
		sfRenderWindow_drawSprite(all->window.window, all->gun_s,
		NULL);
	}

}

void 			display_player(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	while (tmp) {
		if (tmp->type == PLAYER && tmp->display == 1) {
			display_gun(all, tmp);
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
			break;
		}
		tmp = tmp->next;
	}
}

void 			display_rain(all_t *all)
{
	object_t *tmp = all->scenes[all->current_scene].obj;

	while (tmp) {
		if (tmp->type == RAIN && tmp->display == 1) {
			sfRenderWindow_drawSprite(all->window.window,
			tmp->sprite, NULL);
			break;
		}
		tmp = tmp->next;
	}
}
