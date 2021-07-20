/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick_proto
*/

#ifndef MATCHSTICK_PROTO_H_
#define MATCHSTICK_PROTO_H_

#include <stdlib.h>

int my_getnbr(char const *str);
int matchstick(int line, int move);
int print_map(char **map);
int my_strlen(char *str);
int my_putstr(char *str);
int my_putnbr(int nbr);
int my_strlen(char *str);
void *my_memset(void *ptn, int value, size_t count);
int is_map_empty(char **map);
int is_winner(int turn);
int is_player_turn(char **map, int turn, int move);
int my_tablen(char **map);
int is_nbr(char *str);
int check_linep(char **linep, char **map, char **nbrp, int move);
int check_nbrp(char **nbrp, char **map, int move, char **linep);
int player_game(char *linep, char *nbrp, char **map);
int print_end(int i, int line, int nbr);
int is_ia_turn(char **map, int *turn, int move);
int is_line_valid(char *linep, char **map);
char *my_strdup(char *dest, char *src);
int my_getline(char **str);

#endif /* MATCHSTICK_PROTO_H_ */