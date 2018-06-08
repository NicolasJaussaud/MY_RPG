/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_color.c
*/

#include "my.h"

char 				*get_color(char *line)
{
	char *s = NULL;
	int i = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("color=", line, 6) == 0 && line != NULL)
		line++;
	line += 6;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

int 				get_type(char *line)
{
	char *s = NULL;
	int i = 0;
	int nbr;

	s = malloc(sizeof(char) * 100);
	while (my_strncmp("type=", line, 5) == 0 && line != NULL)
		line++;
	line += 5;
	while (line[i] != ';' && line[i] != 0) {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nbr = my_getnbr(s);
	free(s);
	return (nbr);
}

int 				get_opacity(char *line)
{
	char *s = NULL;
	int i = 0;
	int nbr;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("opacity=", line, 8) == 0 && line != NULL)
		line++;
	line += 8;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nbr = my_getnbr(s);
	free(s);
	return (nbr);
}
