/*
** EPITECH PROJECT, 2024
** include
** File description:
** include
*/

#include <stdarg.h>
#include <unistd.h>
#include "include/struct_square.h"

#ifndef MY_H
    #define MY_H
    #include "struct.h"
    #include <sys/stat.h>

void *my_realloc(void *ptr, size_t new_size);

char *my_strtok(char *str, const char *delim);

char *my_strdup(const char *s);

char *my_strchar(const char *str, int c);

char **readmap(const char *filename);

void find_square(char **map, int rows, int cols, biggest_square_t *square);

int my_put_unsigned_nbr(unsigned int nb);

int handle_unsigned(va_list ap);

int handle_e(va_list ap);

int flottant(va_list ap);

int handle_ptr(va_list ap);

int handle_oct(va_list ap);

int handle_hexmaj(va_list ap);

int handle_hex(va_list ap);

int my_putfloat(float nb);

int handle_char(va_list ap);

int handle_str(va_list ap);

int handle_int(va_list ap);

int percent(va_list ap);

int my_printf(char const *format, ...);

char *copy_word(const char *str, int start, int end);

int is_alnum(char c);

char **my_str_to_word_array(char const *str);

int count_words(const char *str);

void fill_word_array(const char *str, word_array_t *word_array);

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *concat_params(int argc, char **argv);

int my_show_word_array(char *const *tab);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

int my_is_prime(int nb);

#endif
