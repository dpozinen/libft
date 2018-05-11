/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_char_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:24 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/19 19:19:28 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_char_prec(char *ret_s, t_attr *t_arg)
{
	char	*prec_s;

	if (t_arg->prec < 0 || !(prec_s = ft_strnew(t_arg->prec)))
		return (ret_s);
	ft_strncpy(prec_s, ret_s, t_arg->prec);
	free(ret_s);
	return (prec_s);
}

char	*make_char_width(char *ret_s, t_attr *t_arg)
{
	char		*help_s;
	intmax_t	size;
	char		c;

	c = (t_arg->zero && !t_arg->minus) ? '0' : ' ';
	size = t_arg->width - ft_strlen(ret_s);
	if (t_arg->sp == 'c' && t_arg->length != l)
		size = t_arg->width - 1;
	if ((t_arg->sp == 'c' && t_arg->length == l) || t_arg->sp == 'C')
		if (t_arg->wchar_error == 2)
			size = t_arg->width - 1;
	if (size <= 0 || !(help_s = make_s_of_chars(size, c)))
		return (ret_s);
	if (t_arg->minus)
		ret_s = free_n_join(ret_s, help_s, 3);
	else
		ret_s = free_n_join(help_s, ret_s, 3);
	return (ret_s);
}
