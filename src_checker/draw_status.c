/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:45:37 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 16:26:58 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	draw_block(t_bonus *p, int start_x, int start_y, int len)
{
	int	i;
	int	j;
	int	h;

	h = p->diff;
	i = -1;
	while (++i < p->diff)
	{
		j = -1;
		while (++j < len)
			mlx_pixel_put(p->mlx, p->win, start_x + j, start_y - i, 0xFFFFFF);
	}
}

void	draw_status(t_bonus *p, t_stack *stack)
{
	int	i;

	i = stack->len_a;
	while (--i >= 0)
	{
		draw_block(p, 1, p->len_y - (stack->len_a - i - 1) * (p->diff + 1) - 25,
				(stack->a[(stack->head_a + i) % stack->len].ord + 1) * p->diff);
	}
	i = stack->len_b;
	while (--i >= 0)
	{
		draw_block(p, p->len_x / 2 + 20,
				p->len_y - (stack->len_b - i - 1) * (p->diff + 1) - 25,
				(stack->b[(stack->head_b + i) % stack->len].ord + 1) * p->diff);
	}
}
