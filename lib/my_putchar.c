/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** pour print peut etre ?
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
