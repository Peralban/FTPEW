/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "include/server.h"
#include "include/return_error_code.h"
#include "include/check_param.h"
#include <fcntl.h>

static void do_stor_command(int accept_socket, client_t *client,
    char *file_name)
{
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[1024];
    int size = 1;

    dprintf(client->socket, return_error(C150, NULL));
    if (fd == -1) {
        dprintf(client->socket, return_error(E550, NULL));
        return;
    }
    for (; size > 0; size = read(accept_socket, buffer, 1024)) {
        buffer[size] = '\0';
        dprintf(fd, "%s", buffer);
    }
    close(fd);
    close(accept_socket);
    dprintf(client->socket, return_error(C226, NULL));
    exit(0);
}

static void stor_command_passive(client_t *client, char *file_name)
{
    int pid;
    int accept_socket = accept(client->clientServer->socket, NULL, NULL);

    check_return_value(accept_socket, ACCEPT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_stor_command(accept_socket, client, file_name);
    close(accept_socket);
    close(client->clientServer->socket);
    client->mode = UNKNOW;
}

static void stor_command_active(client_t *client, server_t *serv
    __attribute__((unused)), char *file_name)
{
    int pid;
    socklen_t size = sizeof(struct sockaddr_in);
    int return_value = connect(client->clientServer->socket,
    (struct sockaddr *) (client->clientServer->serverAddress), size);

    check_return_value(return_value, CONNECT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_stor_command(client->clientServer->socket, client, file_name);
    client->mode = UNKNOW;
}

void stor_command(client_t *client, char **command, server_t *serv
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
        stor_command_passive(client, command[1]);
    else if (client->mode == ACTIVE)
        stor_command_active(client, serv, command[1]);
}
