/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:05:43 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/20 09:50:51 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		overs(const char *s)
{
	if (ft_num_strlen(s) >= 19 && (ft_strcmp(s, "-9223372036854775808\0") == 0))
		return (0);
	if (s[0] == '-' && ft_num_strlen(s) >= 20
	&& ft_strcmp(s, "-9223372036854775807\0") >= 0)
		return (1);
	if (ft_num_strlen(s) >= 19 && (ft_strcmp(s, "9223372036854775807\0") > 0
	|| ft_strcmp(s, "+9223372036854775807\0") > 0))
		return (-1);
	return (2);
}

int				ft_atoi(const char *s)
{
	int				i;
	long long int	res;
	int				si;

	if (!s)
		return (0);
	res = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\r' || s[i] == '\n' ||
s[i] == ' ' || s[i] == '\f')
		i++;
	if (overs(s + i) != 2)
		return (overs(s + i));
	si = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit((char)s[i]) && (char)s[i])
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * si);
}
