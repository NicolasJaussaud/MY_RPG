/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_rect.c
*/

#include "my.h"

char                    **malloc_char_dd(int y, int x)
{
	char **s = NULL;

	s = malloc(sizeof(char *) * y);
	for (int i = 0; i < y; i++) {
		s[i] = NULL;
		s[i] = malloc(sizeof(char) * x);
	}
	return (s);
}

sfIntRect               fill_rect(char **s)
{
	sfIntRect rect;

	rect.top = my_getnbr(s[0]);
	rect.left = my_getnbr(s[1]);
	rect.width = my_getnbr(s[2]);
	rect.height = my_getnbr(s[3]);
	return (rect);
}

sfIntRect 		get_rect(char *line)
{
	char **s1 = malloc_char_dd(10, 10);
	int i = 0;
	int a = 0;
	sfIntRect rect;

	while (my_strncmp("rect=", line, 5) == 0 && line != NULL)
		line++;
	line += 5;
	for (int t = 0; t < 4; t++) {
		while (line[0] != ';' && line[0] != '\0') {
			s1[t][a] = line[i];
			line++;
			a++;
		}
		s1[t][a] = 0;
		a = 0;
		line++;
	}
	rect = fill_rect(s1);
	return (rect);
}