/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server.c
*/

#include "server.h"

static struct sockaddr_in setup_server_address(int port)
{
    struct sockaddr_in srvAdd;

    memset(&srvAdd, 0, sizeof(srvAdd));
    srvAdd.sin_family = AF_INET;
    srvAdd.sin_port = htons(port);
    srvAdd.sin_addr.s_addr = INADDR_ANY;
    return (srvAdd);
}

static void bind_and_listen(int srvsock, struct sockaddr_in *srvAdd)
{
    int listenStatus;
    int bindStatus = bind(srvsock, (struct sockaddr *)srvAdd, sizeof(&srvAdd));

    check_return_value(bindStatus, BIND);
    listenStatus = listen(srvsock, 5);
    check_return_value(listenStatus, LISTEN);
}

int myftp(int ac, char **av)
{
    int srvsock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srvAdd = setup_server_address(atoi(av[1]));

    check_return_value(srvsock, SOCKET);
    bind_and_listen(srvsock, &srvAdd);
    return server_loop(srvsock, &srvAdd);
}
