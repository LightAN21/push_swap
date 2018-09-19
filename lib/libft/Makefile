# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 16:12:19 by jtsai             #+#    #+#              #
#    Updated: 2018/09/01 17:53:08 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILES = ft_strlen.c ft_atoi.c ft_words.c ft_letters.c 

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(CFILES) -I includes/
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
