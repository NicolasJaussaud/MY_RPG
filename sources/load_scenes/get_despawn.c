/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_color.c
*/

#include "my.h"

int 				get_despawn(char *line)
{
	char *s = NULL;
	int i = 0;
	int nbr;

	s = malloc(sizeof(char) * 100);
	while (my_strncmp("despawn=", line, 8) == 0 && line != NULL)
		line++;
	line += 8;
	while (line[i] != ';' && line[i] != 0) {
		s[i] = line[i];
		i++;
	}
	s[i] = 0;
	nbr = my_getnbr(s);
	free(s);
	return (nbr);
}
