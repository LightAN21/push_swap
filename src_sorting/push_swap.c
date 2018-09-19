/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 17:59:01 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/15 10:20:19 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	return (-1);
}

int		free_stack_2(t_stack *stack)
{
	free(stack->op);
	free(stack->sort);
	return (-1);
}

int		malloc_op(t_stack *stack)
{
	int		base;
	int		k;

	base = 1;
	k = 0;
	while (base < stack->len)
	{
		base *= 2;
		k++;
	}
	if (stack->len < 10)
		k += 10;
	if (!(stack->op = (int *)malloc(2 * stack->len * k * sizeof(int))))
		return (-1);
	return (1);
}

void	print_operations(t_stack *stack)
{
	int		i;
	int		a;
	int		b;

	i = -1;
	while (++i < stack->step)
	{
		a = stack->op[i] / 10;
		b = stack->op[i] % 10;
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
}

int		main(int ac, char **av)
{
	t_stack	stack;

	if (read_input(&stack, ac, av) <= 0)
		return (0);
	if (stack.detail || stack.s_step || stack.mlx || stack.visual)
		return (free_stack(&stack) + error_message());
	if (malloc_op(&stack) < 0)
		return (free_stack(&stack) + error_message());
	if (sorting(&stack) < 0)
		return (free_stack(&stack) + free_stack_2(&stack) + error_message());
	print_operations(&stack);
	free_stack(&stack);
	free_stack_2(&stack);
	return (0);
}
