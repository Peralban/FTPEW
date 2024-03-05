/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "test_include.h"
#include "../include/server.h"

Test(create_client_list, test1)
{
    client_list_t *list = create_client_list();
    if (list->client == NULL && list->next == NULL && list->prev == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_fail();
}

Test(create_client, test2)
{
    struct sockaddr_in *clientAddress = malloc(sizeof(struct sockaddr_in));
    client_t *client = create_client(1, clientAddress, "/");
    if (client->socket == 1 && client->clientAddress == clientAddress &&
    client->state == OTHER && client->file_name == NULL &&
    client->file_content == NULL && client->is_logged == true &&
    client->is_connected == false && client->username == NULL &&
    client->password == NULL && strcmp(client->pwd, "/") == 0 &&
    strcmp(client->home, "/") == 0)
        cr_assert_eq(1, 1);
    else
        cr_assert_fail();
}

Test(add_client_to_list, test3)
{
    client_list_t *list = create_client_list();
    struct sockaddr_in *clientAddress = malloc(sizeof(struct sockaddr_in));
    client_t *client = create_client(1, clientAddress, "/");
    add_client_to_list(&list, client);
    if (list->client->socket == 1 && list->client->clientAddress == clientAddress &&
    list->client->state == OTHER && list->client->file_name == NULL &&
    list->client->file_content == NULL && list->client->is_logged == true &&
    list->client->is_connected == false && list->client->username == NULL &&
    list->client->password == NULL && strcmp(list->client->pwd, "/") == 0 &&
    strcmp(list->client->home, "/") == 0 && list->next == NULL && list->prev == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_fail();
}

Test(remove_client_from_list, test4)
{
    client_list_t *list = create_client_list();
    struct sockaddr_in *clientAddress = malloc(sizeof(struct sockaddr_in));
    client_t *client = create_client(1, clientAddress, "/");
    add_client_to_list(&list, client);
    remove_client_from_list(&list, client);
    if (list->client == NULL && list->next == NULL && list->prev == NULL)
        cr_assert_eq(1, 1);
    else
        cr_assert_fail();
}
