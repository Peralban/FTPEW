/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server.c
*/

#include "server.h"

static void check_return_value(int value_to_check, error_type_t error_type)
{
    if (value_to_check == -1) {
        perror(error_messages[error_type]);
        exit(EXIT_FAILURE);
    }
}

static struct sockaddr_in setup_server_address(int port)
{
    struct sockaddr_in serverAddress;

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return (serverAddress);
}

static void bind_and_listen(int tcpSocket, struct sockaddr_in serverAddress)
{
    int bindStatus = bind(tcpSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    check_return_value(bindStatus, BIND);
    int listenStatus = listen(tcpSocket, 5);
    check_return_value(listenStatus, LISTEN);
}

int myftp(int ac, char **av)
{
    int tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
    fd_set readfds;
    check_return_value(tcpSocket, SOCKET);
    struct sockaddr_in serverAddress = setup_server_address(atoi(av[1]));
    bind_and_listen(tcpSocket, serverAddress);
    client_list_t *list = create_client_list();

    FD_ZERO(&readfds);
    FD_SET(tcpSocket, &readfds);
    int max_fd = tcpSocket;

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int selectStatus = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        check_return_value(selectStatus, SELECT);
        if (FD_ISSET(tcpSocket, &readfds)) {
            int clientSocket = accept(tcpSocket, (struct sockaddr *) &clientAddress, &clientAddressLength);
            check_return_value(clientSocket, ACCEPT);
            if (clientSocket > max_fd) {
                printf("error to socket\n");
                continue;
            }
            add_client_to_list(&list, create_client(clientSocket, clientAddress));
            printf("Connection from %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
            FD_SET(clientSocket, &readfds);
        } else {
            for (client_list_t *tmp = list; tmp != NULL; tmp = tmp->next) {
                if (FD_ISSET(tmp->client->socket, &readfds)) {
                    int clientSocket = tmp->client->socket;
                    char buffer[1024];
                    int readStatus = read(clientSocket, buffer, sizeof(buffer));
                    check_return_value(readStatus, READ);
                    if (readStatus == 0) {
                        printf("Connection closed by client\n");
                        close(clientSocket);
                        FD_CLR(clientSocket, &readfds);
                        remove_client_from_list(&list, tmp->client);
                        break;
                    }
                    buffer[readStatus] = '\0';
                    printf("Message from client: %s\n", buffer);
                    const char *message = "Hello World!!!";
                    int writeStatus = write(clientSocket, message, strlen(message));
                    check_return_value(writeStatus, WRITE);
                    close(clientSocket);}
            }
        }
    }
    return 0;
}