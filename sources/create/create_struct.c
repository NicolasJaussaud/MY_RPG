/*
** EPITECH PROJECT, 2017
** MY_RPG
** File description:
** create.c
*/

#include "my.h"

sfTexture		**create_textures_guns(void)
{
	sfTexture **t = malloc(sizeof(sfTexture *) * 11);

	t[0] = sfTexture_createFromFile("assets/imgs/icon/glock.png", NULL);
	t[1] = sfTexture_createFromFile("assets/imgs/icon/tec-9.png", NULL);
	t[2] = sfTexture_createFromFile("assets/imgs/icon/uzi.png", NULL);
	t[3] = sfTexture_createFromFile("assets/imgs/icon/beretta.png", NULL);
	t[4] = sfTexture_createFromFile("assets/imgs/icon/famas.png", NULL);
	t[5] = sfTexture_createFromFile("assets/imgs/icon/fn-fal.png", NULL);
	t[6] = sfTexture_createFromFile("assets/imgs/icon/scar.png", NULL);
	t[7] = sfTexture_createFromFile("assets/imgs/icon/spas12.png", NULL);
	t[8] = sfTexture_createFromFile("assets/imgs/icon/aug.png", NULL);
	t[9] = sfTexture_createFromFile("assets/imgs/icon/m4a1.png", NULL);
	t[10] = sfTexture_createFromFile("assets/imgs/icon/rpg.png", NULL);
	return (t);
}

void 			create_all_1(all_t *all)
{
	all->his = create_history();
	all->info = init_info();
	all->current_scene = 0;
	all->old_scene = 1;
	all->pause.init = 0;
	malloc_scenes(all);
	all->wp = init_wp();
	all->clicking = 0;
	all->shotted_one = 0;
	all->shots = init_shots();
	all->clock = create_clock();
	all->player = init_player(all);
	all->fptr = init_fptr();
	all->settings_sound = init_sound();
	all->gun_s = sfSprite_create();
	all->gun_t = create_textures_guns();
	all->rotation_player = -1;
}

void 			read_all_maps(all_t *all)
{
	read_map(all, "assets/maps/map.txt", 1, 32);
	read_map(all, "assets/maps/shop.txt", 8, 16);
	read_map(all, "assets/maps/hospital1.txt", 10, 16);
	read_map(all, "assets/maps/hospital2.txt", 13, 16);
	read_map(all, "assets/maps/hospital3.txt", 14, 16);
	read_map(all, "assets/maps/laboratoire.txt", 12, 16);
	read_map(all, "assets/maps/pharmacie1.txt", 18, 16);
	read_map(all, "assets/maps/pharmacie2.txt", 19, 16);
	read_map(all, "assets/maps/pharmacie3.txt", 20, 16);
}

void 	create_all_2(all_t *all, sfSprite *loadings, sfSprite *load_bars)
{
	initinventory(all);
	initshop(all);
	initshop2(all);
	initshop3(all);
	put_type_on_scene(all);
	change_rect_and_display(all, 276, loadings, load_bars);
	load_textures(all);
	load_sounds(all);
	load_fonts(all);
	change_rect_and_display(all, 368, loadings, load_bars);
	load_scenes(all);
	read_all_maps(all);
	change_rect_and_display(all, 461, loadings, load_bars);
}

all_t			create_all(void)
{
	all_t all;

	srand(time(NULL));
	all.window = create_window();
	sfSprite *loadings = sfSprite_create();
	sfTexture *loadingt =
	sfTexture_createFromFile("assets/imgs/loading/loading.png", NULL);
	sfTexture *load_bart =
	sfTexture_createFromFile("assets/imgs/loading/rect.png", NULL);
	sfSprite *load_bars = sfSprite_create();
	sfSprite_setTexture(loadings, loadingt, sfTrue);
	sfSprite_setTexture(load_bars, load_bart, sfTrue);
	init_loadings(loadings, load_bars, &all);
	change_rect_and_display(&all, 184, loadings, load_bars);
	create_all_1(&all);
	all.map.map = get_map(&all);
	create_all_2(&all, loadings, load_bars);
	return (all);
}