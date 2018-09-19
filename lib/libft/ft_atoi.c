/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:36:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/07/13 13:39:28 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (num > 9223372036854775807)
		return ((sign == 1) ? -1 : 0);
	return (sign * (int)num);
}
