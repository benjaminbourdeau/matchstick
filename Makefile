#
## EPITECH PROJECT, 2021
## 
## File description:
## Makefile
#

SRC_MAIN	=	src/main.c

SRC_TEST	=	src/check_nbrp.c		\
				src/is_ia_turn.c		\
				src/my_len.c			\
				src/my_nbr.c			\
				src/my_print.c			\
				src/is_winner.c			\
				src/my_getnbr.c			\
				src/my_memset.c			\
				src/matchstick.c		\
				src/player_game.c		\
				src/is_map_empty.c		\
				src/is_player_turn.c	\
				src/print_map.c			\
				src/my_getline.c

SRC			=	$(SRC_TEST) $(SRC_MAIN)

TESTS		=	test/test_basic.c

CFLAGS		=	-Wall -Wextra -g

CPPFLAGS	=	-I./include/

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

NAME		=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug:	clean $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) -o unit_tests $(SRC_TEST) $(TESTS) $(CFLAGS) $(CPPFLAGS) -lcriterion --coverage
	./unit_tests --verbose
	$(RM) *.gc*

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*
	$(RM) unit_tests

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run
