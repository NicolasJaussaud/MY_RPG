/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** get_sf_color.c
*/

#include "my.h"

void	 			get_sf_color1(char *s, sfColor *color)
{
	if (my_strcmp(s, "black") == 1)
		*color = sfBlack;
	else if (my_strcmp(s, "white") == 1)
		*color = sfWhite;
	else if (my_strcmp(s, "red") == 1)
		*color = sfRed;
}

void 				get_sf_color2(char *s, sfColor *color)
{
	if (my_strcmp(s, "green") == 1)
		*color = sfGreen;
	else if (my_strcmp(s, "blue") == 1)
		*color = sfBlue;
	else if (my_strcmp(s, "yellow") == 1)
		*color = sfYellow;
}

void 				get_sf_color3(char *s, sfColor *color)
{
	if (my_strcmp(s, "magenta") == 1)
		*color = sfMagenta;
	else if (my_strcmp(s, "cyan") == 1)
		*color = sfCyan;
}

sfColor 			get_sf_color(char *s)
{
	sfColor color;

	get_sf_color1(s, &color);
	get_sf_color2(s, &color);
	get_sf_color3(s, &color);
	return (color);
}