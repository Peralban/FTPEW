/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** main.c
*/

#include "server.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0)
        return 0;
    if (ac != 3)
        return 84;
    return myftp(ac, av);
}
