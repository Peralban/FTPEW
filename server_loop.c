/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server_loop.c
*/

#include "server.h"

static void new_client(int server_socket, fd_set *readfds,
    client_list_t **list)
{
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket,
    (struct sockaddr *) &client_address, &client_address_length);

    check_return_value(client_socket, ACCEPT);
    if (client_socket > FD_SETSIZE) {
        printf("error to socket\n");
        return;
    }
    add_client_to_list(list, create_client(client_socket,
    &client_address));
    printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr),
    ntohs(client_address.sin_port));
    FD_SET(client_socket, readfds);
}

static void read_client(client_list_t *tmp, fd_set *readfds,
    client_list_t **list)
{
    int read_status;
    char buffer[1024];

    read_status = read(tmp->client->socket, buffer, sizeof(buffer));
    check_return_value(read_status, READ);
    if (read_status == 0) {
        printf("Connection closed by client\n");
        FD_CLR(tmp->client->socket, readfds);
        close(tmp->client->socket);
        remove_client_from_list(list, tmp->client);
    } else {
        printf("Received: %s\n", buffer);
    }
}

static void client_already_connected(fd_set *readfds, client_list_t **list)
{
    for (client_list_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        if (FD_ISSET(tmp->client->socket, readfds)) {
            read_client(tmp, readfds, list);
        }
    }
}

int server_loop(int server_socket, struct sockaddr_in *server_address)
{
    client_list_t *list = create_client_list();
    fd_set readfds;
    int max_fd = server_socket;
    int select_status;

    FD_ZERO(&readfds);
    FD_SET(server_socket, &readfds);
    while (1) {
        select_status = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        check_return_value(select_status, SELECT);
        if (FD_ISSET(server_socket, &readfds)) {
            new_client(server_socket, &readfds, &list);
        } else {
            client_already_connected(&readfds, &list);
        }
    }
}
