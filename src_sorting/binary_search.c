/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:40:17 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/10 11:08:34 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_ord(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		ft_printf("num: %d, ord: %d\n", stack->a[i].num, stack->a[i].ord);
}

int		search(int *arr, int key, int start, int end)
{
	int	ans;
	int	mid;

	ans = -1;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else
		{
			ans = mid;
			break ;
		}
	}
	return (ans);
}

void	binary_search(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
	{
		stack->a[i].ord = \
			search(stack->sort, stack->a[i].num, 0, stack->len - 1);
	}
}
