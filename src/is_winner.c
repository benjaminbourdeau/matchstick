/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** is_winner
*/

#include "matchstick.h"

int is_winner(int turn)
{
    if (turn == 0) {
        if ((my_putstr("I lost... snif... but I'll get you next time!!")) == 84)
            return (84);
        if ((my_putstr("\n")) == 84)
            return (84);
    }
    if (turn == 1) {
        if ((my_putstr("You lost, too bad...\n")) == 84)
            return (84);
    }
    return (turn + 1);
}