/*
** EPITECH PROJECT, 2018
** ASM_corewar
** File description:
** my_strcmp.c
*/

#include "my.h"

int 			my_strcmp(char *s1, char *s2)
{
	for (int i = 0; i < my_strlen(s1); i++) {
		if (s1[i] != s2[i]) {
			return (0);
		}
	}
	return (1);
}

int 			my_strncmp(char *s1, char *s2, int n)
{
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}