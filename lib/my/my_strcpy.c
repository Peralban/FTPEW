/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** write a function that copies a string into another.
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (i == n)
        return dest;
    dest[i] = '\0';
    return dest;
}
