/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:30:36 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/08 03:41:15 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		special_base(t_stack *stack, t_set *set, int i, char c)
{
	int	k;

	k = -1;
	while (++k < set->divisor && i < stack->len)
		stack->sort[i + k] = c;
	return (i + k);
}

int		special_base_re(t_stack *stack, t_set *set, int i, char c)
{
	int	k;

	k = -1;
	while (++k < set->divisor && i >= 0)
		stack->sort[i - k] = c;
	return (i - k);
}

void	special_order(t_stack *stack, t_set *set)
{
	int	i;

	i = 0;
	if (set->parts == 2)
	{
		i = special_base(stack, set, i, 'C');
		special_base(stack, set, i, 'D');
	}
	else if (set->parts < 5)
	{
		i = special_base(stack, set, i, 'B');
		i = special_base(stack, set, i, 'C');
		i = special_base(stack, set, i, 'D');
		if (set->parts == 4)
			special_base(stack, set, i, 'E');
	}
	else
	{
		i = special_base(stack, set, i, 'A');
		i = special_base(stack, set, i, 'B');
		i = special_base(stack, set, i, 'C');
		i = special_base(stack, set, i, 'D');
		special_base(stack, set, i, 'E');
	}
}

void	special_order_re(t_stack *stack, t_set *set)
{
	int	i;

	i = stack->len - 1;
	if (set->parts == 2)
	{
		i = special_base_re(stack, set, i, 'C');
		special_base_re(stack, set, i, 'D');
	}
	else if (set->parts < 5)
	{
		i = special_base_re(stack, set, i, 'B');
		i = special_base_re(stack, set, i, 'C');
		i = special_base_re(stack, set, i, 'D');
		if (set->parts == 4)
			special_base_re(stack, set, i, 'E');
	}
	else
	{
		i = special_base_re(stack, set, i, 'A');
		i = special_base_re(stack, set, i, 'B');
		i = special_base_re(stack, set, i, 'C');
		i = special_base_re(stack, set, i, 'D');
		special_base_re(stack, set, i, 'E');
	}
}
