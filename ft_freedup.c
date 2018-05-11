/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:42:14 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/28 11:45:30 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freedup(char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	if (!(dup = (char*)malloc(ft_strlen(s1) + 1)))
		return (0);
	while (i < ft_strlen(s1))
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	free(s1);
	return (dup);
}
