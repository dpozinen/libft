/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:53:49 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/09 17:53:50 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			make_s_length(intmax_t *n, t_attr *t_arg)
{
	if (t_arg->sp == 'D')
		*n = (long int)*n;
	if (t_arg->length == no && t_arg->sp != 'D')
		*n = (int)*n;
	if (t_arg->length == hh && t_arg->sp != 'D')
		*n = (signed char)*n;
	if (t_arg->length == h && t_arg->sp != 'D')
		*n = (short int)*n;
	if (t_arg->length == l)
		*n = (long int)*n;
	if (t_arg->length == ll)
		*n = (long long int)*n;
	if (t_arg->length == j)
		*n = (intmax_t)*n;
	if (t_arg->length == z)
		*n = (size_t)*n;
	if (t_arg->length == t)
		n = (ptrdiff_t*)n;
}

char			*ft_itoa_long(intmax_t n, t_attr *t_arg, char *str)
{
	char				*ret;
	intmax_t			ncopy;
	int					size;
	int					s;

	if (n == LONG_MIN)
		return (ret = ft_strdup("-9223372036854775808"));
	make_s_length(&n, t_arg);
	s = n < 0 ? 1 : 0;
	size = n < 0 ? 2 : 1;
	ncopy = n < 0 ? -n : n;
	while (n /= 10)
		size++;
	if (!(ret = ft_strnew(size)))
		return (0);
	ret[0] = s == 1 ? '-' : '0';
	while (ncopy)
	{
		ret[size - 1] = ncopy % 10 + '0';
		size--;
		ncopy /= 10;
	}
	free(str);
	return (ret);
}
