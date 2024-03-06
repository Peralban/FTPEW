/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server_loop.c
*/

#include "include/server.h"
#include "include/command.h"
#include "include/my.h"

static void new_client(int server_socket, fd_set *readfds,
    client_list_t **list, char *true_path)
{
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket,
    (struct sockaddr *) &client_address, &client_address_length);

    check_return_value(client_socket, ACCEPT);
    add_client_to_list(list, create_client(client_socket,
    &client_address, true_path));
    printf("Connection from %s:%d of %d\n", inet_ntoa(client_address.sin_addr),
    ntohs(client_address.sin_port), (*list)->list_size);
    FD_SET(client_socket, readfds);
}

static char *take_good_buff(char *buffer)
{
    int i = 0;
    char *good_buff = malloc(sizeof(char) * strlen(buffer) + 1);

    if (good_buff == NULL)
        exit(EXIT_FAIL);
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == '\r' && buffer[j + 1] == '\n') {
            good_buff[i] = '\0';
            return (good_buff);
        }
        good_buff[i] = buffer[j];
        i++;
    }
    good_buff[i] = '\0';
    return (good_buff);
}

static void read_client(client_list_t *tmp, fd_set *readfds,
    client_list_t **list, server_t **server)
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
        handle_client_command(&(tmp->client),
        my_str_to_word_array(take_good_buff(buffer), " "), server);
    }
}

static void client_already_connected(fd_set *readfds, client_list_t **list,
    server_t **server)
{
    for (client_list_t *tmp = *list; tmp->client != NULL; tmp = tmp->next) {
        if (FD_ISSET(tmp->client->socket, readfds)) {
            read_client(tmp, readfds, list, server);
        }
        if (tmp->next == NULL)
            break;
    }
}

static void set_all_in_fd(server_t *server, client_list_t *list,
    fd_set *readfds, int *max_fd)
{
    FD_SET(server->socket, readfds);
    *max_fd = server->socket;
    for (client_list_t *tmp = list; tmp->client != NULL; tmp = tmp->next) {
        FD_SET(tmp->client->socket, readfds);
        if (tmp->client->socket > *max_fd) {
            *max_fd = tmp->client->socket;
        }
        if (tmp->next == NULL)
            break;
    }
}

int server_loop(server_t *server)
{
    client_list_t *list = create_client_list();
    fd_set readfds;
    int max_fd = server->socket;
    int select_status;

    while (1) {
        if (FD_ISSET(server->socket, &readfds)) {
            new_client(server->socket, &readfds, &list, server->path);
        }
        FD_ZERO(&readfds);
        set_all_in_fd(server, list, &readfds, &max_fd);
        select_status = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        check_return_value(select_status, SELECT);
        client_already_connected(&readfds, &list, &server);
    }
}
