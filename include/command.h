/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** client.h
*/

#pragma once

#include "server.h"

typedef struct command_component_s {
    char *command;
    void (*function)(client_t *client, char **command, server_t *server);
} command_component_t;

typedef enum {
    EXIST,
    NOT_EXIST
} exist_t;

/**
 * @brief Handles the client's command
 *
 * This function is responsible for handling the commands sent by the client.
 * It takes as parameters a pointer to the client structure, the command to be
 * executed,
 * and a pointer to the server structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param server A pointer to the server structure. This structure contains
 * information about the server.
 */
void handle_client_command(client_t **client, char **command, server_t **serv);

/**
 * @brief Handles the user command
 *
 * This function is responsible for handling the user command sent by the
 * client.
 * It takes as parameters a pointer to the client structure, the command to be
 * executed,
 * and a pointer to the server structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param server A pointer to the server structure. This structure contains
 * information about the server.
 */
void user_command(client_t *client, char **command, server_t *server);

/**
 * @brief Handles the PASS command
 *
 * This function is responsible for handling the PASS command sent by the
 * client.
 * The PASS command is used for user authentication.
 * It takes as parameters a pointer to the client structure, the command to be
 * executed,
 * and a pointer to the server structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param server A pointer to the server structure. This structure contains
 * information about the server.
 */
void pass_command(client_t *client, char **command, server_t *server);

/**
 * @brief Handles the CWD command
 *
 * This function is responsible for handling the CWD (Change Working Directory)
 * command sent by the client.
 * The CWD command is used to change the current working directory on the
 * server.
 * It takes as parameters a pointer to the client structure, the command to
 * be executed,
 * and a pointer to the server structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param server A pointer to the server structure. This structure contains
 * information about the server.
 */
void cwd_command(client_t *client, char **command, server_t *server);

/**
 * @brief Handles the CDUP command
 *
 * This function is responsible for handling the CDUP
 * (Change to Parent Directory) command sent by the client.
 * The CDUP command is used to change the current working directory to its
 * parent directory on the server.
 * It takes as parameters a pointer to the client structure, the command to
 * be executed,
 * and a pointer to the server structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param server A pointer to the server structure. This structure contains
 * information about the server.
 */
void cdup_command(client_t *client, char **command, server_t *server);

static const command_component_t COMMANDS[] = {
    {"USER", &user_command},
    {"PASS", &pass_command},
    {NULL, NULL}
};
//    {"CWD", &cwd_command},
//    {"CDUP", &cdup_command},
//    {"QUIT", &quit_command},
//    {"DELE", &dele_command},
//    {"PWD", &pwd_command},
//    {"PASV", &pasv_command},
//    {"PORT", &port_command},
//    {"HELP", &help_command},
//    {"NOOP", &noop_command},
//    {"RETR", &retr_command},
//    {"STOR", &stor_command},
//    {"LIST", &list_command},
//    {"SYST", &syst_command},
//    {"TYPE", &type_command},
//    {"MKD", &mkd_command},
//    {"RMD", &rmd_command},
//    {"RNFR", &rnfr_command},
//    {"RNTO", &rnto_command},
