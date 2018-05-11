/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:19:29 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/15 16:52:12 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	if (!dst || !src)
		return (0);
	r = ft_strlen(src) + ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (i >= size)
		r = ft_strlen(src) + size;
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (r);
}
