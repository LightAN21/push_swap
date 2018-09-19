/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:48:22 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/15 11:15:21 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	usage(void)
{
	ft_printf("%sError\n", RED);
	ft_printf("(no arguments)\n");
	ft_printf("%susage:\n", GREEN);
	ft_printf("./push_swap strings_of_numbers\n");
	ft_printf("./checker [-mdvs] strings_of_numbers\n%s", RESET);
	return (0);
}

int	error_message(void)
{
	write(1, "Error\n", 6);
	return (-1);
}
