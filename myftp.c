/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** server.c
*/

#include "server.h"

struct sockaddr_in setup_server_address(int port)
{
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    return (serverAddress);
}

int myftp(int ac, char **av)
{
    int tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
    fd_set readfds;
    if (tcpSocket == -1) {
        perror("socket");
        return (84);
    }
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(av[1]));
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int bindStatus = bind(tcpSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (bindStatus == -1) {
        perror("bind");
        return (84);
    }
    int listenStatus = listen(tcpSocket, 5);
    if (listenStatus == -1) {
        perror("listen");
        return (84);
    }
    client_list_t *list = create_client_list();

    FD_ZERO(&readfds);
    FD_SET(tcpSocket, &readfds);
    int max_fd = tcpSocket;

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int selectStatus = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (selectStatus == -1) {
            perror("select");
            return (84);
        }
        if (FD_ISSET(tcpSocket, &readfds)) {
            int clientSocket = accept(tcpSocket, (struct sockaddr *) &clientAddress, &clientAddressLength);
            if (clientSocket == -1) {
                perror("accept");
                return (84);
            }
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
                    if (readStatus == -1) {
                        perror("read");
                        return (84);
                    }
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
                    if (writeStatus == -1) {
                        perror("write");
                        return (84);
                    }
                    //const char *message = "Hello World!!!";
                    //int writeStatus = write(clientSocket, message, strlen(message));
                    //if (writeStatus == -1) {
                    //    perror("write");
                    //    return (84);
                    //}
                    //char buffer[1024];
                    //int readStatus = read(clientSocket, buffer, sizeof(buffer));
                    //if (readStatus == -1) {
                    //    perror("read");
                    //    return (84);
                    //}
                    //if (readStatus == 0) {
                    //    printf("Connection closed by client\n");
                    //    break;
                    //}
                    //buffer[readStatus] = '\0';
                    //sleep(5);
                    //printf("Message from client: %s\n", buffer);
                    close(clientSocket);}
            }
        }
    }
    return 0;
}