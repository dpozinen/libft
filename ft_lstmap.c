/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:10:42 by dpozinen          #+#    #+#             */
/*   Updated: 2017/11/20 15:50:25 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f_lstdel(void *content, size_t content_size)
{
	content = NULL;
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *make;
	t_list *t;
	t_list *head;

	if (!lst || !f)
		return (0);
	t = f(lst);
	if (!(make = ft_lstnew(t->content, t->content_size)))
		return (0);
	head = make;
	lst = lst->next;
	while (lst)
	{
		t = f(lst);
		if (!(make->next = ft_lstnew(t->content, t->content_size)))
		{
			ft_lstdel(&head, &f_lstdel);
			return (0);
		}
		make = make->next;
		lst = lst->next;
	}
	return (head);
}
