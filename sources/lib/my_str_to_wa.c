/*
** EPITECH PROJECT, 2018
** ASM_corewar
** File description:
** str_to_wa.c
*/

#include "my.h"

char 			**malloc_wa(char *s)
{
	char **ss = malloc(sizeof(char *) * my_strlen(s));

	for (int i = 0; i < my_strlen(s); i++)
		ss[i] = malloc(sizeof(char) * my_strlen(s));
	return (ss);
}

char 			**my_str_to_wa_hard(char *str)
{
	char **str_tab = malloc_wa(str);
	int i = 0;
	int x = 0;
	int y = 0;

	if (!str)
		return (NULL);
	while (str[i] != 0) {
		if (str[i] == '\n') {
			str_tab[y][x] = 0;
			y++;
			x = 0;
			i++;
		}
		str_tab[y][x++] = str[i++];
	}
	str_tab[y][x] = 0;
	str_tab[++y] = NULL;
	return (str_tab);
}

char 			**my_str_to_wa(char *s)
{
	char **ss = malloc_wa(s);
	int i = 0;
	int x = 0;
	int y = 0;

	while (s[i] != '\0') {
		if ((s[i] == ' ' || s[i] == ',')
		&& (s[i+1] != ' ' && s[i+1] != ',')) {
			ss[y++][++x] = '\0';
			x = 0;
			i++;
		}
		if ((s[i] == ' ' || s[i] == ',')
		&& (s[i+1] == ' ' || s[i+1] == ',')) {
			i++;
		}
		ss[y][x++] = s[i++];
	}
	ss[++y] = NULL;
	return (ss);
}