/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:49:24 by dpozinen          #+#    #+#             */
/*   Updated: 2018/02/13 12:49:25 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_from_star(const char *format, t_attr *t_arg, va_list *arg)
{
	int holder;

	holder = va_arg(*arg, int);
	if (*(format - 1) && *(format - 1) == '.')
		t_arg->prec = holder;
	else
	{
		if (holder < 0)
		{
			t_arg->minus = 1;
			holder *= -1;
		}
		t_arg->width = holder;
	}
	return (1);
}

int		add_prec(const char *format, t_attr *t_arg)
{
	int		i;
	size_t	prec;

	prec = 0;
	i = 1;
	if (format[i + 1] == '*')
		return (0);
	while (ft_isdigit(format[i]))
	{
		prec = (prec * 10) + (format[i] - '0');
		i++;
	}
	t_arg->prec = prec;
	if (i == 1)
		return (0);
	return (i - 1);
}

int		add_width(const char *format, t_attr *t_arg)
{
	int		i;
	size_t	width;

	width = 0;
	i = 0;
	while (ft_isdigit(format[i]))
	{
		width = (width * 10) + (format[i] - '0');
		i++;
	}
	if (width > 0)
		t_arg->width = width;
	if (i == 0)
		return (0);
	return (i - 1);
}

void	add_length(const char *format, t_attr *t_arg)
{
	if (*format == 't' && t_arg->length < t)
		t_arg->length = t;
	if (*format == 'j' && t_arg->length < j)
		t_arg->length = j;
	if (*format == 'z' && t_arg->length < z)
		t_arg->length = z;
	if (*format == 'h' && *(format + 1) == 'h' && t_arg->length < hh)
		t_arg->length = hh;
	if (*format == 'h' && t_arg->length < h && t_arg->length != hh)
		t_arg->length = h;
	if (*format == 'l' && *(format + 1) == 'l' && t_arg->length < ll)
		t_arg->length = ll;
	if (*format == 'l' && t_arg->length < l && t_arg->length != ll)
		t_arg->length = l;
}
