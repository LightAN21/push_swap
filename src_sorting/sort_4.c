/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:58:41 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/13 10:16:31 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_min_max(t_stack *stack, t_order *s, int h, int c)
{
	int	i;
	int	len;

	stack->min = INT_MAX;
	stack->max = INT_MIN;
	len = (c == 'a') ? stack->len_a : stack->len_b;
	i = -1;
	while (++i < len)
	{
		if (s[(h + i) % stack->len].num > stack->max)
			stack->max = s[(h + i) % stack->len].num;
		if (s[(h + i) % stack->len].num < stack->min)
			stack->min = s[(h + i) % stack->len].num;
	}
}

void	sort_4_2(t_stack *stack, t_func *app, int c, int k)
{
	int		a;
	int		b;
	t_order	*s;

	a = (c == 'a') ? 'a' : 'b';
	b = (c == 'a') ? 'b' : 'a';
	s = (c == 'a') ? stack->a : stack->b;
	if (k == 1 || k == -1)
		app[2].f(stack, a, 1);
	else if (k == 3 || k == -3)
		app[1].f(stack, a, 1);
	else if (k == 2 || k == -2)
	{
		app[2].f(stack, a, 1);
		app[2].f(stack, a, 1);
	}
	app[0].f(stack, b, 1);
	if (k > 0)
		sort_3(stack, app, s, a);
	else
		sort_3_re(stack, app, s, a);
	app[0].f(stack, a, 1);
}

void	sort_4(t_stack *stack, t_func *app, t_order *s, int c)
{
	int		a;
	int		b;
	int		h;

	a = (c == 'a') ? 'a' : 'b';
	b = (c == 'a') ? 'b' : 'a';
	h = (c == 'a') ? stack->head_a : stack->head_b;
	find_min_max(stack, s, h, c);
	if (s[h].num == stack->min)
	{
		app[0].f(stack, b, 1);
		sort_3(stack, app, s, a);
		app[0].f(stack, a, 1);
	}
	else if (s[(h + 1) % stack->len].num == stack->min)
		sort_4_2(stack, app, c, 1);
	else if (s[(h + 2) % stack->len].num == stack->min)
		sort_4_2(stack, app, c, 2);
	else if (s[(h + 3) % stack->len].num == stack->min)
		sort_4_2(stack, app, c, 3);
}

void	sort_4_re(t_stack *stack, t_func *app, t_order *s, int c)
{
	int		a;
	int		b;
	int		h;

	a = (c == 'a') ? 'a' : 'b';
	b = (c == 'a') ? 'b' : 'a';
	h = (c == 'a') ? stack->head_a : stack->head_b;
	find_min_max(stack, s, h, c);
	if (s[h].num == stack->max)
	{
		app[0].f(stack, b, 1);
		sort_3_re(stack, app, s, a);
		app[0].f(stack, a, 1);
	}
	else if (s[(h + 1) % stack->len].num == stack->max)
		sort_4_2(stack, app, c, -1);
	else if (s[(h + 2) % stack->len].num == stack->max)
		sort_4_2(stack, app, c, -2);
	else if (s[(h + 3) % stack->len].num == stack->max)
		sort_4_2(stack, app, c, -3);
}
