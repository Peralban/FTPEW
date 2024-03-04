##
## EPITECH PROJECT, 2023
## FTPEW
## File description:
## Makefile
##

SRC	=	server.c		\
		client_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp


CFLAGS		=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
