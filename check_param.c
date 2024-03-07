/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** check_param.c
*/

#include "include/check_param.h"

bool check_param(const char *command, int client_socket, exist_t exist)
{
    if (command == NULL && exist == EXIST) {
        dprintf(client_socket, return_error(E501, NULL));
        return false;
    }
    if (command != NULL && exist == NOT_EXIST) {
        dprintf(client_socket, return_error(E501, NULL));
        return false;
    }
    return true;
}
