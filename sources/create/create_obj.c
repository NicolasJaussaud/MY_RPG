/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** create_obj.c
*/

#include "my.h"

window_t 			create_window(void)
{
	window_t window;

	sfVideoMode mode = {1920, 1080, 32};
	window.window = sfRenderWindow_create(mode, "Zombie Survivor",\
	sfTitlebar | sfClose | sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 120);
	return (window);
}

void 				create_object_2(object_t *obj, obj_val_t ov)
{
	obj->sprite = sfSprite_create();
	obj->rect = ov.rect;
	obj->pos = ov.pos;
	obj->old_pos = ov.pos;
	obj->type = ov.type;
	obj->size_max = ov.size_max;
	obj->offset = ov.offset;
}

void				create_object(all_t *all, obj_val_t ov)
{
	object_t *obj = malloc(sizeof(*obj));
	object_t *tmp = all->scenes[all->current_scene].obj;

	create_object_2(obj, ov);
	obj->display = ov.display;
	obj->despawn = ov.despawn;
	obj->spawned = 0;
	obj->next = NULL;
	sfSprite_setColor(obj->sprite, (sfColor){255, 255, 255, ov.opacity});
	sfSprite_setTexture(obj->sprite, ov.texture, sfTrue);
	sfSprite_setTextureRect(obj->sprite, obj->rect);
	sfSprite_setPosition(obj->sprite, obj->pos);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = obj;
}