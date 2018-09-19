# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_num.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsai <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 21:31:48 by jtsai             #+#    #+#              #
#    Updated: 2018/09/15 16:12:34 by jtsai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG=`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`

echo "\nInput:"
echo $ARG

echo "\nchecker and time:"

time ./push_swap $ARG | ./checker $ARG

echo "\nsteps:"

./push_swap $ARG | wc -l
