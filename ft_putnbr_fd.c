/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:29:01 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/12 15:29:02 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		dn;
	char	c;

	if (!fd)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648\0", 12);
		return ;
	}
	n < 0 ? write(fd, "-", 1) : 0;
	n = n < 0 ? -n : n;
	dn = 1;
	while (dn < n / 10)
		dn *= 10;
	while (dn > 0)
	{
		c = n / dn + '0';
		n %= dn;
		dn /= 10;
		write(fd, &c, 1);
	}
}
