/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:30:14 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 16:04:48 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_op(int c)
{
	int		a;
	int		b;

	a = c / 10;
	b = c % 10;
	if (a != 1)
		ft_printf("%c", 'p' + a);
	else
		ft_printf("rr");
	if (b != 2)
		ft_printf("%c\n", 'a' + b);
	else if (a != 3)
		ft_printf("r\n");
	else
		ft_printf("s\n");
}

void	print_status_b(t_stack *stack)
{
	int	i;

	ft_printf("%s]\nstack b:\n[", RESET);
	i = -1;
	while (++i < stack->len)
	{
		if (stack->len_b > 0 && ((stack->head_b <= i && i <= stack->tail_b) ||
				(stack->tail_b < stack->head_b &&
				(i <= stack->tail_b || stack->head_b <= i))))
			ft_printf("%s%*d", YELLOW, stack->num_len + 1, stack->b[i].num);
		else
			ft_printf("%*s", stack->num_len + 1, " ");
	}
	ft_printf("]\n%s----------------------------------------\n", BLUE);
}

void	print_status(t_stack *stack, int c)
{
	int	i;

	if (c >= 0)
	{
		ft_printf("%soperation: ", RESET);
		print_op(c);
	}
	ft_printf("%sstack a:\n[", RESET);
	i = -1;
	while (++i < stack->len)
	{
		if (stack->len_a > 0 && ((stack->head_a <= i && i <= stack->tail_a) ||
				(stack->tail_a < stack->head_a &&
				(i <= stack->tail_a || stack->head_a <= i))))
			ft_printf("%s%*d", YELLOW, stack->num_len + 1, stack->a[i].num);
		else
			ft_printf("%*s", stack->num_len + 1, " ");
	}
	print_status_b(stack);
}

void	init_table(t_func *app, t_stack *stack)
{
	app[0].f = &operation_p;
	app[1].f = &operation_rr;
	app[2].f = &operation_r;
	app[3].f = &operation_s;
	stack->head_a = 0;
	stack->tail_a = stack->len - 1;
	stack->head_b = stack->len;
	stack->tail_b = stack->len - 1;
	stack->len_a = stack->len;
	stack->len_b = 0;
}

void	operations(t_lst *lst, t_stack *stack)
{
	t_lst	*tmp;
	t_func	app[4];

	init_table(app, stack);
	stack->step = 0;
	if (stack->visual)
	{
		ft_printf("initial:\n");
		print_status(stack, -1);
	}
	tmp = lst->next;
	while (tmp)
	{
		app[tmp->data / 10].f(stack, 'a' + tmp->data % 10, 0);
		stack->step++;
		if (stack->visual)
			print_status(stack, tmp->data);
		tmp = tmp->next;
	}
}
