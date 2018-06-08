/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_str.c
*/

#include "my.h"

char                            *get_str(char *line)
{
	char *s = NULL;
	int i = 0;

	s = malloc(sizeof(char) * 1000);
	while (my_strncmp("str=", line, 4) == 0 && line != NULL)
		line++;
	line += 4;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	return (s);
}