##
## EPITECH PROJECT, 2022
## epitech
## File description:
## Makefile
##

SRC = 	my_putstr.c				\
		my_putchar.c			\
		my_strcmp.c				\
		my_strcpy.c				\
		my_arraydup.c			\
		my_put_nbr.c			\
		my_len_before_char.c	\
		char_is_in_str.c		\
		get_nbr_of_char.c		\
		my_put_array.c			\
		my_strdup.c				\
		my_strcat.c				\
		my_start_with.c			\
		my_str_to_word_array.c	\

OBJ	=   $(SRC:.c=.o)

SATAN = -W -Wall -Wextra -Werror -Wshadow

INCLUDE = -I../../include -g

CFLAGS = $(INCLUDE) $(SATAN)

NAME = my

LIB_NAME = libmy.a

all: $(LIB_NAME)

$(LIB_NAME):	$(OBJ)
	@ar rc $(LIB_NAME) $(OBJ)
	@mv libmy.a ../../
	@mkdir -p ../../include
	@cp my.h ../../include

clean:
	@rm -f $(OBJ)

val:
	@ar rc $(LIB_NAME) $(OBJ)
	@mv libmy.a ../../

fclean:	clean
	@rm -f $(LIB_NAME)
	@rm -f libmy.a

re:	fclean all
	@rm -f $(OBJ)
