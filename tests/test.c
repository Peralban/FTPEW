/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** test.c
*/

#include "test_include.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}
