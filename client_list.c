/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client_list.c
*/

#include "include/server.h"

client_list_t *create_client_list(void)
{
    client_list_t *list = malloc(sizeof(client_list_t));

    list->client = NULL;
    list->next = NULL;
    list->prev = NULL;
    list->list_size = 0;
    return (list);
}

client_t *create_client(int socket, struct sockaddr_in *clientAddress,
    char *true_path)
{
    client_t *client = malloc(sizeof(client_t));

    client->socket = socket;
    client->clientAddress = clientAddress;
    client->state = OTHER;
    client->file_name = NULL;
    client->file_content = NULL;
    client->is_logged = true;
    client->username_is_logged = false;
    client->username = NULL;
    client->password = NULL;
    client->pwd = strdup("/");
    client->home = strdup(true_path);
    client->true_path = strdup(true_path);
    return (client);
}

void add_client_to_list(client_list_t **list, client_t *client)
{
    client_list_t *tmp = *list;

    (*list)->list_size += 1;
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

static void remove_client_bis(client_list_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    free(tmp);
}

void remove_client_from_list(client_list_t **list, client_t *client)
{
    client_list_t *tmp = *list;

    if ((*list)->list_size <= 0)
        return;
    (*list)->list_size -= 1;
    if (tmp != NULL && tmp->client == client) {
        if (tmp->next != NULL)
            *list = tmp->next;
        else
            *list = create_client_list();
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->client != client)
        tmp = tmp->next;
    remove_client_bis(tmp);
}
