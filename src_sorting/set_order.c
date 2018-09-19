/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:48:10 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/10 10:43:38 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		set_base_b(t_stack *stack, int i, int ord)
{
	int	j;
	int	w;

	j = -1;
	while (++j < 5 && i < stack->len)
	{
		w = -1;
		while (++w < stack->base && i >= 0)
			stack->sort[i--] = (ord == -1) ? 'A' + j : 'E' - j;
	}
	return (i);
}

int		set_order_b(t_stack *stack, int i, int div, int ord)
{
	if (div / 5 <= stack->base)
		i = set_base_b(stack, i, ord);
	else if (ord == 1)
	{
		i = set_order_b(stack, i, div / 5, ord);
		i = set_order_b(stack, i, div / 5, ord);
		i = set_order_b(stack, i, div / 5, -ord);
		i = set_order_b(stack, i, div / 5, -ord);
		i = set_order_b(stack, i, div / 5, -ord);
	}
	else if (ord == -1)
	{
		i = set_order_b(stack, i, div / 5, -ord);
		i = set_order_b(stack, i, div / 5, -ord);
		i = set_order_b(stack, i, div / 5, -ord);
		i = set_order_b(stack, i, div / 5, ord);
		i = set_order_b(stack, i, div / 5, ord);
	}
	return (i);
}

int		set_base(t_stack *stack, int i, int ord)
{
	int	j;
	int	w;

	j = -1;
	while (++j < 5 && i < stack->len)
	{
		w = -1;
		while (++w < stack->base && i < stack->len)
			stack->sort[i++] = (ord == 1) ? 'A' + j : 'E' - j;
	}
	return (i);
}

int		set_order_a(t_stack *stack, int i, int div, int ord)
{
	if (div / 5 <= stack->base)
		i = set_base(stack, i, ord);
	else if (ord == 1)
	{
		i = set_order_a(stack, i, div / 5, -ord);
		i = set_order_a(stack, i, div / 5, -ord);
		i = set_order_a(stack, i, div / 5, -ord);
		i = set_order_a(stack, i, div / 5, ord);
		i = set_order_a(stack, i, div / 5, ord);
	}
	else if (ord == -1)
	{
		i = set_order_a(stack, i, div / 5, ord);
		i = set_order_a(stack, i, div / 5, ord);
		i = set_order_a(stack, i, div / 5, -ord);
		i = set_order_a(stack, i, div / 5, -ord);
		i = set_order_a(stack, i, div / 5, -ord);
	}
	return (i);
}
