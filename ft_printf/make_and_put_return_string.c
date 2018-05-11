/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_put_return_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:22:25 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/05 09:22:25 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_all_options(char *ret_s, t_attr *t_arg)
{
	char c;

	c = t_arg->sp;
	if (ret_s[0] == '-')
		t_arg->sign = neg;
	if (*ret_s == '0' || !ft_strcmp("0x0", ret_s) || !ft_strcmp("0x", ret_s))
		t_arg->sign = nil;
	if (t_arg->apostrophe && ft_strchr("DdiUu", t_arg->sp))
		ret_s = make_apostrophe(ret_s);
	if (t_arg->prec >= 0)
		ret_s = make_prec(ret_s, t_arg);
	if (t_arg->width > 0)
		ret_s = make_width(ret_s, t_arg);
	ret_s = make_flags(ret_s, t_arg);
	if (c == 'X')
		ret_s = string_to_upper(ret_s);
	return (ret_s);
}

char	*make_ret_s_chars(va_list *arg, t_attr *t_arg, char *ret_s)
{
	char c;

	c = t_arg->sp;
	if (c == 's' && t_arg->length != l)
		ret_s = free_n_join(ret_s, va_arg(*arg, char*), 1);
	else if (c == 'c' && t_arg->length != l)
		*ret_s = (char)va_arg(*arg, int);
	else if (c == 'C' || c == 'S' || c == 'c' || c == 's')
		ret_s = make_uni(arg, t_arg, ret_s);
	else
	{
		*ret_s = t_arg->sp;
		t_arg->sp = 'c';
	}
	if (!ret_s && (c == 's' || c == 'S'))
		ret_s = ft_strdup("(null)");
	if (!*ret_s)
		t_arg->sign = nil;
	if (t_arg->prec >= 0 && (t_arg->sp == 'S' || t_arg->sp == 's'))
		ret_s = make_char_prec(ret_s, t_arg);
	if (t_arg->width > 0)
		ret_s = make_char_width(ret_s, t_arg);
	return (ret_s);
}

char	*make_ret_s(va_list *arg, t_attr *t_arg, int chars_put)
{
	char		*ret_s;
	char		c;
	uintmax_t	*n;

	if (t_arg->sp == 'n')
	{
		n = va_arg(*arg, uintmax_t*);
		*n = chars_put;
		return (0);
	}
	if (!(ret_s = ft_strnew(4)))
		return (0);
	c = t_arg->sp;
	if (c == 'i' || c == 'd' || c == 'D')
		ret_s = ft_itoa_long(va_arg(*arg, intmax_t), t_arg, ret_s);
	else if (c == 'o' || c == 'O')
		ret_s = to_base(va_arg(*arg, uintmax_t), 8, t_arg, ret_s);
	else if (c == 'x' || c == 'X' || c == 'p')
		ret_s = to_base(va_arg(*arg, uintmax_t), 16, t_arg, ret_s);
	else if (c == 'U' || c == 'u')
		ret_s = to_base(va_arg(*arg, uintmax_t), 10, t_arg, ret_s);
	else if (c == 'b')
		ret_s = to_base(va_arg(*arg, uintmax_t), 2, t_arg, ret_s);		
	else
		return (ret_s = make_ret_s_chars(arg, t_arg, ret_s));
	return (ret_s = apply_all_options(ret_s, t_arg));
}

void	put_ret_s(t_attr *t_arg, int *chars_put)
{
	char	*ret_s;

	if (!t_arg->sp || !t_arg->ret_s)
		return ;
	ret_s = t_arg->ret_s;
	*chars_put += ft_strlen(ret_s);
	if (t_arg->sign == nil && (t_arg->sp == 'c' || t_arg->sp == 'C'))
	{
		if (t_arg->minus)
			write(1, "\0", 1);
		ft_putstr(ret_s);
		if (!t_arg->minus)
			write(1, "\0", 1);
		(*chars_put)++;
	}
	else
		ft_putstr(ret_s);
	free(ret_s);
	free(t_arg);
}
