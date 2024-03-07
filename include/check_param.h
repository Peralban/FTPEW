/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** check_param.h
*/

#pragma once

#include <stdbool.h>
#include "return_error_code.h"
#include <stdio.h>

typedef enum exist_s {
    EXIST,
    NOT_EXIST
} exist_t;

/**
 * @brief Checks the parameters of a given command.
 *
 * This function checks the parameters of a given command and returns a boolean
 * value
 * indicating whether the parameters are valid or not.
 *
 * @param command The command whose parameters are to be checked.
 * @param client_socket The client socket where the command is to be
 * executed.
 * @param exist An enum value indicating whether the command exists or not.
 * @return Returns true if the parameters of the command are valid, false
 * otherwise.
 */
bool check_param(const char *command, int client_socket, exist_t exist);
