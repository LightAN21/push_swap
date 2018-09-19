/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:31:26 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/15 15:49:24 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	return (-1);
}

int	free_lst(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*t;

	tmp = lst;
	while (tmp)
	{
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
	return (-1);
}

int	check_unique_c(t_stack *stack)
{
	int	i;

	heap_sort(stack);
	i = 0;
	while (++i < stack->len)
	{
		if (stack->sort[i - 1] == stack->sort[i])
			return (-1);
	}
	return (1);	
}

int	main(int ac, char **av)
{
	t_lst	*lst;
	t_stack	stack;
	t_bonus	pt;

	if (read_input(&stack, ac, av) <= 0)
		return (0);
	if (check_unique_c(&stack) < 0)
		return (free_stack(&stack) + error_message());
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (free_stack(&stack) + error_message());
	lst->data = 0;
	lst->next = NULL;
	if (read_instructions(lst) < 0)
		return (free_stack(&stack) + free_lst(lst) + error_message());
	if (stack.mlx)
		bonus_visual(lst, &stack, &pt);
	else if (stack.detail)
		print_detail(lst, &stack);
	else
		operations(lst, &stack);
	check_result(&stack);
	free_stack(&stack);
	free_lst(lst);
	free(stack.sort);
	return (0);
}
