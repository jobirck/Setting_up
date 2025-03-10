/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\n') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
