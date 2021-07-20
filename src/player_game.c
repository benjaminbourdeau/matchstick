/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** player_game
*/

#include "matchstick.h"

int is_last_matches(int line_p, char **map)
{
    int i = 1;

    while (map[line_p][i + 1] != '\0') {
        i++;
    }
    while (map[line_p][i] != '|') {
        i--;
    }
    return (i);
}

int print_end(int who, int line, int nbr)
{
    if (who == 0) {
        if ((my_putstr("Player removed ")) == 84)
            return (84);
    } else {
        if ((my_putstr("Ai removed ")) == 84)
            return (84);
    }
    if ((my_putnbr(nbr)) == 84)
        return (84);
    if ((my_putstr(" match(es) from line ")) == 84)
        return (84);
    if ((my_putnbr(line)) == 84)
        return (84);
    if ((my_putstr("\n")) == 84)
        return (84);
    return (0);
}

int player_game(char *linep, char *nbrp, char **map)
{
    int line_p = my_getnbr(linep);
    int nbr_p = my_getnbr(nbrp);
    int i = 0;

    i = is_last_matches(line_p, map);
    for (int count = 0; count != nbr_p; count++) {
        if (map[line_p][i] == '|')
            map[line_p][i] = ' ';
        i--;
    }
    if ((print_end(0, line_p, nbr_p)) == 84)
        return (84);
    return (0);
}