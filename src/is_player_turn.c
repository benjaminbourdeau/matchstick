/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** is_player_turn
*/

#include <stdio.h>
#include "matchstick.h"

int line_empty(int line_p, char **map)
{
    for (int i = 0; map[line_p][i] != '\0'; i++) {
        if (map[line_p][i] == '|')
            return (0);
    }
    return (84);
}

int is_line_valid(char *linep, char **map)
{
    int line_nbr = my_tablen(map);
    int line_p = 0;

    if ((is_nbr(linep)) == 84) {
        if (my_putstr("Error: invalid input (positive number expected)") == 84)
            return (84);
        if (my_putstr("\n") == 84)
            return (84);
        return (-1);
    }
    line_p = my_getnbr(linep);
    if (line_p > line_nbr || line_p <= 0) {
        if ((my_putstr("Error: this line is out of range\n")) == 84)
            return (84);
        return (-1);
    }
    return (line_p);
}

int check_linep(char **linep, char **map, char **nbrp, int move)
{
    int line_p = 0;
    char *line = NULL;
    int res = 0;

    if ((my_putstr("Line: ")) == 84)
        return (84);
    if ((my_getline(&line)) == 84)
        return (-1);
    *linep = my_strdup(*linep, line);
    line_p = is_line_valid(*linep, map);
    if (line_p == -1) {
        res = check_linep(linep, map, nbrp, move);
        return (res);
    }
    if ((my_putstr("Matches: ")) == 84)
        return (84);
    return (check_nbrp(nbrp, map, move, linep));
}

int is_player_turn(char **map, int turn, int move)
{
    char *linep = NULL;
    char *nbrp = NULL;
    int check_linep_return = 0;

    if (turn == 0) {
        if ((my_putstr("\nYour turn:\n")) == 84)
            return (84);
        check_linep_return = check_linep(&linep, map, &nbrp, move);
        if ((check_linep_return) == 84)
            return (84);
        if ((check_linep_return) == -1)
            return (-1);
        if ((player_game(linep, nbrp, map)) == 84)
            return (84);
    }
    return (0);
}