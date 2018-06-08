/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_sounds.c
*/

#include "my.h"

void 			create_all_fonts(all_t *all, char **file_dd)
{
	char *path = NULL;

	all->fonts = malloc(sizeof(sfFont *) * all->nb_fonts);
	for (int i = 0; i < all->nb_fonts; i++) {
		path = get_path(file_dd[i]);
		all->fonts[i] = sfFont_createFromFile(path);
		free(path);
	}
}

void 			load_fonts(all_t *all)
{
	int fd = open("assets/fonts.fts", O_RDONLY);
	char *file = get_file(fd);
	char **file_dd = my_str_to_wa_hard(file);

	all->nb_fonts = count_lines(file_dd);
	create_all_fonts(all, file_dd);
	close(fd);
	free(file);
	for (int i = 0; file_dd[i]; i++)
		free(file_dd[i]);
	free(file_dd);
}