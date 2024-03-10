/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** retr_stor_list.c
*/

#include "include/server.h"
#include "include/return_error_code.h"
#include "include/check_param.h"

static void do_retr_command(int accept_socket, client_t *client,
    char *file_name)
{
    FILE *file = fopen(file_name, "r");
    char buffer[1];

    if (file == NULL) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    while (fread(buffer, 1, 1, file) > 0)
        write(accept_socket, buffer, 1);
    fclose(file);
    close(accept_socket);
    close(client->clientServer->socket);
    dprintf(client->socket, return_error(C226, NULL));
    exit(0);
}

static void retr_command_passive(client_t *client, char *file_name)
{
    int pid;
    int accept_socket = accept(client->clientServer->socket, NULL, NULL);

    check_return_value(accept_socket, ACCEPT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_retr_command(1, client, file_name);
    close(accept_socket);
    close(client->clientServer->socket);
}

static void retr_command_active(client_t *client,
    server_t *serv __attribute__((unused)))
{
    int pid;
    socklen_t size = sizeof(client->clientServer->serverAddress);
    int accept_socket = connect(client->clientServer->socket,
    (struct sockaddr *)client->clientServer->serverAddress, size);

    check_return_value(accept_socket, CONNECT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_retr_command(accept_socket, client, client->file_name);
    close(accept_socket);
    close(client->clientServer->socket);
}

void retr_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    if (client->mode == UNKNOW) {
        dprintf(client->socket, return_error(E425, NULL));
        return;
    }
    if (client->mode == PASSIVE)
        retr_command_passive(client, command[1]);
    else if (client->mode == ACTIVE)
        retr_command_active(client, serv);
}
