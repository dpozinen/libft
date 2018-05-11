/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:46:37 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/06 17:45:21 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*nstr;

	if (!str)
		return (0);
	nstr = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (nstr[i] == (unsigned char)c)
			return (&nstr[i]);
		i++;
	}
	return (0);
}
