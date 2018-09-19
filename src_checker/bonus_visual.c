/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 20:10:36 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 14:21:50 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_screen(t_stack *stack, t_bonus *p)
{
	int	r;

	if (stack->len >= 600)
	{
		p->len_x = stack->len * 2 + 50;
		p->len_y = stack->len + 50;
		p->diff = 2;
	}
	else
	{
		r = 600 / stack->len;
		p->len_x = stack->len * r * 2 + 50;
		p->len_y = stack->len * (r + 1) + 50;
		p->diff = r;
	}
}

int		deal_enter(int key, t_bonus *p)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (p->lst)
	{
		mlx_clear_window(p->mlx, p->win);
		p->app[p->lst->data / 10].f(p->st, 'a' + p->lst->data % 10, 0);
		draw_status(p, p->st);
		p->st->step++;
		p->lst = p->lst->next;
	}
	else if (!p->lst && p->mark)
	{
		if (check_result(p->st) < 0)
			mlx_string_put(p->mlx, p->win, 10, 5, 0xFF5500, "    Checker: KO.");
		else
			mlx_string_put(p->mlx, p->win, 10, 5, 0x66C2FF, "    Checker: OK!");
		p->mark = 0;
	}
	return (0);
}

void	bonus_visual(t_lst *lst, t_stack *stack, t_bonus *p)
{
	t_func	app[4];

	init_table(app, stack);
	stack->step = 0;
	heap_sort(stack);
	binary_search(stack);
	init_screen(stack, p);
	p->st = stack;
	p->app = app;
	p->lst = lst->next;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->len_x, p->len_y, "push_swap checker");
	draw_status(p, stack);
	mlx_hook(p->win, 2, 2, deal_enter, (void *)p);
	mlx_loop(p->mlx);
}
