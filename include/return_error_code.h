/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** return_error_code.h
*/

#pragma once

#include <string.h>
#include <stdlib.h>

typedef enum ERROR_CODES {
    C120,
    C125,
    C150,
    C200,
    C214,
    C220,
    C221,
    C226,
    C227,
    C230,
    C250,
    C257,
    C331,
    C332,
    E425,
    E451,
    E500,
    E501,
    E502,
    E503,
    E504,
    E530,
    E550
} ERROR_CODES_t;

/**
 * @brief Returns the error message associated with a given error code
 *
 * This function is used to retrieve the error message that corresponds to a
 * given error code.
 * The error codes are defined in the ERROR_CODES_t enumeration. The function
 * takes as parameters
 * an error code and a string complement. The complement is used to provide
 * additional information
 * about the error. The function returns a pointer to a string containing the
 * error message.
 *
 * @param code The error code. This is a value from the ERROR_CODES_t
 * enumeration.
 * @param complement A string containing additional information about the
 * error.
 * @return A pointer to a string containing the error message associated with
 * the given error code.
 */
const char *return_error(ERROR_CODES_t code, char *complement);
