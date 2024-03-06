/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_putstr.c
*/

#include "my.h"
#include <unistd.h>
#include <string.h>

void my_putstr(char *str)
{
    write(1, str, strlen(str));
}

void my_putstr_err(char *str)
{
    write(2, str, strlen(str));
}
