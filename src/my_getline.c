/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** my_getline
*/

#include <stdio.h>
#include <sys/types.h>

int my_getline(char **str)
{
    size_t size = 0;
    ssize_t char_read = 0;

    char_read = getline(str, &size, stdin);
    if (char_read == -1)
        return (84);
    return (0);
}