/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** my_put_array.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdbool.h>

void my_put_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
