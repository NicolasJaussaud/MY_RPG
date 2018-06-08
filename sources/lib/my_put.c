/*
** EPITECH PROJECT, 2018
** ASM_corewar
** File description:
** my_put.c
*/

#include "my.h"

void 			my_putchar(char c)
{
	write(1, &c, 1);
}

void 			my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}


void 			my_putnbr(int nb)
{
	int m;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			m = (nb % 10);
			nb = (nb - m) / 10;
			my_putnbr(nb);
			my_putchar(m + 48);
		} else {
			my_putchar(48 + (nb % 10));
		}
	}
}
