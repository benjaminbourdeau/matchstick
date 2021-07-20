/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick_principal_function
*/

#include <stdlib.h>
#include "matchstick.h"

char **pipe_in_map(char **map, int line)
{
    int y = 1;
    int x = (line);
    int count = 1;

    while (y != (line + 1)) {
        my_memset(&map[y][x], '|', (sizeof(char) * count));
        y++;
        x--;
        count += 2;
    }
    return (map);
}

char **space_in_map(char **map, int line)
{
    int y = 1;

    while (map[y + 1] != NULL) {
        my_memset(&map[y][1], ' ', (sizeof(char) * (line * 2 - 1)));
        y++;
    }
    return (map);
}

char **fill_map(char **map, int line)
{
    int i = 0;

    while (i != (line + 2)) {
        map[i] = malloc(sizeof(char) * (line * 2 + 2));
        my_memset(map[i], '*', (sizeof(char) * (line * 2 + 1)));
        map[i][(line * 2 + 1)] = '\0';
        i++;
    }
    map[i] = NULL;
    map = space_in_map(map, line);
    map = pipe_in_map(map, line);
    return (map);
}

int matchstick(int line, int move)
{
    int nbr = 1;
    int is_p_turn_return = 0;
    char **map = malloc(sizeof(char *) * (line + 2));

    map = fill_map(map, line);
    for (int turn = 0; nbr != 0; turn += 1) {
        nbr = is_map_empty(map);
        if ((print_map(map)) == 84)
            return (84);
        if (nbr == 0)
            return (is_winner(turn));
        is_p_turn_return = is_player_turn(map, turn, move);
        if ((is_p_turn_return) == 84)
            return (84);
        if ((is_p_turn_return) == -1)
            return (0);
        if ((is_ia_turn(map, &turn, move)) == 84)
            return (84);
    }
    return (0);
}