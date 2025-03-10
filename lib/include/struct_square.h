/*
** EPITECH PROJECT, 2024
** struct_square
** File description:
** stocker le carré le plus grand
*/
#ifndef STRUCT_SQUARE_H
    #define STRUCT_SQUARE_H
typedef struct {
    int size;
    int i;
    int y;
} biggest_square_t;

typedef struct {
    int rows;
    int cols;
} dimensions_t;

typedef struct file_info {
    int fd;
    struct stat *st;
} file_info_t;

#endif
