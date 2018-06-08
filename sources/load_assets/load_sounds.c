/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_sounds.c
*/

#include "my.h"

void 			create_all_sounds(all_t *all, char **file_dd)
{
	char *path = NULL;

	all->sounds = malloc(sizeof(sfMusic *) * all->nb_sounds);
	for (int i = 0; i < all->nb_sounds; i++) {
		path = get_path(file_dd[i]);
		all->sounds[i] = sfMusic_createFromFile(path);
		free(path);
	}
}

void 			load_sounds(all_t *all)
{
	int fd = open("assets/sounds.snd", O_RDONLY);
	char *file = get_file(fd);
	char **file_dd = my_str_to_wa_hard(file);

	all->nb_sounds = count_lines(file_dd);
	create_all_sounds(all, file_dd);
	close(fd);
	free(file);
	for (int i = 0; file_dd[i]; i++)
		free(file_dd[i]);
	free(file_dd);
}