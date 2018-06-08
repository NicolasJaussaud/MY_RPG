/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** load_textures.c
*/

#include "my.h"

int 			count_lines(char **ss)
{
	int i = 0;

	for (; ss[i] != NULL; i++);
	return (i);
}

char 			*get_path(char *s)
{
	char *ns = NULL;
	int i = 0;

	ns = malloc(sizeof(char) * my_strlen(s));
	while (s[i] != ' ' && s[i] != '\0' && s[i] != '\t') {
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

void 			create_all_textures(all_t *all, char **file_dd)
{
	char *path = NULL;

	all->textures = malloc(sizeof(sfTexture *) * all->nb_textures);
	for (int i = 0; i < all->nb_textures; i++) {
		path = get_path(file_dd[i]);
		all->textures[i] = sfTexture_createFromFile(path, NULL);
		free(path);
	}
}

void 			load_textures(all_t *all)
{
	int fd = open("assets/textures.txrs", O_RDONLY);
	char *file = get_file(fd);
	char **file_dd = my_str_to_wa_hard(file);

	all->nb_textures = count_lines(file_dd);
	create_all_textures(all, file_dd);
	close(fd);
	free(file);
	for (int i = 0; file_dd[i]; i++)
		free(file_dd[i]);
	free(file_dd);
}