/*
** EPITECH PROJECT, 2017
** file_gestion.c
** File description:
** file_gestion.c
*/

#include "my.h"

char 	*get_file(int fd)
{
	int ret;
	char *buffer = NULL;
	char *file = NULL;

	if (fd == -1)
		exit(84);
	buffer = malloc(sizeof(char) * 4096 + 1);
	while ((ret = read(fd, buffer, 4096)) != 0) {
		if (ret == -1)
			exit(84);
		buffer[ret] = '\0';
		file = my_strcat(file, buffer);
	}
	free(buffer);
	return (file);
}
