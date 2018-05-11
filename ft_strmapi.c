/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:45:07 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/11 17:07:28 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(new = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		new[i] = f(i, *s);
		s++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
