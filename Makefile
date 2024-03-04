##
## EPITECH PROJECT, 2023
## FTPEW
## File description:
## Makefile
##

SRC	=	main.c			\
		server.c		\
		client_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

TESTS_SRC = $(filter-out main.c, $(SRC))	\
			tests/test.c					\
			tests/test_error_case.c			\


CFLAGS		=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(TESTS_SRC) $(CFLAGS) --coverage -lcriterion
	./unit_tests
