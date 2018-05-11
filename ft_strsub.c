/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:05:09 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/09 12:05:10 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!(ret = ft_strnew(len)) || !s)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		ret[i] = (char)s[start];
		start++;
		i++;
	}
	return (ret);
}
