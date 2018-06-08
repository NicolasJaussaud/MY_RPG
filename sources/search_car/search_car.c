/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** search_car.c
*/

#include "my.h"

void 			update_scene_car(all_t *all, int qt_random_food,
char *str_random, int random_money)
{
	for (text_t *tmp = all->scenes[9].txt; tmp; tmp = tmp->next) {
		if (tmp->type == CAR_MONEY) {
			free(tmp->str);
			tmp->str = malloc(sizeof(char) * 5);
			tmp->str = my_strcpy("- ");
			my_getcharstar(random_money, str_random);
			tmp->str = my_strcat(tmp->str, str_random);
			sfText_setString(tmp->text, tmp->str);
		}
		if (tmp->type == CAR_FOOD) {
			free(tmp->str);
			tmp->str = malloc(sizeof(char) * 5);
			tmp->str = my_strcpy("- ");
			my_getcharstar(qt_random_food, str_random);
			tmp->str = my_strcat(tmp->str, str_random);
			sfText_setString(tmp->text, tmp->str);
		}
	}
}

void 			search_car(all_t *all)
{
	int random_money = rand_a_b(2, 21);
	int qt_random_food = rand_a_b(1, 3);
	int random_food = rand_a_b(0, 8);
	char *str_random = malloc(sizeof(char) * 10);

	all->player.money += random_money;
	all->inv.tabfood[random_food].nb += qt_random_food;
	update_scene_car(all, qt_random_food, str_random, random_money);
	for (object_t *tmp = all->scenes[9].obj; tmp; tmp = tmp->next)
		if (tmp->type == CAR_FOOD_O)
			sfSprite_setTexture(tmp->sprite, all->textures\
			[random_food + 10], sfTrue);
	all->old_scene = all->current_scene;
	all->current_scene = 9;
}