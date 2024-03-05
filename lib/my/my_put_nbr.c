/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** process_info
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}

void my_put_nbr_err(int nb)
{
    if (nb < 0) {
        my_putchar_err('-');
        my_put_nbr_err(-nb);
    } else if (nb > 9) {
        my_put_nbr_err(nb / 10);
        my_put_nbr_err(nb % 10);
    } else {
        my_putchar_err(nb + '0');
    }
}
