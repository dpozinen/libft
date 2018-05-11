/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:34:10 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/11 11:34:11 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_string(char *s_original, char *s_to_insert, int where)
{
	int		i;
	char	*s_ret;
	int		i_so;

	i_so = 0;
	i = 0;
	if (!(s_ret = ft_strnew(ft_strlen(s_original) + ft_strlen(s_to_insert))))
		return (0);
	while (i < where && s_original[i_so])
		s_ret[i++] = s_original[i_so++];
	while (*s_to_insert)
		s_ret[i++] = *s_to_insert++;
	while (s_original[i_so])
		s_ret[i++] = s_original[i_so++];
	free(s_original);
	return (s_ret);
}
