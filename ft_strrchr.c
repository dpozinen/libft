/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:17:58 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/07 12:43:46 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ns;
	char	*rs;

	if (!s)
		return (0);
	ns = (char*)s;
	rs = 0;
	if ((char)c == '\0')
	{
		while (*ns)
			ns++;
		return (ns);
	}
	while (*ns)
	{
		if (*ns == (char)c)
			rs = ns;
		ns++;
	}
	return (rs);
}
