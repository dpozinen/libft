/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:34:40 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/15 16:15:22 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;

	if (!alst || !*alst || !del)
		return ;
	t = *alst;
	while (t)
	{
		del(t->content, t->content_size);
		t = t->next;
	}
	free(*alst);
	*alst = NULL;
}
