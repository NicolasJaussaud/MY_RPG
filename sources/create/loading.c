/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** loading.c
*/

#include "my.h"

void 			init_loadings(sfSprite *loadings, sfSprite *load_bars,
all_t *all)
{
	sfSprite_setTextureRect(load_bars, (sfIntRect){0, 0, 92, 32});
	sfSprite_setPosition(loadings, (sfVector2f){720, 454});
	sfSprite_setPosition(load_bars, (sfVector2f){730, 584});
	sfRenderWindow_drawSprite(all->window.window, loadings, NULL);
	sfRenderWindow_drawSprite(all->window.window, load_bars, NULL);
	sfRenderWindow_display(all->window.window);
}

void 			change_rect_and_display(all_t *all, int rect,
sfSprite *loadings, sfSprite *load_bars)
{
	sfSprite_setTextureRect(load_bars, (sfIntRect){0, 0, rect, 32});
	sfRenderWindow_drawSprite(all->window.window, loadings, NULL);
	sfRenderWindow_drawSprite(all->window.window, load_bars, NULL);
	sfRenderWindow_display(all->window.window);
}

void 			put_type_on_scene_2(all_t *all)
{
	all->scenes[10].type = HOSPITAL;
	all->scenes[11].type = DEATH;
	all->scenes[12].type = LABO;
	all->scenes[13].type = HOSPITAL;
	all->scenes[14].type = HOSPITAL;
	all->scenes[15].type = HTPPOPUP;
	all->scenes[16].type = HTP;
	all->scenes[17].type = PAUSE;
	all->scenes[18].type = PHARMACIE;
	all->scenes[19].type = PHARMACIE;
	all->scenes[20].type = PHARMACIE;
	all->scenes[21].type = SOUND;
	all->scenes[22].type = FIND_ITEM;
	all->scenes[23].type = INTRO;
	all->scenes[24].type = HTP2;
}

void 			put_type_on_scene(all_t *all)
{
	all->scenes[0].type = MENU;
	all->scenes[1].type = GAME;
	all->scenes[2].type = INVENTORY;
	all->scenes[3].type = PROF_DIALOGUE;
	all->scenes[4].type = BOISSONS;
	all->scenes[5].type = NOURRITURES;
	all->scenes[6].type = ARMES;
	all->scenes[7].type = MINIMAP_S;
	all->scenes[8].type = SHOP;
	all->scenes[9].type = CAR;
	put_type_on_scene_2(all);
}

void 			malloc_scenes(all_t *all)
{
	all->scenes = malloc(sizeof(scene_t) * 100);
	for (int i = 0; i < 100; i++) {
		all->scenes[i].obj = init_list_object();
		all->scenes[i].btn = init_list_btn();
		all->scenes[i].txt = init_list_text();
		all->scenes[i].mob = init_list_mob();
	}
}
