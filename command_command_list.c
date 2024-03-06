/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** command_command_list.c
*/

#include "include/command.h"

static bool check_param(const char *command, int client_socket, exist_t exist)
{
    if (command == NULL && exist == EXIST) {
        dprintf(client_socket, "501 Syntax error in parameters or "
                                "argument.\r\n");
        return false;
    }
    if (command != NULL && exist == NOT_EXIST) {
        dprintf(client_socket, "501 Syntax error in parameters or "
                                "argument.\r\n");
        return false;
    }
    return true;
}

void user_command(client_t *client, char **command, server_t *server)
{
    (void)(server);
    if (!check_param(command[1], client->socket, EXIST))
        dprintf(client->socket, "530 Permission denied.\r\n");
        return;
    }
    client->username = strdup(command[1]);
    client->username_is_logged = true;
    dprintf(client->socket, "331 User name okay, need password.\r\n");
}

void pass_command(client_t *client, char **command, server_t *server)
{
    (void)(server);
    if (strcmp(client->username, "Anonymous") == 0 && command[1] == NULL) {
        dprintf(client->socket, "230 User logged in, proceed.\r\n");
        client->is_logged = true;
        client->password = strdup("");
        return;
    }
    if (client->username_is_logged == true) {
        dprintf(client->socket, "332 Need account for login.\r\n");
        return;
    }
    dprintf(client->socket, "530 Permission denied.\r\n");
}
