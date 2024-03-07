/*
** EPITECH PROJECT, 2023
** FTPEW
** File description:
** help_message.h
*/

#pragma once

static const char *help_message = "USER <SP> <username> <CRLF>   : Specify "
"user for authentication\n"
"PASS <SP> <password> <CRLF>  : Specify password for authentication\n"
"CWD  <SP> <pathname> <CRLF>  : Change working directory\n"
"CDUP <CRLF>                  : Change working directory to parent directory\n"
"QUIT <CRLF>                  : Disconnection\n"
"DELE <SP> <pathname> <CRLF>  : Delete file on the server\n"
"PWD  <CRLF>                  : Print working directory\n"
"PASV <CRLF>                  : Enable \"passive\" mode for data "
"transfer\n"
"PORT <SP> <host-port> <CRLF> : Enable \"active\" mode for data "
"transfer\n"
"HELP [<SP> <string>] <CRLF>  : List available commands\n"
"NOOP <CRLF>                  : Do nothing\n"
"(the following are commands using data transfer )\n"
"RETR <SP> <pathname> <CRLF>  : Download file from server to client\n"
"STOR <SP> <pathname> <CRLF>  : Upload file from client to server\n"
"LIST [<SP> <pathname>] <CRLF>: List files in the current working "
"directory\n";
