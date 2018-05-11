/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_s_of_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:35:42 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/11 11:35:44 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_s_of_chars(int n, char c)
{
	char	*s;
	int		i;

	if (n <= 0 || !(s = ft_strnew(n)))
		return (0);
	i = 0;
	while (i < n)
		s[i++] = c;
	return (s);
}
