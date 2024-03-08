/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "include/server.h"
#include "include/return_error_code.h"
#include "include/check_param.h"

void stor_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (check_param(command[1], client->socket, EXIST) == 0) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    if (client->mode == UNKNOW) {
        dprintf(client->socket, return_error(E425, NULL));
        return;
    }
}
