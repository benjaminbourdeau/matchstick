/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** is_map_empty
*/

#include <stdlib.h>

int is_line_empty(char *line)
{
    int count = 0;

    for (int i = 1; line[i + 1] != '\0'; i++) {
        if (line[i] == '|')
            count++;
    }
    return (count);
}

int is_map_empty(char **map)
{
    int count = 0;

    for (int i = 1; map[i + 1] != NULL; i++) {
        count += is_line_empty(map[i]);
    }
    return (count);
}