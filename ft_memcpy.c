/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:12:40 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/06 15:10:20 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char			*nstr1;
	char			*nstr2;
	unsigned long	i;

	if (!str2 || !str1)
		return (0);
	i = 0;
	nstr1 = (char*)str1;
	nstr2 = (char*)str2;
	while (i < n)
	{
		nstr1[i] = nstr2[i];
		i++;
	}
	return (nstr1);
}
