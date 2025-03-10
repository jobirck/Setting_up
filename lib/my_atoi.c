/*
** EPITECH PROJECT, 2025
** B-CPE-110-LIL-1-1-settingup-joseph.birck
** File description:
** my_atoi
*/

#include <stdlib.h>
#include <stdio.h>


int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
