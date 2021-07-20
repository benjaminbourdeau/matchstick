/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** print_the_map
*/

#include <stdlib.h>
#include "matchstick.h"

int print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        if ((my_putstr(map[i])) == 84)
            return (84);
        if ((my_putstr("\n")) == 84)
            return (84);
    }
    return (0);
}