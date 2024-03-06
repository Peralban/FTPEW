/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_strcat.c
*/

#include "my.h"
#include <stdlib.h>

// This strcat function will be reallocated the @param dest.
char *my_strcat(char *dest, char *src)
{
    int len_dest = get_len((void **) &dest, STRING);
    int len_src = get_len((void **) &src, STRING);
    char *new_dest = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (new_dest == NULL)
        return NULL;
    for (int i = 0; i < len_dest; i++)
        new_dest[i] = dest[i];
    for (int i = 0; i < len_src; i++)
        new_dest[i + len_dest] = src[i];
    new_dest[len_dest + len_src] = '\0';
    free(dest);
    return new_dest;
}

char *my_strncat(char *dest, char *src, int n)
{
    int len_dest = get_len((void **) &dest, STRING);
    int len_src = get_len((void **) &src, STRING);
    char *new_dest = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (new_dest == NULL)
        return NULL;
    for (int i = 0; i < len_dest; i++)
        new_dest[i] = dest[i];
    for (int i = 0; i < n && i < len_src; i++)
        new_dest[i + len_dest] = src[i];
    new_dest[len_dest + n] = '\0';
    free(dest);
    return new_dest;
}
