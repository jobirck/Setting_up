/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** compter le nombre de character
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 0;
    for (; str[i]; i++) {
    }
    return i;
}
