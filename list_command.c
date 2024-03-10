/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "include/server.h"
#include "include/return_error_code.h"
#include "include/check_param.h"
#include <dirent.h>

static void do_ls_command(int accept_socket, client_t *client, char *command)
{
    FILE *fp = popen(command, "r");
    char buffer[1024];

    dprintf(client->socket, return_error(C150, NULL));
    if (fp == NULL) {
        dprintf(client->socket, return_error(E451, NULL));
        exit(84);
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
        dprintf(accept_socket, "%s", buffer);
    dprintf(client->socket, return_error(C226, NULL));
    pclose(fp);
    exit(0);
}

static void list_command_passive(client_t *client, char *path)
{
    int pid;
    int accept_socket = accept(client->clientServer->socket, NULL, NULL);
    char *command = strdup("ls -l ");

    if (path != NULL)
        command = strcat(command, path);
    check_return_value(accept_socket, ACCEPT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_ls_command(accept_socket, client, command);
    close(accept_socket);
    close(client->clientServer->socket);
    client->mode = UNKNOW;
}

static void list_command_active(client_t *client, server_t *serv
    __attribute__((unused)), char *path)
{
    int pid;
    socklen_t size = sizeof(struct sockaddr_in);
    int return_value = connect(client->clientServer->socket,
        (struct sockaddr *) (client->clientServer->serverAddress), size);
    char *command = strdup("ls -l ");

    if (path != NULL)
        command = strcat(command, path);
    check_return_value(return_value, CONNECT);
    pid = fork();
    check_return_value(pid, FORK);
    if (pid == 0)
        do_ls_command(client->clientServer->socket, client, command);
    client->mode = UNKNOW;
}

static bool check_path(char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL)
        return false;
    closedir(dir);
    return true;
}

void list_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (command[1] != NULL)
        if (!check_path(command[1])) {
            dprintf(client->socket, return_error(E501, NULL));
            return;
        }
    if (client->mode == UNKNOW) {
        dprintf(client->socket, return_error(E425, NULL));
        return;
    }
    if (client->mode == PASSIVE)
        list_command_passive(client, command[1]);
    else if (client->mode == ACTIVE)
        list_command_active(client, serv, command[1]);
}
