/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** create_passive_server.h
*/

#pragma once

#include "check_param.h"
#include "server.h"
#include "return_error_code.h"

/**
 * @brief Creates a passive server.
 *
 * This function is responsible for creating a passive server. It does not take
 * any parameters
 * and returns an integer. The return value can be used to check if the server
 * was created successfully.
 * A successful creation returns 0, while any error during the creation process
 * returns a non-zero value.
 *
 * @return int - Returns 0 if the server was created successfully, otherwise
 * returns a non-zero value.
 */
int create_passive_server(void);
