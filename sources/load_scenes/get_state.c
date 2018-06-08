/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_state.c
*/

#include "my.h"

int                     get_state(char *line)
{
	char *s = NULL;
	int i = 0;
	int nb = 0;

	s = malloc(sizeof(char) * 10);
	while (my_strncmp("state=", line, 6) == 0 && line != NULL)
		line++;
	line += 6;
	while (line[i] != ';') {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nb = my_getnbr(s);
	free(s);
	return (nb);
}