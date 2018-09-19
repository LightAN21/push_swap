/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:11:50 by jtsai             #+#    #+#             */
/*   Updated: 2018/09/14 15:52:25 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/minilibx/mlx.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include <limits.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"
# define BUFF_SIZE	1000

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_variable
{
	char			buff[BUFF_SIZE + 1];
	char			tmp[BUFF_SIZE + 1];
	int				len;
}					t_variable;

typedef struct		s_order
{
	int				num;
	int				ord;
}					t_order;

typedef struct		s_stack
{
	int				len;
	t_order			*a;
	t_order			*b;
	int				*sort;
	int				head_a;
	int				head_b;
	int				tail_a;
	int				tail_b;
	int				len_a;
	int				len_b;
	int				*op;
	int				step;
	int				max;
	int				min;
	int				base;
	int				num_len;
	int				visual;
	int				detail;
	int				s_step;
	int				mlx;
}					t_stack;

typedef struct		s_func
{
	int				(*f)(t_stack *, char, int);
}					t_func;

typedef struct		s_set
{
	int				log;
	int				divisor;
	int				parts;
}					t_set;

typedef struct		s_record
{
	t_order			*s;
	int				i;
	int				*head;
	int				len;
	int				tmp;
	int				key_2;
}					t_record;

typedef struct		s_bonus
{
	t_stack			*st;
	t_func			*app;
	t_lst			*lst;
	void			*mlx;
	void			*win;
	int				len_x;
	int				len_y;
	int				diff;
	int				mark;
}					t_bonus;

/*
** Check inputs:
*/
int					read_input(t_stack *stack, int ac, char **av);
int					read_instructions(t_lst *tmp);
int					check_result(t_stack *stack);
t_long				ft_check_atoi(const char *str);

/*
** Each operation funcrtions:
*/
int					operation_s(t_stack *stack, char c, int v);
int					operation_p(t_stack *stack, char c, int v);
int					operation_r(t_stack *stack, char c, int v);
int					operation_rr(t_stack *stack, char c, int v);

/*
** Sorting functions:
*/
void				print_steps(t_stack *stack);
int					sorting(t_stack *stack);
void				heap_sort(t_stack *stack);
void				binary_search(t_stack *stack);
void				order_sort_5(t_stack *stack);

void				push_all(char c, t_stack *stack, t_func *app);
void				push_bcde(char c, t_stack *stack, t_func *app, char key);

int					set_order_a(t_stack *stack, int i, int div, int ord);
int					set_order_b(t_stack *stack, int i, int div, int ord);
void				special_order(t_stack *stack, t_set *set);
void				special_order_re(t_stack *stack, t_set *set);

void				sort_3(t_stack *stacki, t_func *app, t_order *s, int a);
void				sort_3_re(t_stack *stack, t_func *app, t_order *s, int a);
void				sort_4(t_stack *stack, t_func *app, t_order *s, int c);
void				sort_4_re(t_stack *stack, t_func *app, t_order *s, int c);

void				print_operations(t_stack *stack);

/*
** Visiualization functions:
*/
void				init_table(t_func *app, t_stack *stack);
void				print_op(int c);
void				print_status(t_stack *stack, int c);
void				operations(t_lst *lst, t_stack *stack);
void				print_detail(t_lst *lst, t_stack *stack);

void				bonus_visual(t_lst *lst, t_stack *stack, t_bonus *p);
void				draw_status(t_bonus *p, t_stack *stack);

/*
** other functions:
*/
t_lst				*new_node(int num);
int					usage(void);
int					error_message(void);
int					free_stack(t_stack *stack);
#endif
