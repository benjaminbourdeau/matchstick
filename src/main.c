/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** main
*/

#include "matchstick.h"

int str_is_nbr(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 48 && str[i] > 57)
            return (84);
    }
    return (0);
}

int error_manage(int ac, char **av, int *first, int *second)
{
    if (ac != 3)
        return (84);
    if ((str_is_nbr(av[1])) == 84)
        return (84);
    if ((str_is_nbr(av[2])) == 84)
        return (84);
    *first = my_getnbr(av[1]);
    *second = my_getnbr(av[2]);
    if (*first <= 1 || *first >= 100)
        return (84);
    if (*second <= 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int first = 0;
    int second = 0;

    if ((error_manage(ac, av, &first, &second)) == 84)
        return (84);
    return (matchstick(first, second));
}
