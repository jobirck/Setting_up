/*
** EPITECH PROJECT, 2025
** B-CPE-110-LIL-1-1-settingup-joseph.birck
** File description:
** map_generating
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char **generating_map(const char *str, const char *size_str)
{
    int size = my_atoi(size_str);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int pattern_len = my_strlen(str);
    int index = 0;

    if (!tab || size <= 0)
        return NULL;
    for (int i = 0; i < size; i++) {
        tab[i] = malloc(sizeof(char) * (size + 1));
        if (!tab[i])
            return NULL;
        for (int j = 0; j < size; j++) {
            tab[i][j] = str[index % pattern_len];
            index++;
        }
        tab[i][size] = '\0';
    }
    tab[size] = NULL;
    return tab;
}

void free_map(char **map)
{
    if (!map)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}
