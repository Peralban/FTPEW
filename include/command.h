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
    void (*function)(client_t *client, char **command, server_t *server,
        client_list_t **client_list);
} command_component_t;

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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void handle_client_command(client_t **client, char **command, server_t **serv,
    client_list_t **client_list);

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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void user_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list);

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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void pass_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list);

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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void cwd_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list);

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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void cdup_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list);

/**
 * @brief Handles the PWD command
 *
 * This function is responsible for handling the PWD (Print Working Directory)
 * command sent by the client.
 * The PWD command is used to retrieve the current working directory on the
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
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void pwd_command(client_t *client, char **command, server_t *server,
    client_list_t **client_list);

/**
 * @brief Handles the QUIT command
 *
 * This function is responsible for handling the QUIT command sent by the
 * client.
 * The QUIT command is used to terminate the FTP session.
 * It takes as parameters a pointer to the client structure, the command to be
 * executed,
 * a pointer to the server structure, and a pointer to the client list
 *structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param serv A pointer to the server structure. This structure contains
 * information about the server.
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void quit_command(client_t *client, char **command, server_t *serv,
    client_list_t **client_list);

/**
 * @brief Handles the NOOP command
 *
 * This function is responsible for handling the NOOP (No Operation) command
 * sent by the client.
 * The NOOP command is used to keep the connection alive without performing any
 * action.
 * It takes as parameters a pointer to the client structure, the command to be
 * executed,
 * a pointer to the server structure, and a pointer to the client list
 * structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param serv A pointer to the server structure. This structure contains
 * information about the server.
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void noop_command(client_t *client, char **command, server_t *serv,
    client_list_t **client_list);

/**
 * @brief Handles the HELP command
 *
 * This function is responsible for handling the HELP command sent by the
 * client.
 * The HELP command is used to provide the client with a list of available
 * commands.
 * It takes as parameters a pointer to the client structure, the command to
 * be executed,
 * a pointer to the server structure, and a pointer to the client list
 * structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param serv A pointer to the server structure. This structure contains
 * information about the server.
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void help_command(client_t *client, char **command, server_t *serv,
    client_list_t **client_list);

/**
 * @brief Handles the DELE command
 *
 * This function is responsible for handling the DELE (Delete) command sent
 * by the client.
 * The DELE command is used to delete a file on the server.
 * It takes as parameters a pointer to the client structure, the command to
 * be executed,
 * a pointer to the server structure, and a pointer to the client list
 * structure.
 *
 * @param client A pointer to the client structure. This structure contains
 * information about the client.
 * @param command The command to be executed. This is a string representing
 * the command sent by the client.
 * @param serv A pointer to the server structure. This structure contains
 * information about the server.
 * @param client_list A pointer to the client list structure. This structure
 * contains information about the client list.
 */
void dele_command(client_t *client, char **command, server_t *serv,
    client_list_t **client_list);

static const command_component_t COMMANDS[] = {
    {"USER", &user_command},
    {"PASS", &pass_command},
    {"CWD", &cwd_command},
    {"CDUP", &cdup_command},
    {"PWD", &pwd_command},
    {"QUIT", &quit_command},
    {"DELE", &dele_command},
    {"HELP", &help_command},
    {"NOOP", &noop_command},
    {NULL, NULL}
};
//    {"PASV", &pasv_command},
//    {"PORT", &port_command},
//    {"RETR", &retr_command},
//    {"STOR", &stor_command},
//    {"LIST", &list_command},
//    {"SYST", &syst_command},
//    {"TYPE", &type_command},
//    {"MKD", &mkd_command},
//    {"RMD", &rmd_command},
//    {"RNFR", &rnfr_command},
//    {"RNTO", &rnto_command},
