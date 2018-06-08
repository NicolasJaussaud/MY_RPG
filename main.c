/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** main.c
*/

#include "my.h"

double 				frand_a_b(double a, double b)
{
	return ((rand()/(double)RAND_MAX ) * (b-a) + a);
}

int				rand_a_b(int a, int b)
{
	return (rand()%(b-a) +a);
}

void 				go_back_to_last_scene(all_t *all)
{
	if (NOT_ECHAP)
		all->current_scene = all->old_scene;

}

void 				keyboard_touch(all_t *all)
{
	if (sfKeyboard_isKeyPressed(sfKeyM) && (PLAYING_SCENE))
		go_to_scene_7(all);
	if (sfKeyboard_isKeyPressed(sfKeyI) && (PLAYING_SCENE))
		go_to_scene_2(all);
	if (sfKeyboard_isKeyPressed(sfKeyEscape) && (CAN_ESCAPE_SCENE))
		go_back_to_last_scene(all);
	if (sfKeyboard_isKeyPressed(sfKeyN))
		display_obstacles(all);
	if (sfKeyboard_isKeyPressed(sfKeyP) && (PLAYING_SCENE)) {
		if (all->pause.init == 0)
			all->pause.old_scene = all->current_scene;
		all->current_scene = 17;
		all->pause.init = 1;
	}
}

int				main(void)
{
	all_t all = create_all();
	all.current_scene = 0;
	all.his.step_h = 0;
	all.player.money = 0;

	sfMusic_setLoop(all.sounds[4], sfTrue);
	sfMusic_play(all.sounds[4]);
	while (sfRenderWindow_isOpen(all.window.window)) {
		core(&all);
		keyboard_touch(&all);
		if (all.current_scene != 17 && all.current_scene != 9
		&& all.current_scene != 3 && all.current_scene != 2
		&& all.current_scene != 7)
			all.pause.init = 0;
	}
	return (0);
}