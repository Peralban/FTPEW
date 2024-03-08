/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** pasv_port_fct.c
*/

#include "include/command.h"
#include "include/create_passive_server.h"
#include "include/my.h"

static void clear_data(client_t *client)
{
    if (client->mode != UNKNOW) {
        if (client->dataSocket != 0)
            close(client->dataSocket);
        if (client->mode == PASSIVE && client->clientServer->socket)
            close(client->clientServer->socket);
    }
    memset(client->clientServer, 0, sizeof(&(client->clientServer)));
}

static bool check_info(int *parsed_ip)
{
    for (int i = 0; i < 6; i++) {
        if (parsed_ip[i] == -1)
            return false;
    }
    return true;
}

static void pasv_bis(client_t *client, int socket)
{
    char *ipaddress = inet_ntoa(client->clientServer->serverAddress->sin_addr);
    int ip_numbers[4] = {0};
    int port;

    sscanf(ipaddress, "%d.%d.%d.%d", &ip_numbers[0], &ip_numbers[1],
    &ip_numbers[2], &ip_numbers[3]);
    port = ntohs(client->clientServer->serverAddress->sin_port);
    dprintf(client->socket, return_error(C227, "Entering Passive Mode "
    "(%d,%d,%d,%d,%d,%d).\n"), ip_numbers[1], ip_numbers[2],
    ip_numbers[3], port / 256, port % 256);
    client->mode = PASSIVE;
    client->clientServer->socket = socket;
}

void pasv_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    int socket;

    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    if (!check_param(command[1], client->socket, NOT_EXIST)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    clear_data(client);
    socket = create_passive_server();
    check_return_value(socket, SOCKET);
    getsockname(socket, (struct sockaddr *)client->clientServer->serverAddress,
        (socklen_t *)&client->clientServer->serverAddress->sin_port);
    pasv_bis(client, socket);
}

static void create_new_socket(client_t *client, int *parsed_ip)
{
    char ip[16];
    int port = htons(256 * parsed_ip[4] + parsed_ip[5]);

    sprintf(ip, "%d.%d.%d.%d", parsed_ip[0], parsed_ip[1], parsed_ip[2],
        parsed_ip[3]);
    inet_aton(ip, &client->clientServer->serverAddress->sin_addr);
    client->clientServer->serverAddress->sin_port = port;
    client->clientServer->serverAddress->sin_family = AF_INET;
    dprintf(client->socket, return_error(C200, "PORT command successful.\n"));
    client->mode = ACTIVE;
}

void port_command(client_t *client, char **command, server_t *serv
    __attribute__((unused)), client_list_t **client_list
    __attribute__((unused)))
{
    int parsed_ip[6] = {-1, -1, -1, -1, -1, -1};

    if (!client->is_logged) {
        dprintf(client->socket, return_error(E530, NULL));
        return;
    }
    clear_data(client);
    if (!check_param(command[1], client->socket, EXIST) ||
        get_nbr_of_char(command[1], ',') != 5 || sscanf(command[1],
        "%d,%d,%d,%d,%d,%d", &parsed_ip[0], &parsed_ip[1], &parsed_ip[2],
        &parsed_ip[3], &parsed_ip[4], &parsed_ip[5]) == EOF ||
        !check_info(parsed_ip)) {
        dprintf(client->socket, return_error(E501, NULL));
        return;
    }
    return create_new_socket(client, parsed_ip);
}
