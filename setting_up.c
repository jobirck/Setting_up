/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** trouver le plus grand carré dan sla map
*/

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "lib/include/struct_square.h"
#include "lib/include/my.h"
#include <string.h>

dimensions_t find_dimension(char **map)
{
    dimensions_t dims = {0, 0};

    if (!map || !map[0]) {
        return dims;
    }
    dims.cols = my_strlen(map[0]);
    for (dims.rows = 1; map[dims.rows] != NULL; dims.rows++) {
        if (dims.cols != (int)my_strlen(map[dims.rows])) {
            return dims;
        }
    }
    return dims;
}

void draw_square(char **map, biggest_square_t *square)
{
    int start_row = square->i - square->size + 1;
    int start_col = square->y - square->size + 1;

    for (int i = 0; i < square->size; i++) {
        for (int j = 0; j < square->size; j++) {
            map[start_row + i][start_col + j] = 'x';
        }
    }
}

static int check_argument(int argc, const char **argv)
{
    if (argc == 2 || argc >= 4)
        return 1;
    if (argc != 3)
        return 84;
    if (argv[2] == NULL || my_strlen(argv[2]) == 0)
        return 84;
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if (argv[2][i] != 'o' && argv[2][i] != '.')
            return 84;
    }
    return 0;
}

static void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}

static void print_map_with_square(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%s\n", map[i]);
    }
}

static char **is_generate(int argc, const char **argv)
{
    if (argc == 3 && argv[2] != NULL)
        return generating_map(argv[2], argv[1]);
    return readmap(argv[1]);
}

int main(int argc, const char *argv[])
{
    char **map;
    dimensions_t dims;
    biggest_square_t square = {0, 0, 0};

    if (!argv)
        return 84;
    if (check_argument(argc, argv) == 84)
        return 84;
    if (check_argument(argc, argv) == 1 && argc != 2)
        return 1;
    map = is_generate(argc, argv);
    if (!map)
        return 1;
    dims = find_dimension(map);
    find_square(map, dims.rows, dims.cols, &square);
    draw_square(map, &square);
    print_map_with_square(map);
    free_map(map);
    return 0;
}
