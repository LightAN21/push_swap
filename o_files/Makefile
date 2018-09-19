# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 08:37:06 by jtsai             #+#    #+#              #
#    Updated: 2018/09/15 15:31:24 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_1 = push_swap
NAME_2 = checker

FLAGS = -Wall -Wextra -Werror

FILES_1_ = sorting.c heap_sort.c binary_search.c order_sort_5.c \
		   set_order.c special_order.c switch_stack.c sort_3.c sort_4.c
FILES_2_ = operations.c operations_spr.c read_input.c read_instructions.c \
		   ft_check_atoi.c print_detail.c bonus_visual.c messages.c draw_status.c

DIR_SORTING = ../src_sorting/
DIR_CHECKER = ../src_checker/

MAIN_1 = ../src_sorting/push_swap.c
MAIN_2 = ../src_checker/checker.c
FILES_1 = $(addprefix $(DIR_SORTING), $(FILES_1_))
FILES_2 = $(addprefix $(DIR_CHECKER), $(FILES_2_))
FILES = $(FILES_1) $(FILES_2)

FIND_LIB = -I ../lib/libft/ -I ../lib/ft_printf/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(FIND_LIB) -c $(MAIN_1) $(MAIN_2) $(FILES)
