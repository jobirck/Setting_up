/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** lol jsp
*/

#include <errno.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\n') {
        if (s1[i] == s2[i]) {
            continue;
        }
        if (s1[i] != s2[i]) {
            perror("The str are not the same");
            return 84;
        }
    }
    return 0;
}
