/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** read_shop_map.c
*/

#include "my.h"

void 				create_obj_with_map_core(int i, int j,
all_t *all, int block_size, int **map_int)
{
	obj_val_t ov;

	if (map_int[i][j] == 1) {
		ov.rect = (sfIntRect){0, 0, block_size, block_size};
		ov.size_max = 0;
		ov.offset = 0;
		ov.pos.x = block_size * j;
		ov.pos.y = block_size * i;
		ov.type = OBJ;
		ov.opacity = 100;
		ov.display = 0;
		ov.texture = all->textures[8];
		create_object(all, ov);
	}
}

void 				create_obj_with_map(int **map_int, int size[2],
int scene, all_t *all, int block_size)
{
	all->current_scene = scene;
	for (int i = 0; i < size[1]; i++) {
		for (int j = 0; j < size[0]; j++)
			create_obj_with_map_core(i, j, all,
			block_size, map_int);
	}
	all->current_scene = 0;
}

void 				read_map(all_t *all, char *path, int scene,
int block_size)
{
	int **map_int = NULL;
	int fd = open(path, O_RDONLY);
	char *map = get_file(fd);
	char **map2d = my_str_to_wa_hard(map);
	int size[2];

	size[0] = my_strlen(map2d[0]);
	size[1] = get_len_y(map2d);
	map_int = char_dd_to_int_dd(map2d, size[0], size[1]);
	create_obj_with_map(map_int, size, scene, all, block_size);
	close(fd);
}