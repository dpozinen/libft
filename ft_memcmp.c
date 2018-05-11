/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:11:28 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/20 09:44:24 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*nstr1;
	unsigned char	*nstr2;
	size_t			i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	nstr1 = (unsigned char*)str1;
	nstr2 = (unsigned char*)str2;
	while (i < n)
	{
		if (nstr1[i] != nstr2[i])
			return ((unsigned char)nstr1[i] - (unsigned char)nstr2[i]);
		i++;
	}
	return (0);
}
