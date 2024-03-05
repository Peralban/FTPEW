/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_arraydup.c
*/

#include "my.h"
#include <stdlib.h>

char **my_arraydup(char **src)
{
    char **dest = NULL;
    int i = 0;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char *) * (get_len((void **) src, STRING) + 1));
    if (dest == NULL)
        return NULL;
    while (src[i] != NULL) {
        dest[i] = my_strdup(src[i]);
        i++;
    }
    dest[i] = NULL;
    return dest;
}
