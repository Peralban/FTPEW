/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** command.c
*/

#include "include/command.h"
#include "include/server.h"
#include "include/return_error_code.h"

void handle_client_command(client_t **client, char **command, server_t **serv,
    client_list_t **client_list)
{
    for (int i = 0; i < 15; i++) {
        if (COMMANDS[i].command == NULL || command[0] == NULL) {
            dprintf((*client)->socket, return_error(E500, NULL));
            return;
        }
        if (strcmp(command[0], COMMANDS[i].command) == 0) {
            COMMANDS[i].function(*client, command, *serv, client_list);
            return;
        }
    }
}
