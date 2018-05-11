/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:47:01 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/11 17:09:05 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	if (!f || !s)
		return (NULL);
	while (s[i])
		i++;
	if (!(new = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		new[i] = f(*s);
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
