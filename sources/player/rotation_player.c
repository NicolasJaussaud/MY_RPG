/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** rotation_player.c
*/

#include "my.h"

void 				calcul_angle_2(all_t *all, sfVector2f posf)
{
	if ((posf.x == 0) && (posf.y > 0))
		all->player.angle = M_PI/2;
	else if ((posf.x == 0) && (posf.y < 0))
		all->player.angle = (3 * M_PI) / 2;
}

void 				calcul_angle_1(all_t *all, sfVector2f posf)
{
	if (posf.x > 0 && posf.y >= 0)
		all->player.angle = atan(posf.y/posf.x) * (180/M_PI);
	else if (posf.x > 0 && posf.y < 0)
		all->player.angle =
		(atan(posf.y/posf.x) + 2 * M_PI) * (180/M_PI);
	else if (posf.x < 0)
		all->player.angle = (atan(posf.y/posf.x) + M_PI) * (180/M_PI);
}

void 				calcul_wich_sprite_with_angle_1(all_t *all,
object_t *tmp)
{
	if (all->player.angle > 315 || all->player.angle < 45) {
		tmp->rect.top = 142;
		all->rotation_player = 0;
	} else if (all->player.angle > 45 && all->player.angle < 135) {
		tmp->rect.top = 213;
		all->rotation_player = -1;
	}
}

void 				calcul_wich_sprite_with_angle_2(all_t *all,
object_t *tmp)
{
	if (all->player.angle > 135 && all->player.angle < 225) {
		tmp->rect.top = 71;
		all->rotation_player = 1;
	} else if (all->player.angle > 225 && all->player.angle < 315) {
		tmp->rect.top = 0;
		all->rotation_player = -1;
	}
}

void	 			rotation_player(all_t *all)
{
	sfVector2f posf;
	sfVector2i posMouse;
	object_t *tmp = all->scenes[all->current_scene].obj;

	if (PLAYING_SCENE) {
		while (tmp != NULL && tmp->type != PLAYER)
			tmp = tmp->next;
		posMouse =
		sfMouse_getPosition((const sfWindow *)all->window.window);
		posf.x = tmp->pos.x - posMouse.x;
		posf.y = tmp->pos.y - posMouse.y;
		calcul_angle_1(all, posf);
		calcul_angle_2(all, posf);
		calcul_wich_sprite_with_angle_1(all, tmp);
		calcul_wich_sprite_with_angle_2(all, tmp);
		sfSprite_setTextureRect(tmp->sprite, tmp->rect);
	}
}
