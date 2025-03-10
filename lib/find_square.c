/*
** EPITECH PROJECT, 2024
** find_square
** File description:
** trouver les carré dans la map
*/

#include "include/my.h"
#include <stdlib.h>
#include "include/struct_square.h"

static int is_border(int i, int j)
{
    return (i == 0 || j == 0);
}

int min_of_three(int a, int b, int c)
{
    int min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

static int **initialize_auxiliary(int rows, int cols)
{
    int **aux = malloc(rows * sizeof(int *));

    if (!aux)
        exit(EXIT_FAILURE);
    for (int i = 0; i < rows; i++) {
        aux[i] = malloc(cols * sizeof(int));
        if (!aux[i])
            exit(EXIT_FAILURE);
    }
    return aux;
}

static void free_auxiliary(int **aux, int rows)
{
    for (int i = 0; i < rows; i++)
        free(aux[i]);
    free(aux);
}

static void update_square(int **aux, biggest_square_t *square, int i, int j)
{
    if (aux[i][j] > square->size) {
        square->size = aux[i][j];
        square->i = i;
        square->y = j;
    }
}

int calculate_aux_value(char **map, int **aux, int i, int j)
{
    if (map[i][j] == 'o') {
        return 0;
    }
    if (is_border(i, j)) {
        return 1;
    }
    return 1 + min_of_three(aux[i][j - 1], aux[i - 1][j], aux[i - 1][j - 1]);
}

void find_square(char **map, int rows, int cols, biggest_square_t *square)
{
    int **aux = initialize_auxiliary(rows, cols);

    square->size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            aux[i][j] = calculate_aux_value(map, aux, i, j);
            update_square(aux, square, i, j);
        }
    }
    free_auxiliary(aux, rows);
}
