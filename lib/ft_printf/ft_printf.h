/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:37:07 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/30 12:06:27 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <locale.h>

# define LEN 151072

typedef unsigned long long int	t_max;
typedef long long int			t_long;

typedef struct					s_var
{
	va_list						args;
	int							k;
	char						p[LEN];
	t_long						flag[128];
	t_long						return_value;
}								t_var;

/*
**		 	   {-,  +, space, 0,  #,   *,  min_width, '.', pre_width}
** flag[128] : '-','+',' ' , '0','#', '*', '_',       '.', '/'
*/

int								ft_printf(const char *s, ...);
int								read_specifier(t_var *data, char type, int i);
int								type(int k);
int								read_flags(t_var *v, char *s, int i);
int								re_atoi(char *s, int *i);

void							save_itoa(t_var *v, int k, t_long num);
void							save_itoa_base(t_var *v,
		t_max num, t_max base, char c);
void							deal_int(t_var *v, t_long num);
void							deal_int_base(t_var *data,
		t_max num, t_max base, char c);

void							save_char(t_var *v,
		t_long bound, t_long mark, char c);

void							deal_char(t_var *v, int c);
void							deal_str(t_var *v, char *s);
void							deal_l_str(t_var *data, wchar_t *s);
void							save_str(t_var *v, char *s, t_long len);
void							save_l_str(t_var *v, wchar_t *s, t_long len);

t_long							ft_wide_strllen(wchar_t *s);
void							save_wide_char(t_var *data, wchar_t wc);
void							deal_wide_char(t_var *data, wchar_t wc);
void							deal_wide_string(t_var *data, wchar_t *ws);
void							null_str(t_var *data);

#endif
