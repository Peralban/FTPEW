/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client.c
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("socket");
        return (84);
    }
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(av[2]));
    serverAddress.sin_addr.s_addr = inet_addr(av[ac - 2]);
    int connectStatus = connect(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (connectStatus == -1) {
        perror("connect");
        return (84);
    }
    char buffer[1024];
    int readStatus = read(serverSocket, buffer, sizeof(buffer));
    if (readStatus == -1) {
        perror("read");
        return (84);
    }
    printf("Server said: %s\n", buffer);
    const char *message = "Hello from client";
    int writeStatus = write(serverSocket, message, strlen(message));
    if (writeStatus == -1) {
        perror("write");
        return (84);
    }
}