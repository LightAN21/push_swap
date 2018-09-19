/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:14:55 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 09:07:05 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_instruction(char *s, int n)
{
	if (n == 3 && (s[0] == 's' || s[0] == 'p' || s[0] == 'r'))
	{
		if (s[1] == 'a' || s[1] == 'b')
			return ((s[0] - 'p') * 10 + s[1] - 'a');
		else if ((s[0] == 's' || s[0] == 'r') && s[1] == s[0])
			return ((s[0] - 'p') * 10 + 2);
	}
	else if (n == 4 && s[0] == 'r' && s[1] == 'r')
	{
		if (s[2] == 'a' || s[2] == 'b')
			return (10 + s[2] - 'a');
		else if (s[2] == 'r')
			return (12);
	}
	return (-1);
}

t_lst	*new_node(int num)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->data = num;
	new->next = NULL;
	return (new);
}

int		read_buff(t_variable *v, t_lst **t)
{
	int		i;
	int		check;

	i = -1;
	while (v->buff[++i])
	{
		v->tmp[v->len++] = v->buff[i];
		if (v->buff[i] == '\n')
		{
			check = check_instruction(v->tmp, v->len);
			if (check < 0)
				return (-1);
			(*t)->next = new_node(check);
			(*t) = (*t)->next;
			if (!(*t))
				return (-1);
			v->len = 0;
		}
	}
	return (1);
}

int		read_instructions(t_lst *lst)
{
	t_variable	v;
	t_lst		*tmp;
	int			n;

	tmp = lst;
	v.len = 0;
	while ((n = read(0, v.buff, BUFF_SIZE)) > 0)
	{
		v.buff[n] = '\0';
		if (read_buff(&v, &tmp) < 0)
			return (-1);
	}
	return (1);
}
