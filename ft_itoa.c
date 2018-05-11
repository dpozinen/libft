/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:53:49 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/06 14:27:01 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char				*ret;
	long long int		ncopy;
	int					size;
	int					s;

	s = n < 0 ? 1 : 0;
	size = n <= 0 ? 1 : 0;
	ncopy = n < 0 ? -(long long int)n : (long long int)n;
	while (n)
	{
		n /= 10;
		size++;
	}
	if (!(ret = (char*)malloc(size + 1)))
		return (0);
	ret[0] = s == 1 ? '-' : '0';
	ret[size] = '\0';
	while (ncopy)
	{
		ret[size - 1] = ncopy % 10 + '0';
		size--;
		ncopy /= 10;
	}
	return (ret);
}
