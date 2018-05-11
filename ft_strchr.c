/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:29:52 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/07 12:44:46 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char *ns;

	if (!s)
		return (0);
	ns = (char*)s;
	while (*ns)
	{
		if (*ns == (unsigned char)c)
			return (ns);
		ns++;
	}
	if ((unsigned char)c == '\0')
		return (ns);
	return (0);
}
