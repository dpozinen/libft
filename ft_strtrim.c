/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:40:33 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/19 17:49:15 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		front(char *s)
{
	int f;

	f = 0;
	while (s[f] == '\t' || s[f] == ' ' || s[f] == '\n')
		f++;
	return (f);
}

static int		back(char *s)
{
	int b;
	int r;

	b = ft_strlen(s) - 1;
	r = 0;
	while (s[b] == '\t' || s[b] == ' ' || s[b] == '\n')
	{
		b--;
		r++;
	}
	return (r);
}

static int		countw(char *s)
{
	int	size;
	int i;
	int j;

	i = front(s);
	j = back(s);
	size = ft_strlen(s) - i - j + 1;
	size <= 0 ? size = 1 : 0;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		f;
	int		b;

	if (!s)
		return (0);
	i = 0;
	f = 0;
	b = ft_strlen(s) - 1;
	if (!(ret = (char*)malloc(countw((char*)s))))
		return (0);
	f = front((char*)s);
	b = ft_strlen((char*)s) - back((char*)s) - 1;
	while (f <= b)
	{
		ret[i] = s[f];
		i++;
		f++;
	}
	ret[i] = '\0';
	return (ret);
}
