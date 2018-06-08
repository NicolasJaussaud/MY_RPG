/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** core.c
*/

#include "my.h"

void 				event_management(all_t *all)
{
	while (sfRenderWindow_pollEvent(all->window.window,
	&all->window.event)) {
		if (all->window.event.type == sfEvtClosed)
			sfRenderWindow_close(all->window.window);
		if (all->window.event.type == sfEvtMouseButtonPressed) {
			gestion_click_btn(all);
			all->clicking = 1;
		} else if (all->window.event.type == sfEvtMouseButtonReleased) {
			button_callback_management(all);
			all->clicking = 0;
			all->shotted_one = 0;
		}
		if (all->clicking == 0)
			gestion_hover(all);
	}
}

void 				delete_disable_btn(all_t *all)
{
	button_t *btn = all->scenes[all->current_scene].btn;

	if (!btn)
		return;
	while (btn->next) {
		if (btn->next->enable == 0) {
			free(btn->next);
			btn->next = btn->next->next;
			return;
		}
		btn = btn->next;
	}
}

void 				core_2(all_t *all)
{
	set_rect_btn(all);
	display_scenes(all);
	event_management(all);
	player_movement(all);
	rotation_player(all);
	animation_player(all);
	main_clock_management(all);
	shot_management(all);
	fire_shot(all);
	exp_management(all);
	pathfinding_mob(all);
	management_bar_life_mob(all);
	damage_taken(all);
	hud_management(all);
	stat_management(all);
}

void				do_rain_only_on_map(all_t *all)
{
	if (all->current_scene == 1) {
		if (sfMusic_getStatus(all->sounds[4]) == sfPaused)
			sfMusic_play(all->sounds[4]);
	} else {
		sfMusic_pause(all->sounds[4]);
	}
}

void 				core(all_t *all)
{
	quest_2_management(all);
	do_rain_only_on_map(all);
	core_2(all);
	display_only_near_tp_btn(all);
	halo_centered_on_player(all);
	spawning_management(all);
	despawn_management(all);
	minimap_management(all);
	delete_disable_btn(all);
	gestion_animation_rect(all);
	do_rain(all);
	death_management(all);
	core_3(all);
}
