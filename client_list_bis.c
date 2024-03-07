/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client_list_bis.c
*/

#include "include/server.h"

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
