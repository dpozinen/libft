/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:52:25 by dpozinen          #+#    #+#             */
/*   Updated: 2018/02/13 12:52:28 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "ft_printf.h"
# include <stdarg.h>

# define MALCHK(x) if (!x) return (0);

typedef enum		e_length
{
	no, hh, h, l, ll, j, t, z
}					t_length;

typedef enum		e_sign
{
	neg, nil, pos
}					t_sign;

typedef struct		s_argument_attributes
{
	char			sp;
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				apostrophe;
	intmax_t		width;
	intmax_t		prec;
	t_length		length;
	t_sign			sign;
	int				wchar_error;
	char			*ret_s;
}					t_attr;

int					execute_printf(va_list *arguments, char *format);

char				*make_unicode(va_list *arg, t_attr *t_arg, char *ret_s);

char				*ft_itoa_long(intmax_t i, t_attr *t_arg, char *s);
char				*to_base(uintmax_t n, int base, t_attr *t_arg, char *str);
char				*ft_insert_string(char *s2, char *s1, int where);
char				*make_flags(char *ret_s, t_attr *t_arg);
int					add_prec(const char *format, t_attr *t_arg);
int					add_width(const char *format, t_attr *t_arg);
void				add_length(const char *format, t_attr *t_arg);
char				*make_width(char *ret_s, t_attr *t_arg);
char				*make_prec(char *ret_s, t_attr *t_arg);
char				*string_to_upper(char *string);
char				*make_s_of_chars(int n, char c);
int					add_from_star(const char *format, t_attr *t_arg,
									va_list *arg);
char				*make_ret_s(va_list *arg, t_attr *t_arg, int chars_put);
char				*make_char_prec(char *ret_s, t_attr *t_arg);
char				*make_char_width(char *ret_s, t_attr *t_arg);
char				*make_apostrophe(char *ret_s);
void				put_ret_s(t_attr *t_arg, int *chars_put);
char				*make_uni(va_list *arg, t_attr *t_arg, char *ret_s);
#endif
