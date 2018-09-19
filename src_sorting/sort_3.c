/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:18:19 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/13 08:52:54 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *stack, t_func *app, t_order *s, int a)
{
	int	h;
	int	l;

	h = (a == 'a') ? stack->head_a : stack->head_b;
	l = stack->len;
	if ((a == 'a') ? stack->len_a : stack->len_b == 3)
	{
		if (s[h].num < s[(h + 2) % l].num &&
				s[(h + 2) % l].num < s[(h + 1) % l].num)
			h = app[3].f(stack, a, 1) + app[2].f(stack, a, 1);
		else if (s[(h + 2) % l].num < s[(h + 1) % l].num &&
				s[(h + 1) % l].num < s[h].num)
			h = app[3].f(stack, a, 1) + app[1].f(stack, a, 1);
		else if (s[(h + 1) % l].num < s[(h + 2) % l].num &&
				s[(h + 2) % l].num < s[h].num)
			app[2].f(stack, a, 1);
		else if (s[(h + 1) % l].num > s[(h + 2) % l].num)
			app[1].f(stack, a, 1);
		else if (s[h].num > s[(h + 1) % l].num)
			app[3].f(stack, a, 1);
	}
	else if ((a == 'a') ? stack->len_a : stack->len_b == 2 &&
			s[h].num > s[(h + 1) % l].num)
		app[3].f(stack, a, 1);
}

void	sort_3_re(t_stack *stack, t_func *app, t_order *s, int a)
{
	int	h;
	int	l;

	h = (a == 'a') ? stack->head_a : stack->head_b;
	l = stack->len;
	if ((a == 'a') ? stack->len_a : stack->len_b == 3)
	{
		if (s[(h + 1) % l].num < s[(h + 2) % l].num &&
				s[(h + 2) % l].num < s[h].num)
			h = app[3].f(stack, a, 1) + app[2].f(stack, a, 1);
		else if (s[h].num < s[(h + 1) % l].num &&
				s[(h + 1) % l].num < s[(h + 2) % l].num)
			h = app[3].f(stack, a, 1) + app[1].f(stack, a, 1);
		else if (s[(h + 2) % l].num < s[h].num &&
				s[h].num < s[(h + 1) % l].num)
			app[3].f(stack, a, 1);
		else if (s[h].num < s[(h + 1) % l].num)
			app[2].f(stack, a, 1);
		else if (s[(h + 1) % l].num < s[(h + 2) % l].num)
			app[1].f(stack, a, 1);
	}
	else if ((a == 'a') ? stack->len_a : stack->len_b == 2
			&& s[h].num < s[(h + 1) % l].num)
		app[3].f(stack, a, 1);
}
