/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_width_precision_length.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:22:38 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/05 09:22:40 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_prec_width(char *s_ret_s, char *ret_s, t_attr *t_arg, int n)
{
	if (t_arg->sign == neg)
		if (n == 1 || (n == 0 && s_ret_s[0] == '0'))
		{
			ret_s = ft_insert_string(ret_s, s_ret_s, 1);
			free(s_ret_s);
			return (ret_s);
		}
	if (t_arg->sp == 'p')
		if ((n == 1) || (n == 0 && t_arg->zero))
		{
			ret_s = ft_insert_string(ret_s, s_ret_s, 2);
			free(s_ret_s);
			return (ret_s);
		}
	return (ret_s = free_n_join(s_ret_s, ret_s, 3));
}

char	*make_width(char *ret_s, t_attr *t_arg)
{
	char		*spaces_string;
	intmax_t	size;
	char		c;

	size = t_arg->width - ft_strlen(ret_s);
	c = (t_arg->zero && t_arg->prec < 0 && !t_arg->minus) ? '0' : ' ';
	if (t_arg->hash && t_arg->sign != nil)
	{
		if (t_arg->sp == 'X' || t_arg->sp == 'x')
			size -= 2;
		if (t_arg->sp == 'o' || t_arg->sp == 'O')
			size--;
	}
	if (ft_strchr("Ddi", t_arg->sp) && t_arg->sign != neg)
		if (t_arg->plus || t_arg->space)
			size--;
	if (size <= 0 || !(spaces_string = make_s_of_chars(size, c)))
		return (ret_s);
	if (t_arg->minus)
		ret_s = free_n_join(ret_s, spaces_string, 3);
	else
		ret_s = apply_prec_width(spaces_string, ret_s, t_arg, 0);
	return (ret_s);
}

char	*make_prec(char *ret_s, t_attr *t_arg)
{
	char		*prec_s;
	intmax_t	size;

	size = t_arg->prec;
	if (t_arg->sign == nil && size == 0 && t_arg->sp != 'p')
		return (ret_s = ft_strdup("\0"));
	size -= ft_strlen(ret_s);
	if (t_arg->sp == 'p')
		size += 2;
	t_arg->sign == neg ? size++ : 0;
	if (t_arg->hash && (t_arg->sp == 'o' || t_arg->sp == 'O'))
		if (t_arg->sign != nil)
			size--;
	if (size <= 0 || !(prec_s = make_s_of_chars(size, '0')))
		return (ret_s);
	ret_s = apply_prec_width(prec_s, ret_s, t_arg, 1);
	return (ret_s);
}
