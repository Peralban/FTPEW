/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
        i++;
    return str1[i] - str2[i];
}

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < n) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    if (i == n)
        return 0;
    return (str1[i] - str2[i]);
}
