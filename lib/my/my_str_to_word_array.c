/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static int word_nbr(char *str, char *delim)
{
    int nbr_word = 0;
    bool is_word = false;

    for (int index = 0; str[index] != '\0'; index++) {
        if (char_is_in_str(str[index], delim) == false && is_word == false) {
            nbr_word += 1;
            is_word = true;
        }
        if (char_is_in_str(str[index], delim) == true) {
            is_word = false;
        }
    }
    return nbr_word;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int nbr_word = word_nbr(str, delim);
    int size_str = 0;
    char **array = malloc(sizeof(char *) * (nbr_word + 1));
    int string = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (!char_is_in_str(str[index], delim)) {
            size_str = my_len_before_char(str + index, delim);
            array[string] = malloc(sizeof(char) * size_str + 1);
            my_strncpy(array[string], str + index, size_str);
            array[string][size_str] = '\0';
            index += size_str;
            string += 1;
        }
        if (str[index] == '\0') {
            break;
        }
    }
    array[nbr_word] = NULL;
    return array;
}
