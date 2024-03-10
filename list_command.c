/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "include/server.h"
#include "include/return_error_code.h"
#include "include/check_param.h"

static void do_ls_command(int accept_socket, client_t *client)
{
    FILE *fp = popen("ls -l", "r");
    char buffer[1024];

    dprintf(client->socket, return_error(C150, NULL));
    if (fp == NULL) {
        dprintf(client->socket, return_error(E451, NULL));
        exit(84);
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
        dprintf(accept_socket, "%s", buffer);
    pclose(fp);
    close(accept_socket);
    close(client->clientServer->socket);
    dprintf(client->socket, return_error(C226, NULL));
    exit(0);
}

static void list_command_passive(client_t *client)
{
    int pid;
    int accept_socket = accept(client->clientServer->socket, NULL, NULL);

    check_return_value(accept_socket, ACCEPT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_ls_command(accept_socket, client);
    close(accept_socket);
    close(client->clientServer->socket);
    client->mode = UNKNOW;
}

static void list_command_active(client_t *client, server_t *serv
    __attribute__((unused)))
{
    int pid;
    socklen_t size = sizeof(&client->clientServer->serverAddress);
    int return_value = connect(client->clientServer->socket,
        (struct sockaddr *)client->clientServer->serverAddress, size);

    check_return_value(return_value, CONNECT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_ls_command(client->clientServer->socket, client);
    close(client->clientServer->socket);
    client->mode = UNKNOW;
}

void list_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, NOT_EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    if (client->mode == UNKNOW) {
        dprintf(client->socket, return_error(E425, NULL));
        return;
    }
    if (client->mode == PASSIVE)
        list_command_passive(client);
    else if (client->mode == ACTIVE)
        list_command_active(client, serv);
}
