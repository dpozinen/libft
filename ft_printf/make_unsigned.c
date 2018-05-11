/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:19:19 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/12 17:19:39 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_u_length(uintmax_t *n, t_attr *t_arg)
{
	if (t_arg->sp == 'p')
		return ;
	if (t_arg->sp == 'U' || t_arg->sp == 'O' || t_arg->sp == 'D')
		*n = (unsigned long int)*n;
	if (t_arg->sp != 'U' && t_arg->sp != 'O' && t_arg->sp != 'D')
	{
		if (t_arg->length == no)
			*n = (unsigned int)*n;
		if (t_arg->length == hh)
			*n = (unsigned char)*n;
		if (t_arg->length == h)
			*n = (unsigned short int)*n;
	}
	if (t_arg->length == t)
		*n = *((ptrdiff_t*)n);
	if (t_arg->length == l)
		*n = (unsigned long int)*n;
	if (t_arg->length == ll)
		*n = (unsigned long long int)*n;
	if (t_arg->length == j)
		*n = (uintmax_t)*n;
	if (t_arg->length == z)
		*n = (size_t)*n;
}

char	*to_base(uintmax_t n, int base, t_attr *t_arg, char *str)
{
	char			*ret_s;
	uintmax_t		nc;
	int				i;

	free(str);
	make_u_length(&n, t_arg);
	if (n == 0 && t_arg->sp == 'p')
		return (ret_s = ft_strdup(!t_arg->prec ? "0x\0" : "0x0\0"));
	else if (n == 0)
		return (ret_s = ft_strdup("0"));
	nc = n;
	i = 0;
	while (nc /= base)
		i++;
	if (!(ret_s = ft_strnew(i + 1)))
		return (0);
	while (n)
	{
		nc = n % base;
		ret_s[i] = (nc > 9) ? nc - 10 + 'a' : nc + '0';
		i--;
		n /= base;
	}
	t_arg->sp == 'p' ? ret_s = free_n_join("0x", ret_s, 2) : 0;
	return (ret_s);
}
