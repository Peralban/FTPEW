/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** command_command_list.c
*/

#include "include/command.h"
#include "include/check_param.h"

void user_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list)
{
    (void)(server);
    (void)(client_list);
    if (!check_param(command[1], client->socket, EXIST))
        return;
    client->username = strdup(command[1]);
    client->username_is_logged = true;
    dprintf(client->socket, return_error(C331, NULL));
}

void pass_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list)
{
    (void)(server);
    (void)(client_list);
    if (strcmp(client->username, "Anonymous") == 0 && command[1] == NULL) {
        dprintf(client->socket, return_error(C230, NULL));
        client->is_logged = true;
        client->password = strdup("");
        return;
    }
    if (client->username_is_logged == true) {
        dprintf(client->socket, return_error(C332, NULL));
        return;
    }
}

void cwd_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list)
{
    (void)(server);
    (void)(client_list);
    if (client->is_logged == false) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, EXIST))
        return;
    if (strcmp(client->pwd, "/") == 0)
        client->pwd = strdup(client->home);
    if (chdir(command[1]) == -1) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    client->pwd = getcwd(NULL, 0);
    dprintf(client->socket, return_error(C250, NULL));
}

void cdup_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list)
{
    (void)(client_list);
    (void)(server);
    if (client->is_logged == false) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, NOT_EXIST))
        return;
    if (strcmp(client->pwd, "/") == 0) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    if (chdir("..") == -1) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    client->pwd = getcwd(NULL, 0);
    dprintf(client->socket, return_error(C200, NULL));
}

void pwd_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list)
{
    (void) client_list;
    (void) server;
    if (client->is_logged == false) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, NOT_EXIST))
        return;
    dprintf(client->socket, return_error(C257, client->pwd));
}
