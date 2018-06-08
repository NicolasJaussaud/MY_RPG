/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** read_map.c
*/

#include "my.h"

int 				**char_dd_to_int_dd(char **map, int len_x,
int len_y)
{
	int **map_int = malloc(sizeof(int *) * len_y);

	for (int i = 0; i < len_y; i++)
		map_int[i] = malloc(sizeof(int) * len_x);
	for (int i = 0; i < len_y; i++)
		for (int j = 0; j < len_x; j++)
			map_int[i][j] = map[i][j] - 48;
	return (map_int);
}

int 				get_len_y(char **map)
{
	int i = 0;

	for (; map[i] != NULL; i++);
	return (i);
}

int 				**get_map(all_t *all)
{
	int **map_int = NULL;
	int fd = open("assets/maps/map.txt", O_RDONLY);
	char *map = get_file(fd);
	char **map2d = my_str_to_wa_hard(map);

	all->map.len_x = my_strlen(map2d[0]);
	all->map.len_y = get_len_y(map2d);
	map_int = char_dd_to_int_dd(map2d, all->map.len_x, all->map.len_y);
	return (map_int);
}