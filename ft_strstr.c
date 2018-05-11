/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:07:59 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/17 19:02:42 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	char	*nb;
	char	*nl;
	char	*begin;

	if (!big || !little)
		return (0);
	nb = (char*)big;
	if (!*little)
		return (nb);
	while (*nb)
	{
		nl = (char*)little;
		begin = nb;
		while (*nb == *nl && *nl && *nb)
		{
			nb++;
			nl++;
		}
		if (!*nl)
			return (begin);
		nb = begin + 1;
	}
	return (0);
}
