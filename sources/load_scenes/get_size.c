/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_size.c
*/

#include "my.h"

int                     get_size_x(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("size_x=", line, 6) == 0 && line != NULL)
		line++;
	line += 7;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int                     get_size_y(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("size_y=", line, 6) == 0 && line != NULL)
		line++;
	line += 7;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int                     get_size_max(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("size_max=", line, 9) == 0 && line != NULL)
		line++;
	line += 9;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}

int                     get_size(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("size=", line, 5) == 0 && line != NULL)
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