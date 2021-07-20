/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** print_functions
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len += 1;
    }
    return (len);
}

int my_putstr(char *str)
{
    int len = my_strlen(str);

    if ((write(1, str, len)) != len)
        return (84);
    return (0);
}

int my_putchar(char c)
{
    if ((write(1, &c, 1)) != 1)
        return (84);
    return (0);
}

int my_putnbr(int nbr)
{
    if (nbr < 10) {
        if ((my_putchar(nbr + 48)) == 84)
            return (84);
    } else {
        if ((my_putnbr(nbr / 10)) == 84)
            return (84);
        if ((my_putnbr(nbr % 10)) == 84)
            return (84);
    }
    return (0);
}