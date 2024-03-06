/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** command.c
*/

#include "include/command.h"
#include "include/server.h"

void handle_client_command(client_t **client, char **command, server_t **serv)
{
    for (int i = 0; i < 2; i++) {
        if (strcmp(command[0], COMMANDS[i].command) == 0) {
            COMMANDS[i].function(*client, command, *serv);
            return;
        }
        if (COMMANDS[i].command == NULL)
            dprintf((*client)->socket, "500 Syntax error, "
                                       "command unrecognized.\r\n");
    }
}
