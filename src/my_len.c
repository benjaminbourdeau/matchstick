/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** len_functions
*/

#include <stdlib.h>
#include "matchstick.h"

int my_tablen(char **map)
{
    int i = 1;

    while (map[i + 2] != NULL) {
        i++;
    }
    return (i);
}

char *my_strdup(char *dest, char *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src)));
    while (src[i + 1] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}