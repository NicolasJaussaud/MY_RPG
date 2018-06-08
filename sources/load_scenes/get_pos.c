/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get.c
*/

#include "my.h"

int                     get_pos_x(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("posx=", line, 5) == 0 && line != NULL)
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

int                     get_pos_y(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("posy=", line, 5) == 0 && line != NULL)
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