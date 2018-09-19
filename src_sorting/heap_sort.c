/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:09:08 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/12 15:51:18 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_arr(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		ft_printf("%d ", stack->sort[i]);
	ft_printf("\n-----------------------------\n");
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	max_heapify(int *arr, int start, int end)
{
	int dad;
	int son;

	dad = start;
	son = dad * 2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
			son++;
		if (arr[dad] > arr[son])
			return ;
		else
		{
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void	heap_sort(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->len)
		stack->sort[i] = stack->a[i].num;
	i = stack->len / 2;
	while (--i >= 0)
		max_heapify(stack->sort, i, stack->len - 1);
	i = stack->len;
	while (--i > 0)
	{
		swap(&(stack->sort[0]), &(stack->sort[i]));
		max_heapify(stack->sort, 0, i - 1);
	}
}
