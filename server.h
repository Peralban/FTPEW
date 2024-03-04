/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client.h
*/

#pragma once

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    FILE_TRANSFER,
    OTHER
} client_state_t;

typedef struct client_s {
    //Client info
    int socket;
    struct sockaddr_in serverAddress;
    //Type transfer info
    client_state_t state;
    //If file transfer
    char *file_name;
    char *file_content;
    //User info
    bool is_logged;     //If user is logged to the server
    bool is_connected;  //If user is connected to the server
    char *username;
    char *password;
    char *pwd;          //Current directory
    char *home;         //Home directory
} client_t;

typedef struct client_list_s {
    client_t *client;
    struct client_list_s *next;
    struct client_list_s *prev;
} client_list_t;

/**
 * @brief Creates a new client list.
 *
 * This function creates a new client list and returns a pointer to it.
 *
 * @return A pointer to the newly created client list.
 */
client_list_t *create_client_list(void);

/**
 * @brief Creates a new client.
 *
 * This function creates a new client with the given socket and server address.
 *
 * @param socket The socket of the client.
 * @param serverAddress The server address of the client.
 * @return A pointer to the newly created client.
 */
client_t *create_client(int socket, struct sockaddr_in serverAddress);

/**
 * @brief Adds a client to a client list.
 *
 * This function adds a given client to a given client list.
 *
 * @param list A pointer to the client list.
 * @param client A pointer to the client to be added.
 */
void add_client_to_list(client_list_t **list, client_t *client);

/**
 * @brief Removes a client from a client list.
 *
 * This function removes a given client from a given client list.
 *
 * @param list A pointer to the client list.
 * @param client A pointer to the client to be removed.
 */
void remove_client_from_list(client_list_t **list, client_t *client);


/**
 * @brief Removes a client from a client list by socket.
 *
 * This function removes a client from a given client list using the client's socket.
 *
 * @param list A double pointer to the client list.
 * @param socket The socket of the client to be removed.
 */
void remove_client_from_list_by_socket(client_list_t **list, int socket);

/**
 * @brief Retrieves a client from a client list by socket.
 *
 * This function retrieves a client from a given client list using the client's socket.
 *
 * @param list A pointer to the client list.
 * @param socket The socket of the client to be retrieved.
 * @return A pointer to the client if found, NULL otherwise.
 */
client_t *get_client_from_list(client_list_t *list, int socket);