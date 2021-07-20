/*
** EPITECH PROJECT, 2020
** MY_GETNBR
** File description:
** my_getnbr.c
*/

#include <stdlib.h>

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int n = 1;

    if (str == NULL)
        return (84);
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            n = n * -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    nb = nb * n;
    return (nb);
}