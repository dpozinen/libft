/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:51:09 by dpozinen          #+#    #+#             */
/*   Updated: 2018/02/13 12:51:44 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_flags(char *ret_s, t_attr *t_arg)
{
	int i;

	find_not_c(' ', ret_s, &i);
	if (t_arg->hash)
	{
		if (t_arg->sign != nil)
		{
			if (t_arg->sp == 'x' || t_arg->sp == 'X')
				ret_s = ft_insert_string(ret_s, "0x", i);
			if ((t_arg->sp == 'o' || t_arg->sp == 'O'))
				ret_s = ft_insert_string(ret_s, "0", i);
		}
		if (t_arg->sign == nil && t_arg->prec == 0)
			if (t_arg->sp == 'o' || t_arg->sp == 'O')
				ret_s = ft_insert_string(ret_s, "0", i);
	}
	if (t_arg->sign != neg && ft_strchr("Ddi", t_arg->sp))
	{
		if (t_arg->plus)
			ret_s = ft_insert_string(ret_s, "+", i);
		if (t_arg->space && !t_arg->plus)
			ret_s = free_n_join(" ", ret_s, 2);
	}
	return (ret_s);
}

char	*make_apostrophe(char *ret_s)
{
	char			*help_s;
	struct lconv	*lc;
	size_t			i;

	lc = localeconv();
	if (!(*(lc->thousands_sep)))
		return (ret_s);
	help_s = lc->thousands_sep;
	i = ft_strlen(ret_s) - 3;
	while (ret_s[i] && i > 0 && ft_isdigit(ret_s[i - 1]))
	{
		ret_s = ft_insert_string(ret_s, help_s, i);
		i -= 3;
	}
	return (ret_s);
}
