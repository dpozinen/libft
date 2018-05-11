/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:39:53 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/11 13:39:57 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		stars(char *s, char c, int i)
{
	if (*s != c && i == 0)
		return (1);
	if (*s == c && *(s + 1) == '\0')
		return (0);
	if (*s == c && *(s + 1) != c)
		return (1);
	return (0);
}

static int		times(char *s, char c)
{
	int t;
	int i;

	i = 0;
	t = 1;
	while (s[i])
	{
		if (stars(&s[i], c, i))
			t++;
		i++;
	}
	return (t);
}

static char		*wrtoarr(char *s, int until)
{
	int		i;
	char	*ret;

	if (!(ret = ft_strnew(until + 1)))
		return (0);
	i = 0;
	while (i < until)
	{
		ret[i] = s[i];
		i++;
	}
	ret[until] = '\0';
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		start;
	int		r;

	r = 0;
	i = 0;
	if (!s || !(ret = (char**)malloc(sizeof(char*) * times((char*)s, c))))
		return (0);
	while ((char)s[i] && r < times((char*)s, c))
	{
		if (stars((char*)&s[i], c, i))
		{
			start = s[i] == c ? ++i : i;
			while ((char)s[i] != c && (char)s[i] != '\0')
				i++;
			if (!(ret[r] = wrtoarr((char*)&s[start], i - start)))
				return (free_char_array(ret, r));
			r++;
		}
		else
			i++;
	}
	ret[r] = 0;
	return (ret);
}
