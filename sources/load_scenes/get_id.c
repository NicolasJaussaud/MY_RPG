/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_id.c
*/

#include "my.h"

int                     get_texture_id(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("texture_id=", line, 11) == 0 && line != NULL)
		line++;
	line += 11;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int                     get_font_id(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("font_id=", line, 8) == 0 && line != NULL)
		line++;
	line += 8;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int                     get_func_id(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("func=", line, 5) == 0 && line != NULL)
		line++;
	line += 5;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int 			get_id(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("id=", line, 3) == 0 && line != NULL)
		line++;
	line += 3;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int 			get_display(char *line)
{
	while (my_strncmp("display=", line, 8) == 0 && line[0] != 0)
		line++;
	line += 8;
	if (line[0] == '0')
		return (0);
	else if (line[0] == '1')
		return (1);
	return (0);

}