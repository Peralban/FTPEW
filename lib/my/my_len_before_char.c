/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_len_before_char.c
*/

#include "my.h"

int my_len_before_char(char *str, char *delim)
{
    int i = 0;

    while (str[i] != '\0' && !char_is_in_str(str[i], delim))
        i++;
    return i;
}
