##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of project
##

CC = gcc

RM = rm -f

NAME	=	unit_test

SRC	=	test_key.c	\
		test_settings.c	\
		tests_map.c	\
		../src/parser/map/parser_map.c	\
		../src/parser/key/parser_key.c	\
		../src/parser/str_to_wordarray.c	\
		../src/parser/settings/parser_settings.c	\

OBJ	= 	$(SRC:%.c=%.o)

CFLAGS	=	-I ../include -I .			\
		-W -Wall -Wshadow -Wextra	\
		-fprofile-arcs -ftest-coverage -fPIC	\

LDFLAGS	=	-lcriterion --coverage	\

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f $(SRC:.c=.gcno)
	$(RM) -f $(SRC:.c=.gcda)
	$(RM) -f $(SRC_UT:.c=.gcno)
	$(RM) -f $(SRC_UT:.c=.gcda)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run: all
			./$(NAME)

.PHONY: clean fclean re all tests_run
