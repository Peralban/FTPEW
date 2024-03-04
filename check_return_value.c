/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** check_return_value.c
*/

#include "server.h"

void check_return_value(int value_to_check, error_type_t error_type)
{
    if (value_to_check == -1) {
        perror(error_messages[error_type]);
        exit(EXIT_FAILURE);
    }
}
