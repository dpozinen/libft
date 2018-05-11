/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:00:26 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/07 11:32:02 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	size_t			i;

	i = 0;
	if (!src || !dst)
		return (0);
	nsrc = (unsigned char*)src;
	ndst = (unsigned char*)dst;
	while (i < n)
	{
		if (nsrc[i] == (unsigned char)c)
		{
			ndst[i] = nsrc[i];
			return (&ndst[++i]);
		}
		ndst[i] = nsrc[i];
		i++;
	}
	return (0);
}
