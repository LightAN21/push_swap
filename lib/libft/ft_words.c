/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:28:42 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/15 10:45:05 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_f(const char *s)
{
	int		i;
	char	c;

	if (s[0] != '-')
		return (0);
	i = 0;
	while (s[++i])
	{
		c = s[i];
		if (c != 'd' && c != 's' && c != 'v' && c != 'm')
			return (0);
	}
	if (i != 1)
		return (1);
	return (0);
}

int	ft_words(const char *s, char c)
{
	int		i;
	int		num;
	char	a;
	char	b;

	if (check_f(s))
		return (0);
	num = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		a = s[i];
		b = s[i + 1];
		if ((a < '0' || a > '9') && a != ' ' && a != '\n' &&
				a != '\t' && a != '-' && a != '+' && a != c)
			return (-42);
		if ((a == '-' || a == '+') && (b < '0' || b > '9' ||
					(i > 0 && '0' <= s[i - 1] && s[i - 1] <= '9')))
			return (-42);
		if (a != ' ' && a != '\n' && a != '\t' && a != c &&
				(b == c || b == '\0'))
			num++;
	}
	return (num);
}
