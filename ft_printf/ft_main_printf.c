 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:08:55 by dpozinen          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:56 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_attr	*init_argument(void)
{
	t_attr *t_arg;

	if (!(t_arg = (t_attr*)malloc(sizeof(t_attr))))
		return (0);
	t_arg->sp = 0;
	t_arg->hash = 0;
	t_arg->minus = 0;
	t_arg->plus = 0;
	t_arg->space = 0;
	t_arg->zero = 0;
	t_arg->width = 0;
	t_arg->prec = -1;
	t_arg->length = no;
	t_arg->sign = pos;
	t_arg->wchar_error = 0;
	t_arg->ret_s = 0;
	t_arg->apostrophe = 0;
	return (t_arg);
}

int		is_format(char *format, t_attr *t_arg)
{
	char c;

	if (!*format)
		return (0);
	c = *format;
	if (ft_isdigit(c))
		return (1);
	if (ft_strchr("\'L#-+. *", c))
		return (1);
	if (ft_strchr("tlhjz", c))
	{
		add_length((format), t_arg);
		return (1);
	}
	if (ft_strchr("cCsSdDioOuUxXpn", c))
	{
		t_arg->sp = c;
		return (1);
	}
	return (0);
}

int		analyze_format(char *format, va_list *arg, t_attr *t_arg, int *ch_put)
{
	int	i;

	i = 0;
	while (t_arg->sp == 0 && is_format((format + i), t_arg))
	{
		format[i] == '0' ? t_arg->zero = 1 : 0;
		i += ft_isdigit(format[i]) ? add_width((format + i), t_arg) : 0;
		i += format[i] == '.' ? add_prec((format + i), t_arg) : 0;
		format[i] == '*' ? add_from_star((format + i), t_arg, arg) : 0;
		format[i] == '#' ? t_arg->hash = 1 : 0;
		format[i] == '-' ? t_arg->minus = 1 : 0;
		format[i] == ' ' ? t_arg->space = 1 : 0;
		format[i] == '+' ? t_arg->plus = 1 : 0;
		format[i] == '\'' ? t_arg->apostrophe = 1 : 0;
		i++;
	}
	(!t_arg->sp && format[i]) ? t_arg->sp = format[i++] : 0;
	t_arg->sp ? t_arg->ret_s = make_ret_s(arg, t_arg, *ch_put) : 0;
	if (t_arg->wchar_error == 1)
	{
		*ch_put = -1;
		free(t_arg->ret_s);
		free(t_arg);
	}
	return (i + 1);
}

int		execute_printf(va_list *arg, char *format)
{
	int		i;
	int		chars_put;
	int		f;
	t_attr	*t_arg;

	chars_put = 0;
	i = 0;
	while (format[i])
	{
		f = i;
		i += get_char_index(format + i, '%');
		chars_put += i - f;
		if (format[i] == '%')
		{
			MALCHK((t_arg = init_argument()));
			i += analyze_format((format + i + 1), arg, t_arg, &chars_put);
			if (chars_put == -1)
				return (-1);
			put_while_not_c((format + f), '%');
			put_ret_s(t_arg, &chars_put);
		}
		else
			put_while_not_c((format + f), '\0');
	}
	return (chars_put);
}
