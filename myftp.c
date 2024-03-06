/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server.c
*/

#include "include/server.h"
#include <unistd.h>

static char *check_error(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport is the port number on which the server socket"
        " listens\n");
        printf("\tpath is the path to the home directory for the Anonymous"
        " user\n");
        exit(EXIT_SUCCESS);
    } else if (ac != 3) {
        write(2, "Invalid number of arguments\n", 28);
        exit(EXIT_FAIL);
    }
    if (chdir(av[2]) == -1) {
        write(2, "Invalid path\n", 13);
        exit(EXIT_FAIL);
    } else {
        return (getcwd(NULL, 0));
    }
}

static void setup_server_address(server_t **server)
{
    (*server)->serverAddress->sin_family = AF_INET;
    (*server)->serverAddress->sin_addr.s_addr = htons(INADDR_ANY);
    (*server)->serverAddress->sin_port = htons((*server)->port);
    if (setsockopt((*server)->socket, SOL_SOCKET, SO_REUSEADDR,
    &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        exit(EXIT_FAIL);
    }
}

static void bind_and_listen(server_t *server)
{
    int listenStatus = 0;
    int bindStatus = bind(server->socket,
    (struct sockaddr *)server->serverAddress, sizeof(*server->serverAddress));

    check_return_value(bindStatus, BIND);
    listenStatus = listen(server->socket, 5);
    check_return_value(listenStatus, LISTEN);
}

int myftp(int ac, char **av)
{
    server_t *server = malloc(sizeof(server_t));

    if (server == NULL)
        exit(EXIT_SUCC);
    server->serverAddress = malloc(sizeof(struct sockaddr_in));
    server->path = check_error(ac, av);
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    server->port = atoi(av[1]);
    check_return_value(server->socket, SOCKET);
    setup_server_address(&server);
    bind_and_listen(server);
    return server_loop(server);
}
