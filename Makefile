# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 16:42:15 by jtsai             #+#    #+#              #
#    Updated: 2018/09/18 18:17:23 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = push_swap
NAME_2 = checker

FLAGS = -Wall -Wextra -Werror

MAIN_1 = src_sorting/push_swap.c
MAIN_2 = src_checker/checker.c
FILES_1_ = sorting.c heap_sort.c binary_search.c order_sort_5.c \
		   set_order.c special_order.c switch_stack.c sort_3.c sort_4.c
FILES_2_ = operations.c operations_spr.c read_input.c read_instructions.c \
		   ft_check_atoi.c print_detail.c bonus_visual.c messages.c draw_status.c

DIR_SORTING = src_sorting/
DIR_CHECKER = src_checker/
DIR_OFILES = o_files/

FILES_1 = $(addprefix $(DIR_SORTING), $(FILES_1_))
FILES_2 = $(addprefix $(DIR_CHECKER), $(FILES_2_))
FILES = $(FILES_1) $(FILES_2)

O_FILES_ = $(FILES_1_:.c=.o) $(FILES_2_:.c=.o)

O_FILE_1 = o_files/push_swap.o
O_FILE_2 = o_files/checker.o
OFILES = $(addprefix $(DIR_OFILES), $(O_FILES_))

LIB = lib/ft_printf/libftprintf.a lib/libft/libft.a
MLX = -L./lib/minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME_1)

$(NAME_1):  
	@make -C lib/libft/
	make -C o_files/
#	gcc -c $(FLAGS) -I libft/ -I ft_printf/ $(MAIN_1) $(MAIN_2) $(FILES)
#	gcc -o $(NAME_1) push_swap.o $(O_FILES_) $(LIB) $(MLX)
#	gcc -o $(NAME_2) checker.o $(O_FILES_) $(LIB) $(MLX)
	gcc -o $(NAME_1) $(O_FILE_1) $(OFILES) $(LIB) $(MLX)
	gcc -o $(NAME_2) $(O_FILE_2) $(OFILES) $(LIB) $(MLX)
#	gcc -o $(NAME_1) -fsanitize=address $(O_FILE_1) $(OFILES) $(LIB) $(MLX)
#	gcc -o $(NAME_2) -fsanitize=address $(O_FILE_2) $(OFILES) $(LIB) $(MLX)
#	gcc -g $(MAIN_1) $(FILES) $(LIB)
#	gcc -g $(MAIN_2) $(FILES) $(LIB)

clean:
	@make -C lib/libft/ clean
	/bin/rm -f $(OFILES)
	/bin/rm -f $(O_FILE_1)
	/bin/rm -f $(O_FILE_2)

fclean: clean
	@make -C lib/libft/ fclean
	/bin/rm -f $(NAME_1)
	/bin/rm -f $(NAME_2)

re: fclean all
