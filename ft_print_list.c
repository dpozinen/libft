/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:24:38 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/20 15:51:06 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list **head)
{
	t_list	*t;
	int		i;

	if (head && *head)
	{
		i = 1;
		t = *head;
		while (t)
		{
			ft_putendl((char*)t->content);
			i++;
			t = t->next;
		}
	}
}
