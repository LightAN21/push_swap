/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:27:22 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/13 10:36:26 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_bcde(char c, t_stack *stack, t_func *app, char key)
{
	t_record	r;

	r.s = (c == 'b') ? stack->a : stack->b;
	r.head = (c == 'b') ? &(stack->head_a) : &(stack->head_b);
	r.len = (c == 'b') ? stack->len_a : stack->len_b;
	r.key_2 = (key == 'C') ? 'D' : 'E';
	r.i = -1;
	while (++r.i < r.len)
	{
		r.tmp = stack->sort[r.s[*(r.head)].ord];
		if (r.tmp == key || r.tmp == r.key_2)
		{
			app[0].f(stack, c, 1);
			if (r.tmp == r.key_2)
			{
				r.tmp = stack->sort[r.s[*(r.head)].ord];
				if (r.tmp != key && r.tmp != r.key_2 && r.i != r.len - 1)
					r.i += 1 + app[2].f(stack, 'c', 1);
				else
					app[2].f(stack, c, 1);
			}
		}
		else
			app[2].f(stack, 'a' + 'b' - c, 1);
	}
}

void	push_all(char c, t_stack *stack, t_func *app)
{
	int		i;
	int		len;

	len = (c == 'b') ? stack->len_a : stack->len_b;
	i = -1;
	while (++i < len)
		app[0].f(stack, c, 1);
}
