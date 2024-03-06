/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my.h
*/

#pragma once

#define ARRAY 0
#define STRING 1

#include <stdbool.h>

/**
 * @brief Check if a char is in a string
 * @param c The char to check.
 * @param str The string to check.
 * @return true if the char is in the string, false otherwise.
*/

bool char_is_in_str(char c, char *str);

/**
 * @brief Return the lenght of an object (string, array, etc...).
 * @param object The object to check.
 * @param type The type of the object (ARRAY or STRING).
 * @return The lenght of the object. If the object is NULL, return 0.
 * @warning If the object isn't NULL, it must be terminated by '\0' or NULL.
*/

int get_len(void **object, int type);

/**
 * @brief Return the number of char in a string.
 * @param str The string to check.
 * @param c The char to check.
 * @return The number of char in the string.
*/

int get_nbr_of_char(char *str, char c);

/**
 * @brief Return a duplicate of an array.
 * @param src The array to duplicate.
 * @return The duplicate of the array. If the array is NULL, return NULL.
 * @warning The array must be terminated by NULL.
*/

char **my_arraydup(char **src);

/**
 * @brief Return the lenght of a string before a char.
 * @param str The string to check.
 * @param delim The char of reference.
 * @return The lenght of the string before the char.
 * @warning The string must be terminated by '\0'.
*/

int my_len_before_char(char *str, char *delim);

/**
 * @brief Return a duplicate of a string.
 * @param src The string to duplicate.
 * @return The duplicate of the string. If the string is NULL, return NULL.
 * @warning The string must be terminated by '\0'.
*/

char *my_strdup(char *src);

/**
 * @brief Return a duplicate of a string of a specific lenght.
 * @param str The string to duplicate.
 * @param n The lenght of the string to duplicate.
 * @return The duplicate of the string. If the string is NULL, return NULL.
*/

char *my_strndup(char *str, int n);

/**
 * @brief Write an int number on the standard output.
 * @param nb The number to write.
 * @return Nothing.
*/

void my_put_nbr(int nb);

/**
 * @brief Write an int number on the error output.
 * @param nb The number to write.
 * @return Nothing.
*/

void my_put_nbr_err(int nb);

/**
 * @brief Write a char on the standard output.
 * @param c The char to write.
 * @return Nothing.
*/

void my_putchar(char c);

/**
 * @brief Write a char on the error output.
 * @param c The char to write.
 * @return Nothing.
*/

void my_putchar_err(char c);

/**
 * @brief Write a string on the standard output.
 * @param str The string to write.
 * @return Nothing.
*/

void my_putstr(char *str);

/**
 * @brief Write a string on the error output.
 * @param str The string to write.
 * @return Nothing.
*/

void my_putstr_err(char *str);

/**
 * @brief Return true if the string start with the string cmp.
 * @param src The string to check.
 * @param cmp The string of reference.
 * @return true if the string start with the string cmp, false otherwise.
 * @warning The string and the string of reference must be terminated by '\0'.
*/

bool my_start_with(char *src, char *cmp);

/**
 * @brief Return an array of string from a string.
 * @param str The string to split.
 * @param delim A string of delimiter.
 * @return An array of string. If the string is NULL, return NULL.
 * @warning The string must be terminated by '\0'.
*/

char **my_str_to_word_array(char *str, char *delim);

/**
 * @brief Return a concatenation of two strings.
 * @param dest The string of destination.
 * @param src The string to concatenate.
 * @return The concatenation of the two strings. If one of the string is NULL,
 * return NULL.
 * @warning The string of destination and the string to concatenate must be
 * terminated by '\0'.
*/

char *my_strcat(char *dest, char *src);

/**
 * @brief Return a concatenation of two strings.
 * @param dest The string of destination.
 * @param src The string to concatenate.
 * @param n The number of char to concatenate.
 * @return The concatenation of the two strings. If one of the string is NULL,
 * return NULL.
 * @warning The string of destination and the string to concatenate must be
 * terminated by '\0'.
*/

char *my_strncat(char *dest, char *src, int n);

/**
 * @brief This function will be used to compare two strings.
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return 0 if the two strings are identical or the difference between the
 * first two different char.
 * @warning The two strings must be terminated by '\0'.
*/

int my_strcmp(char *str1, char *str2);

/**
 * @brief This function will be used to compare two strings.
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param n The number of char to compare.
 * @return 0 if the two strings are identical or the difference between the
 * first two different char.
 * @warning The two strings must be terminated by '\0'.
*/

int my_strncmp(char *str1, char *str2, int n);

/**
 * @brief This function will be used to copy a string into another.
 * @param dest The string of destination.
 * @param src The string to copy.
 * @return The string of destination. If the string of destination is NULL,
 * return NULL.
*/

char *my_strcpy(char *dest, char *src);

/**
 * @brief This function will be used to copy a string into another.
 * @param dest The string of destination.
 * @param src The string to copy.
 * @param n The number of char to copy.
 * @return The string of destination. If the string of destination is NULL,
 * return NULL.
*/

char *my_strncpy(char *dest, char *src, int n);

/**
 * @brief This function will be print an array of string.
 * @param array The array of string to print.
 * @return Nothing.
*/

void my_put_array(char **array);
