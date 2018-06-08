/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** get_nbr
*/

#include "my.h"

int 			my_getnbr(char *str)
{
	int sign = 0;
	int res = 0;
	int i = 0;

	if (str[0] == '-') {
		sign = -1;
		i = 1;
	} else
		sign = 1;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	res = res * sign;
	return (res);
}
