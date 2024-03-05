/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client_list.c
*/

#include "server.h"

client_list_t *create_client_list(void)
{
    client_list_t *list = malloc(sizeof(client_list_t));

    list->client = NULL;
    list->next = NULL;
    list->prev = NULL;
    return (list);
}

client_t *create_client(int socket, struct sockaddr_in *clientAddress)
{
    client_t *client = malloc(sizeof(client_t));

    client->socket = socket;
    client->clientAddress = clientAddress;
    client->state = OTHER;
    client->file_name = NULL;
    client->file_content = NULL;
    client->is_logged = true;
    client->is_connected = false;
    client->username = NULL;
    client->password = NULL;
    client->pwd = strdup("/");
    client->home = strdup("/");
    return (client);
}

void add_client_to_list(client_list_t **list, client_t *client)
{
    client_list_t *tmp = *list;

    if ((*list)->client == NULL) {
        (*list)->client = client;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = malloc(sizeof(client_list_t));
        if (tmp->next == NULL) {
            return;
        }
        tmp->next->client = client;
        tmp->next->next = NULL;
        tmp->next->prev = tmp;
    }
}

void remove_client_from_list(client_list_t **list, client_t *client)
{
    client_list_t *tmp = *list;
    client_list_t *prev = NULL;

    if (tmp != NULL && tmp->client == client) {
        if (tmp->next != NULL)
            *list = tmp->next;
        else
            *list = create_client_list();
        free(tmp);
        return;
    } while (tmp != NULL && tmp->client != client) {
        prev = tmp->prev;
        tmp = tmp->next;
    } if (tmp == NULL)
        return;
    tmp->next->prev = prev;
    if (prev != NULL)
        prev->next = tmp->next;
    free(tmp);
}
