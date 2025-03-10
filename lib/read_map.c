/*
** EPITECH PROJECT, 2024
** read_map
** File description:
** pour lire le fichier qui equivaut un la map pour setting_up
*/

#include "include/my.h"
#include "include/struct_square.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

static int get_file_stats(const char *filename, struct stat *st)
{
    if (stat(filename, st) == -1) {
        return -1;
    }
    return 0;
}

static char *alloc_content_buffer(struct stat *st)
{
    char *content = malloc(st->st_size + 1);

    if (!content) {
        return NULL;
    }
    return content;
}

static char *read_file_content(int fd, struct stat *st, char *content)
{
    if (read(fd, content, st->st_size) != st->st_size) {
        free(content);
        close(fd);
        return NULL;
    }
    content[st->st_size] = '\0';
    close(fd);
    return content;
}

static char *read_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    char *content;

    if (fd == -1) {
        return NULL;
    }
    if (get_file_stats(filename, &st) == -1) {
        close(fd);
        return NULL;
    }
    content = alloc_content_buffer(&st);
    if (!content) {
        close(fd);
        return NULL;
    }
    return read_file_content(fd, &st, content);
}

static void gestion(char **map, int *num_lines)
{
    for (int i = 0; i < *num_lines; i++)
        free(map[i]);
}

char **add_line_to_map(char **map, char *line, int *num_lines,
    size_t *allocated_size)
{
    if (*allocated_size < sizeof(char *) * (*num_lines + 2)) {
        *allocated_size = sizeof(char *) * (*num_lines + 2);
        map = my_realloc(map, *allocated_size);
        if (!map) {
            gestion(map, num_lines);
            return NULL;
        }
    }
    map[*num_lines] = my_strdup(line);
    if (!map[*num_lines]) {
        for (int i = 0; i < *num_lines; i++) {
            free(map[i]);
        }
        free(map);
        return NULL;
    }
    (*num_lines)++;
    map[*num_lines] = NULL;
    return map;
}

static char **parse_map(char *content)
{
    char **map = NULL;
    char *line;
    int num_lines = 0;
    size_t allocated_size = 0;
    char *map_start = my_strchar(content, '\n');

    if (!map_start)
        return NULL;
    map_start++;
    line = my_strtok(map_start, "\n");
    while (line) {
        map = add_line_to_map(map, line, &num_lines, &allocated_size);
        if (!map) {
            return NULL;
        }
        line = my_strtok(NULL, "\n");
    }
    return map;
}

char **readmap(const char *filename)
{
    char *content = read_file(filename);
    char **map;

    if (!content)
        return NULL;
    map = parse_map(content);
    free(content);
    return map;
}
