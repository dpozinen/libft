/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:57:34 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/08 11:37:22 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*nb;
	char	*nl;
	size_t	begin;

	if (!big || !little)
		return (0);
	nb = (char*)big;
	if (!*little)
		return (nb);
	i = 0;
	while (nb[i] && i < len)
	{
		nl = (char*)little;
		begin = i;
		while (nb[i] == *nl && *nl && nb[i] && i < len)
		{
			i++;
			nl++;
		}
		if (!*nl)
			return (&nb[begin]);
		i = begin + 1;
	}
	return (0);
}
