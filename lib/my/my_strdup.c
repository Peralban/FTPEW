/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (get_len((void **) &src, STRING) + 1));
    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}

char *my_strndup(char *src, int n)
{
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (n + 1));
    if (dest == NULL)
        return NULL;
    my_strncpy(dest, src, n);
    return dest;
}
