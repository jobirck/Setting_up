##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make qui file
##

SRC_DIR		=	lib

SRC_MAIN	=	setting_up.c \
				map_generating.c

SRC		=	$(SRC_DIR)/my_putstr.c \
			$(SRC_DIR)/my_putchar.c \
			$(SRC_DIR)/my_strlen.c \
			$(SRC_DIR)/my_revstr.c \
			$(SRC_DIR)/my_compute_power_rec.c \
			$(SRC_DIR)/my_compute_square_root.c \
			$(SRC_DIR)/my_find_prime_sup.c \
			$(SRC_DIR)/my_getnbr.c \
			$(SRC_DIR)/my_isneg.c \
			$(SRC_DIR)/my_is_prime.c \
			$(SRC_DIR)/my_put_nbr.c \
			$(SRC_DIR)/my_showmem.c \
			$(SRC_DIR)/my_showstr.c \
			$(SRC_DIR)/my_sort_int_array.c \
			$(SRC_DIR)/my_strcapitalize.c \
			$(SRC_DIR)/my_strcat.c \
			$(SRC_DIR)/my_strcmp.c \
			$(SRC_DIR)/my_strcpy.c \
			$(SRC_DIR)/my_str_isalpha.c \
			$(SRC_DIR)/my_str_islower.c \
			$(SRC_DIR)/my_str_isnum.c \
			$(SRC_DIR)/my_str_isprintable.c \
			$(SRC_DIR)/my_str_isupper.c \
			$(SRC_DIR)/my_strlowcase.c \
			$(SRC_DIR)/my_strncat.c \
			$(SRC_DIR)/my_strncmp.c \
			$(SRC_DIR)/my_strncpy.c \
			$(SRC_DIR)/my_strstr.c \
			$(SRC_DIR)/my_strupcase.c \
			$(SRC_DIR)/my_swap.c \
			$(SRC_DIR)/copy_word.c \
			$(SRC_DIR)/count_words.c \
			$(SRC_DIR)/is_alnum.c \
			$(SRC_DIR)/my_str_to_word_array.c \
			$(SRC_DIR)/fill_word_array.c \
			$(SRC_DIR)/my_printf.c \
			$(SRC_DIR)/handle_char.c \
			$(SRC_DIR)/handle_str.c \
			$(SRC_DIR)/handle_int.c \
			$(SRC_DIR)/percent.c \
			$(SRC_DIR)/handle_hex.c \
			$(SRC_DIR)/handle_hexmaj.c \
			$(SRC_DIR)/handle_oct.c \
			$(SRC_DIR)/handle_ptr.c \
			$(SRC_DIR)/handle_flottants.c \
			$(SRC_DIR)/handle_e.c \
			$(SRC_DIR)/my_put_unsigned_nbr.c \
			$(SRC_DIR)/handle_unsigned.c \
			$(SRC_DIR)/find_square.c \
			$(SRC_DIR)/read_map.c \
			$(SRC_DIR)/my_strchar.c \
			$(SRC_DIR)/my_strdup.c \
			$(SRC_DIR)/my_strtok.c \
			$(SRC_DIR)/my_realloc.c \
			$(SRC_DIR)/my_atoi.c

OBJ		=	$(SRC:.c=.o)

M_OBJ	=	$(SRC_MAIN:.c=.o)

NAME	=	lib/libmy.a

EXEC	=	setting_up

CFLAGS	=	-Ilib/include -Wall -Werror -Wextra

all:	$(NAME) $(EXEC)

$(NAME):		$(OBJ)
		ar rc $(NAME) $(OBJ)

$(EXEC):		$(M_OBJ) $(NAME)
		gcc -o $(EXEC) $(M_OBJ) -Llib -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(M_OBJ).o
	rm -f $(EXEC).o

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXEC)

re: fclean all
