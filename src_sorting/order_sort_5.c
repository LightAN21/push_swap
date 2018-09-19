/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_sort_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:40:12 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/13 10:21:33 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_order(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		ft_printf("%c ", (char)(stack->sort[i]));
	ft_printf("\n-----------------------\n");
}

void	set_order(t_stack *stack, t_set *set)
{
	int		i;
	int		k;
	int		num;

	i = (set->log % 2) ? stack->len - 1 : 0;
	num = set->parts / 2 + set->parts % 2;
	k = -1;
	while (++k < num)
	{
		if (set->log % 2)
			i = set_order_b(stack, i, set->divisor, 1);
		else
			i = set_order_a(stack, i, set->divisor, -1);
	}
	num = set->parts / 2;
	k = -1;
	while (++k < num && i < stack->len)
	{
		if (set->log % 2)
			i = set_order_b(stack, i, set->divisor, -1);
		else
			i = set_order_a(stack, i, set->divisor, 1);
	}
}

void	init_setting(t_set *set, t_stack *stack, t_func *app)
{
	init_table(app, stack);
	set->log = 0;
	stack->base = 1;
	while (stack->base < stack->len)
	{
		set->log++;
		stack->base *= 5;
	}
	set->divisor = stack->base / 5;
	if (stack->base == stack->len)
		set->parts = 5;
	else
	{
		stack->base /= 5;
		set->parts = stack->len / stack->base + \
			((stack->len % stack->base) ? 1 : 0);
	}
	stack->base = 1;
}

void	order_sort_5(t_stack *stack)
{
	t_func	app[4];
	t_set	set;
	int		i;

	init_setting(&set, stack, app);
	i = -1;
	while (++i < set.log - 1)
	{
		set_order(stack, &set);
		push_bcde('b' - i % 2, stack, app, 'C');
		push_bcde('b' - i % 2, stack, app, 'B');
		push_all('b' - i % 2, stack, app);
		stack->base *= 5;
	}
	if (set.log % 2 == 0)
		special_order(stack, &set);
	else
		special_order_re(stack, &set);
	push_bcde('a' + set.log % 2, stack, app, 'C');
	if (set.parts > 2)
		push_bcde('a' + set.log % 2, stack, app, 'B');
	if (set.parts == 5)
		push_all('a' + set.log % 2, stack, app);
	if (set.log % 2)
		push_all('a', stack, app);
}
