/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my_strcpy.c
*/

#include "my.h"

char 				*my_strcpy(char *s)
{
	char *ns = malloc(sizeof(char) * 1000);
	int i = 0;

	for (i = 0; i < my_strlen(s); i++)
		ns[i] = s[i];
	ns[i] = '\0';
	return (ns);
}