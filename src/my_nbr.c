/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** nbr_functions
*/

int is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (84);
    }
    return (0);
}