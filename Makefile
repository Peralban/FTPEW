##
## EPITECH PROJECT, 2023
## FTPEW
## File description:
## Makefile
##

SRC	=	main.c					\
        myftp.c					\
		client_list.c			\
		server_loop.c			\
		check_return_value.c	\
		client_list_bis.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

TESTS_SRC = $(filter-out main.c, $(SRC))	\
			tests/test.c					\
			tests/test_error_case.c			\
			tests/tests_linked_list.c		\


CFLAGS		=	-W -Wall -Wextra -Wshadow

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests*

re:	fclean all

tests_run:
	gcc -o unit_tests $(TESTS_SRC) $(CFLAGS) --coverage -lcriterion
	./unit_tests
