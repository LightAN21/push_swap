/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 21:14:39 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 14:36:39 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_len(int ac, char **av)
{
	int	i;
	int	len;
	int	tmp;

	len = 0;
	i = 0;
	while (++i < ac)
	{
		tmp = ft_words(av[i], ' ');
		if (tmp < 0)
			return (-42);
		len += tmp;
	}
	return (len);
}

int	check_flags(t_stack *stack, char *s)
{
	int		i;
	char	c;

	if (s[0] != '-')
		return (0);
	i = 0;
	while (s[++i])
	{
		c = s[i];
		if (c == 'v')
			stack->visual = 1;
		else if (c == 'd')
			stack->detail = 1;
		else if (c == 's')
			stack->s_step = 1;
		else if (c == 'm')
			stack->mlx = 1;
		else
			return (0);
	}
	return (1);
}

int	save_input(t_stack *stack, char *s, int *i, int *j)
{
	t_long	tmp;
	int		l;

	tmp = ft_check_atoi(s + *i);
	if (tmp == 3000000000)
		return (-42);
	stack->a[(*j)++].num = (int)tmp;
	l = ft_letters(s, *i, ' ');
	if (l > stack->num_len)
		stack->num_len = l;
	*i += l;
	return (1);
}

int	get_arguments(int ac, char **av, t_stack *stack)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (++k < ac)
	{
		if (check_flags(stack, av[k]))
			continue ;
		i = 0;
		while (av[k][i] == ' ' || av[k][i] == '\t')
			i++;
		while (av[k][i])
		{
			if (save_input(stack, av[k], &i, &j) < 0)
				return (-42);
			while (av[k][i] == ' ' || av[k][i] == '\t')
				i++;
		}
	}
	return (1);
}

int	read_input(t_stack *stack, int ac, char **av)
{
	if (ac < 2)
		return (usage());
	stack->len = count_len(ac, av);
	if (stack->len == -42)
		return (error_message());
	else if (stack->len == 0)
		return (0);
	if (!(stack->a = (t_order *)malloc((stack->len + 1) * sizeof(t_order))))
		return (error_message());
	if (!(stack->b = (t_order *)malloc((stack->len + 1) * sizeof(t_order))))
	{
		free(stack->a);
		return (error_message());
	}
	if (!(stack->sort = (int *)malloc((stack->len + 1) * sizeof(int))))
		return (free_stack(stack) + error_message());
	stack->num_len = 0;
	stack->visual = 0;
	stack->detail = 0;
	stack->s_step = 0;
	stack->mlx = 0;
	if (get_arguments(ac, av, stack) == -42)
		return (error_message());
	return (1);
}
