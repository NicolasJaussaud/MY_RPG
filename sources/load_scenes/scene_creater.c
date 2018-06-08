/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** asset_loader.c
*/

#include "my.h"

void 			get_id_scene(all_t *all, char *line)
{
	char *s = my_strcpy(line);

	s+=3;
	all->scenes[all->current_scene].id = my_getnbr(s);
}

void 			parser_scenes(char **file, int *y, all_t *all)
{
	while (file[*y][0] != '}' && file[*y] != NULL) {
		if (my_strncmp(file[*y], "obj:", 4) == 1) {
			parser_obj(all, file[*y]);
		} else if (my_strncmp(file[*y], "txt:", 4) == 1) {
			parser_txt(all, file[*y]);
		} else if (my_strncmp(file[*y], "btn:", 4) == 1) {
			parser_btn(all, file[*y]);
		} else if (my_strncmp(file[*y], "ID:", 3) == 1) {
			get_id_scene(all, file[*y]);
		}
		(*y)++;
	}
}

void 			parser(char **file, all_t *all)
{
	int y = 0;
	while (file[y] != NULL) {
		if (file[y][0] == '{') {
			parser_scenes(file, &y, all);
			y++;
			all->current_scene++;
			all->nb_scenes++;
		}
		if (file[y] == NULL)
			return;
		y++;
	}
}

void 			load_scenes(all_t *all)
{
	char **file = file_create();
	parser(file, all);
	for (int i = 0; file[i]; i++)
		free(file[i]);
	free(file);
}


char			**file_create(void)
{
	int fd = open("assets/scenes.scenes", O_RDONLY);
	char *file = get_file(fd);
	char **file_dd = my_str_to_wa_hard(file);
	free(file);
	return (file_dd);
}
