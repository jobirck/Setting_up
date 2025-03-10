/*
** EPITECH PROJECT, 2024
** copy_word (str_to_word_array)
** File description:
** copier  un mot dans un **char
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

char *copy_word(const char *str, int start, int end)
{
    int len = end - start;
    char *word = malloc(sizeof(char) * (len + 1));

    if (word == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        word[i] = str[start + i];
    }
    word[len] = '\0';
    return word;
}
