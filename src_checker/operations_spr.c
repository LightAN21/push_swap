/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_spr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:48:51 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/15 15:50:40 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operation_s(t_stack *st, char c, int v)
{
	int	tmp;

	if (v)
		st->op[st->step++] = 30 + c - 'a';
	if (c == 'a' && st->len_a > 1)
	{
		tmp = st->a[st->head_a].num;
		st->a[st->head_a].num = st->a[(st->head_a + 1) % st->len].num;
		st->a[(st->head_a + 1) % st->len].num = tmp;
		tmp = st->a[st->head_a].ord;
		st->a[st->head_a].ord = st->a[(st->head_a + 1) % st->len].ord;
		st->a[(st->head_a + 1) % st->len].ord = tmp;
	}
	else if (c == 'b' && st->len_b > 1)
	{
		tmp = st->b[st->head_b].num;
		st->b[st->head_b].num = st->b[(st->head_b + 1) % st->len].num;
		st->b[(st->head_b + 1) % st->len].num = tmp;
		tmp = st->b[st->head_b].ord;
		st->b[st->head_b].ord = st->b[(st->head_b + 1) % st->len].ord;
		st->b[(st->head_b + 1) % st->len].ord = tmp;
	}
	else if (c == 'c')
		return (operation_s(st, 'a', 0) + operation_s(st, 'b', 0));
	return (0);
}

int	operation_p(t_stack *stack, char c, int v)
{
	if (v)
		stack->op[stack->step++] = c - 'a';
	if (c == 'a' && stack->len_b > 0)
	{
		stack->head_a--;
		if (stack->head_a < 0)
			stack->head_a = stack->len - 1;
		stack->a[stack->head_a].ord = stack->b[stack->head_b].ord;
		stack->a[stack->head_a].num = stack->b[stack->head_b++].num;
		if (stack->head_b == stack->len)
			stack->head_b = 0;
		stack->len_a += 1 + (--stack->len_b & 0);
	}
	else if (c == 'b' && stack->len_a > 0)
	{
		stack->head_b--;
		if (stack->head_b < 0)
			stack->head_b = stack->len - 1;
		stack->b[stack->head_b].ord = stack->a[stack->head_a].ord;
		stack->b[stack->head_b].num = stack->a[stack->head_a++].num;
		if (stack->head_a == stack->len)
			stack->head_a = 0;
		stack->len_a += -1 + (++stack->len_b & 0);
	}
	return (0);
}

int	operation_r(t_stack *stack, char c, int v)
{
	if (v)
		stack->op[stack->step++] = 20 + c - 'a';
	if (c == 'a' && stack->len_a > 1)
	{
		stack->tail_a++;
		if (stack->tail_a == stack->len)
			stack->tail_a = 0;
		stack->a[stack->tail_a].ord = stack->a[stack->head_a].ord;
		stack->a[stack->tail_a].num = stack->a[stack->head_a++].num;
		if (stack->head_a == stack->len)
			stack->head_a = 0;
	}
	else if (c == 'b' && stack->len_b > 1)
	{
		stack->tail_b++;
		if (stack->tail_b == stack->len)
			stack->tail_b = 0;
		stack->b[stack->tail_b].ord = stack->b[stack->head_b].ord;
		stack->b[stack->tail_b].num = stack->b[stack->head_b++].num;
		if (stack->head_b == stack->len)
			stack->head_b = 0;
	}
	else if (c == 'c')
		return (operation_r(stack, 'a', 0) + operation_r(stack, 'b', 0));
	return (0);
}

int	operation_rr(t_stack *stack, char c, int v)
{
	if (v)
		stack->op[stack->step++] = 10 + c - 'a';
	if (c == 'a' && stack->len_a > 1)
	{
		stack->head_a--;
		if (stack->head_a < 0)
			stack->head_a = stack->len - 1;
		stack->a[stack->head_a].ord = stack->a[stack->tail_a].ord;
		stack->a[stack->head_a].num = stack->a[stack->tail_a--].num;
		if (stack->tail_a < 0)
			stack->tail_a = stack->len - 1;
	}
	else if (c == 'b' && stack->len_b > 1)
	{
		stack->head_b--;
		if (stack->head_b < 0)
			stack->head_b = stack->len - 1;
		stack->b[stack->head_b].ord = stack->b[stack->tail_b].ord;
		stack->b[stack->head_b].num = stack->b[stack->tail_b--].num;
		if (stack->tail_b < 0)
			stack->tail_b = stack->len - 1;
	}
	else if (c == 'c')
		return (operation_rr(stack, 'a', 0) + operation_rr(stack, 'b', 0));
	return (0);
}

int	check_result(t_stack *stack)
{
	int	i;

	if (stack->len_b != 0)
	{
		ft_printf("%sKO\n%s", RED, RESET);
		return (-1);
	}
	i = 0;
	while (++i < stack->len_a)
	{
		if (stack->a[(stack->head_a + i) % stack->len].num <
				stack->a[(stack->head_a + i - 1) % stack->len].num)
		{
			ft_printf("%sKO\n%s", RED, RESET);
			return (-1);
		}
	}
	ft_printf("%sOK\n%s", GREEN, RESET);
	if (stack->s_step)
		ft_printf("steps:\n%s%d%s\n", GREEN, stack->step, RESET);
	return (1);
}
