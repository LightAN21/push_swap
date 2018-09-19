/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:35:56 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 15:00:06 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	merge(t_stack *stack, t_func *app)
{
	int	i;
	int	j;

	i = stack->len_a;
	j = stack->len_b;
	while (i > 0 || j > 0)
	{
		if (i > 0 && (j == 0 ||
					stack->a[stack->tail_a].num > stack->b[stack->head_b].num))
		{
			app[1].f(stack, 'a', 1);
			i--;
		}
		else if (j > 0 && (i == 0 ||
					stack->a[stack->tail_a].num < stack->b[stack->head_b].num))
		{
			app[0].f(stack, 'a', 1);
			j--;
		}
	}
}

void	sort_basic_cases(t_stack *stack)
{
	t_func	app[4];
	int		i;

	init_table(app, stack);
	if (stack->len <= 3)
		sort_3(stack, app, stack->a, 'a');
	else if (stack->len == 4)
		sort_4(stack, app, stack->a, 'a');
	else if (stack->len > 4)
	{
		i = -1;
		while (++i < stack->len / 2)
			app[0].f(stack, 'b', 1);
		if (stack->len <= 6)
			sort_3(stack, app, stack->a, 'a');
		else
			sort_4(stack, app, stack->a, 'a');
		if (stack->len < 8)
			sort_3_re(stack, app, stack->b, 'b');
		else
			sort_4_re(stack, app, stack->b, 'b');
		merge(stack, app);
	}
}

int		check_unique(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->len)
	{
		if (stack->sort[i - 1] == stack->sort[i])
			return (-1);
	}
	return (1);
}

int		check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < stack->len)
	{
		if (stack->a[i - 1].num > stack->a[i].num)
			break ;
	}
	if (i == stack->len)
		return (1);
	return (0);
}

int		sorting(t_stack *stack)
{
	heap_sort(stack);
	if (check_unique(stack) < 0)
		return (-1);
	if (check_sorted(stack))
		return (0);
	binary_search(stack);
	stack->step = 0;
	if (stack->len > 8)
		order_sort_5(stack);
	else if (stack->len > 1)
		sort_basic_cases(stack);
	return (1);
}
