/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:58:55 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 09:49:29 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_long	ft_check_atoi(const char *str)
{
	int		i;
	t_long	sign;
	t_long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if ((num > 2147483647 && sign == 1) || num > 2147483648)
			return (3000000000);
	}
	return (sign * num);
}
