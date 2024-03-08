/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** quit_dele_help_noop_fct.c
*/

#include "include/command.h"
#include "include/return_error_code.h"
#include "include/server.h"
#include "include/check_param.h"
#include "include/help_message.h"

void quit_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list)
{
    if (!check_param(command[1], client->socket, NOT_EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    dprintf(client->socket, return_error(C221, NULL));
    close(client->socket);
    remove_client_from_list(client_list, client);
    FD_CLR(client->socket, &(serv->readfds));
}

void noop_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (!check_param(command[1], client->socket, NOT_EXIST))
        dprintf(client->socket, return_error(E501, NULL));
    else
        dprintf(client->socket, return_error(C200, NULL));
}

void help_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    printf("help_command\n");
    if (!check_param(command[1], client->socket, NOT_EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    dprintf(client->socket, help_message);
    dprintf(client->socket, return_error(C214, NULL));
}

void dele_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (client->is_logged == false) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    if (remove(command[1]) == -1) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    dprintf(client->socket, return_error(C250, NULL));
}
