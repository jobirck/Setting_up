/*
** EPITECH PROJECT, 2024
** my_strtok
** File description:
** str to token
*/

#include "include/my.h"
#include <stdlib.h>
#include "include/struct_square.h"
#include <stddef.h>

static char *skip_delimiters(char *str, const char *delim)
{
    while (*str && my_strchar((char *)delim, *str)) {
        str++;
    }
    return str;
}

static char *find_token_end(char *str, const char *delim, char **saved_str)
{
    char *token_end = str;

    while (*token_end && !my_strchar((char *)delim, *token_end)) {
        token_end++;
    }
    if (*token_end) {
        *token_end = '\0';
        *saved_str = token_end + 1;
    } else {
        *saved_str = NULL;
    }
    return str;
}

char *my_strtok(char *str, const char *delim)
{
    static char *saved_str = NULL;
    char *token_start;

    if (str) {
        saved_str = str;
    }
    if (!saved_str) {
        return NULL;
    }
    token_start = skip_delimiters(saved_str, delim);
    if (!*token_start) {
        saved_str = NULL;
        return NULL;
    }
    return find_token_end(token_start, delim, &saved_str);
}
