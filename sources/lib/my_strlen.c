/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** counts and returns the numbers of characters
*/

#include "my.h"

int 	my_strlen(char *str)
{
	int t = 0;

	if (str == NULL)
		return (0);
	while (str[t] != '\0')
		t = t + 1;
	return (t);
}
