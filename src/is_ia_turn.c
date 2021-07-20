/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** is_ia_turn
*/

#include <stdlib.h>
#include "matchstick.h"

void change_map(char *map, int nbr_move, int max)
{
    int count = 0;

    while (map[max] != '|') {
        max--;
    }
    while (count != nbr_move) {
        map[max] = ' ';
        max--;
        count++;
    }
}

int is_match(char *map, int i, int stock, int move)
{
    int a = 0;

    stock = 0;
    while (i != 0) {
        if (map[i] == '|')
            stock += 1;
        i--;
    }
    if (stock == 0)
        return (-1);
    if ((stock) <= move) {
        a = (random() % stock);
    } else
        a = (random() % move);
    if (a == 0)
        a += 1;
    return (a);
}

int ia_game(int *line_ia, int *nbr_ia, char **map, int move)
{
    int max = my_strlen(map[0]) - 1;
    int n = 0;
    int nbr_move = 0;
    int len = my_tablen(map) + 1;

    while (n != len) {
        nbr_move = is_match(map[n], max, nbr_move, move);
        if (nbr_move == -1) {
            n++;
        } else {
            change_map(map[n], nbr_move, max);
            *line_ia = n;
            *nbr_ia = nbr_move;
            n = len;
        }
    }
    return (0);
}

int is_ia_turn(char **map, int *turn, int move)
{
    int line_ia = 0;
    int nbr_ia = 0;

    if (*turn == 1) {
        if ((my_putstr("\nAI's turn...\n")) == 84)
            return (84);
        if ((ia_game(&line_ia, &nbr_ia, map, move)) == 84)
            return (84);
        if ((print_end(1, line_ia, nbr_ia)) == 84)
            return (84);
        *turn = -1;
    }
    return (0);
}