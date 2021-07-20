/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** check_nbrp
*/

#include <stdio.h>
#include "matchstick.h"

int is_nbr_matches(int line_p, char **map)
{
    int count = 0;

    for (int i = 1; map[line_p][i + 1] != '\0'; i++) {
        if (map[line_p][i] == '|')
            count += 1;
    }
    return (count);
}

int is_error(int nbr_p, int move, int line_p, char **map)
{
    if (nbr_p == 0) {
        if ((my_putstr("Error: you have to remove at list one match\n")) == 84)
            return (84);
        return (-1);
    }
    if (nbr_p > move) {
        if ((my_putstr("Error: you cannot remove more than ")) == 84)
            return (84);
        if ((my_putnbr(move)) == 84)
            return (84);
        if ((my_putstr(" matches per turn\n")) == 84)
            return (84);
        return (-1);
    }
    if (nbr_p > (is_nbr_matches(line_p, map))) {
        if ((my_putstr("Error: not enough matches on this line\n")) == 84)
            return (84);
        return (-1);
    }
    return (0);
}

int is_nbr_valid(int line_p, int move, char *nbrp, char **map)
{
    int nbr_p = 0;
    int error = 0;

    if ((is_nbr(nbrp)) == 84) {
        if (my_putstr("Error: invalid input (positive number expected)") == 84)
            return (84);
        if (my_putstr("\n") == 84)
            return (84);
        return (-1);
    }
    nbr_p = my_getnbr(nbrp);
    error = is_error(nbr_p, move, line_p, map);
    if (error != 0)
        return (error);
    return (nbr_p);
}

int check_nbrp(char **nbrp, char **map, int move, char **linep)
{
    int nbr_p = 0;
    int line_p = is_line_valid(*linep, map);
    char *nbr = NULL;

    if ((my_getline(&nbr)) == 84)
        return (-1);
    *nbrp = my_strdup(*nbrp, nbr);
    nbr_p = is_nbr_valid(line_p, move, *nbrp, map);
    if (nbr_p == -1) {
        if ((check_linep(linep, map, nbrp, move)) == 84)
            return (84);
    }
    return (0);
}