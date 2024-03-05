/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client_list_bis.c
*/

#include "include/server.h"

void remove_client_from_list_by_socket(client_list_t **list, int socket)
{
    client_list_t *tmp = *list;
    client_list_t *prev = NULL;

    if (tmp != NULL && tmp->client->socket == socket) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->client->socket != socket) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}

client_t *get_client_from_list(client_list_t *list, int socket)
{
    client_list_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->client->socket == socket)
            return (tmp->client);
        tmp = tmp->next;
    }
    return (NULL);
}
