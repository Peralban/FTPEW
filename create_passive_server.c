/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** create_passive_server.h
*/

#include "include/create_passive_server.h"

static int create_socket(void)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    check_return_value(fd, SOCKET);
    check_return_value(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt,
    sizeof(int)), SETSOCKOPT);
    return fd;
}

int create_passive_server(void)
{
    int fd = create_socket();
    struct sockaddr_in serverAddress = {0};
    int bindStatus = 0;
    int listenStatus = 0;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htons(INADDR_ANY);
    serverAddress.sin_port = htons(6969);
    bindStatus = bind(fd, (struct sockaddr *)&serverAddress,
    sizeof(serverAddress));
    check_return_value(bindStatus, BIND);
    listenStatus = listen(fd, 5);
    check_return_value(listenStatus, LISTEN);
    return fd;
}
