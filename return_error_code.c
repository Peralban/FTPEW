/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** return_error_code.c
*/

#include "include/return_error_code.h"
#include "include/error_messages.h"

static const char *strfusion(const char *str1, char *str2)
{
    char *result = NULL;

    if (str2 == NULL) {
        result = malloc(strlen(str1) + 3);
        if (result == NULL)
            return (str1);
        strcpy(result, str1);
        strcat(result, "\r\n");
        return (result);
    }
    result = malloc(strlen(str1) + strlen(str2) + 3);
    if (result == NULL)
        return (str1);
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, "\r\n");
    return (result);
}

const char *return_error(ERROR_CODES_t code, char *complement)
{
    return (strfusion(MESSAGES[code], complement));
}
