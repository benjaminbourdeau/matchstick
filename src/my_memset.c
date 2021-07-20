/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** my_memset
*/

#include <stdlib.h>

void *my_memset(void *ptn, int value, size_t count)
{
    unsigned char *dst = ptn;
    while (count > 0) {
        *dst = (unsigned char) value;
        dst++;
        count--;
    }
    return (ptn);
}
