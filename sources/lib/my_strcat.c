/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** my_strcat.c
*/

#include "my.h"

char 		*my_strcat(char *s1, char *s2)
{
	int i = 0;
	int a = 0;
	char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

	for (int j = 0; j < my_strlen(s1) + my_strlen(s2) + 1; j++)
		new[j] = '\0';
	if (s1 != NULL) {
		while (s1[i] != '\0') {
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL) {
		while (s2[a] != '\0') {
			new[i] = s2[a];
			i++;
			a++;
		}
	}
	return (new);
}
