/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:33:37 by dpozinen          #+#    #+#             */
/*   Updated: 2018/05/11 11:33:39 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_n_join(char *s1, char *s2, int f)
{
	char *tmp1;
	char *tmp2;
	char *ret;

	tmp2 = s2;
	tmp1 = s1;
	ret = ft_strjoin(s1, s2);
	if (f == 1)
		free(tmp1);
	if (f == 2)
		free(tmp2);
	if (f == 3)
	{
		free(tmp1);
		free(tmp2);
	}
	return (ret);
}
