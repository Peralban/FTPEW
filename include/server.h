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

#define EXIT_FAIL 84
#define EXIT_SUCC 0

typedef enum {
    SOCKET,
    BIND,
    LISTEN,
    SELECT,
    ACCEPT,
    READ,
    WRITE,
    CLOSE,
    FORK,
    CHDIR
} error_type_t;

typedef enum {
    UNKNOW,
    PASSIVE,
    ACTIVE
} transfer_mode_t;


typedef enum {
    FILE_TRANSFER,
    OTHER
} client_state_t;

typedef struct client_s {
    //Client info
    int socket;
    struct sockaddr_in *clientAddress;
    //Type transfer info
    client_state_t state;
    //If file transfer
    char *file_name;
    char *file_content;
    //User info
    bool is_logged;     //If user is logged in
    bool username_is_logged; //If user is connected
    char *username;
    char *password;
    char *true_path;    //The real password
    char *pwd;          //Current directory
    char *home;         //Home directory
    transfer_mode_t mode;
} client_t;

typedef struct client_list_s {
    client_t *client;
    struct client_list_s *next;
    struct client_list_s *prev;
    int list_size;
} client_list_t;

typedef struct server_s {
    char *path;
    int port;
    int socket;
    fd_set readfds;
    struct sockaddr_in *serverAddress;
} server_t;

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
client_t *create_client(int socket, struct sockaddr_in *serverAddress,
    char *true_path);

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
 * @brief Retrieves a client from a client list by socket.
 *
 * This function retrieves a client from a given client list using the client's
 * socket.
 *
 * @param list A pointer to the client list.
 * @param socket The socket of the client to be retrieved.
 * @return A pointer to the client if found, NULL otherwise.
 */
client_t *get_client_from_list(client_list_t *list, int socket);

/**
 * @brief Entry point for the FTP server.
 *
 * This function serves as the entry point for the FTP server. It takes command
 * line arguments
 * as parameters, which could be used for configuration purposes.
 *
 * @param ac The count of command line arguments.
 * @param av The array of command line arguments.
 * @return Returns 0 on successful execution and non-zero on failure.
 */
int myftp(int ac, char **av);

/**
 * @brief Checks the return value of a function and handles errors.
 *
 * This function checks the return value of a function and handles any errors
 * that may have occurred.
 * If the return value indicates an error, the function prints an error message
 * corresponding to the error type and exits the program.
 *
 * @param value_to_check The return value to check.
 * @param error_type The type of error that may have occurred.
 */
void check_return_value(int value_to_check, error_type_t error_type);

/**
 * @brief Main loop for the FTP server.
 *
 * This function serves as the main loop for the FTP server. It takes the
 * server socket and server address
 * as parameters, and continuously listens for and handles client connections.
 *
 * @param server_socket The socket of the server.
 * @return Returns 0 on successful execution and non-zero on failure.
 */
int server_loop(server_t *server);
