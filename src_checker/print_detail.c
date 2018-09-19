/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_detail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:53:50 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 16:13:28 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_under(int l)
{
	int		i;

	ft_printf("%s", MAGENTA);
	i = -1;
	while (++i < l)
		ft_printf("_");
	ft_printf(" ");
	i = -1;
	while (++i < l)
		ft_printf("_");
	ft_printf("\n%s", YELLOW);
}

void	print_status_detail(t_stack *st)
{
	int		i;
	int		j;
	int		k;
	int		l;

	l = st->num_len;
	k = (st->len_a > st->len_b) ? st->len_a : st->len_b;
	i = 0;
	j = 0;
	while (--k >= 0)
	{
		if (k < st->len_a)
			ft_printf("%*d ", l, st->a[(st->head_a + i++) % st->len].num);
		else
			ft_printf("%*s ", l, " ");
		if (k < st->len_b)
			ft_printf("%*d", l, st->b[(st->head_b + j++) % st->len].num);
		else
			ft_printf("%*s", l, " ");
		ft_printf("\n");
	}
	print_under(l);
	ft_printf("%*c %*c\n", l, 'a', l, 'b');
	ft_printf("%s-----------------------------------%s\n", BLUE, RESET);
}

void	print_detail(t_lst *lst, t_stack *stack)
{
	t_lst	*tmp;
	t_func	app[4];

	init_table(app, stack);
	stack->step = 0;
	ft_printf("%sInit a and b:\n%s", GREEN, YELLOW);
	print_status_detail(stack);
	tmp = lst->next;
	while (tmp)
	{
		app[tmp->data / 10].f(stack, 'a' + tmp->data % 10, 0);
		stack->step++;
		ft_printf("%sOperation: ", CYAN);
		print_op(tmp->data);
		ft_printf("%s", YELLOW);
		print_status_detail(stack);
		tmp = tmp->next;
	}
}
