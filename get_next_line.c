/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:07:05 by dpozinen          #+#    #+#             */
/*   Updated: 2018/01/18 15:07:05 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_list(int fd, t_list **head)
{
	t_list *t;

	t = *head;
	while (t)
	{
		if ((int)t->content_size == fd)
			return (t);
		t = t->next;
	}
	t = ft_lstnew("\0", fd);
	ft_lstadd(head, t);
	t = *head;
	return (t);
}

char	*make_both(char *content, char **line)
{
	char	*nl;
	int		after_nl_size;
	int		content_size;

	content_size = ft_strlen(content);
	if (!(nl = ft_strchr(content, '\n')))
		nl = (content + content_size);
	after_nl_size = ft_strlen(nl);
	if (!(*line = ft_strnew(content_size - after_nl_size)))
		return (0);
	*line = ft_strncpy(*line, content, content_size - after_nl_size);
	ft_strchr(content, '\n') == 0 ? ft_strclr(content) : 0;
	content = ft_strncpy(content, nl + 1, after_nl_size);
	return (content);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*t;
	ssize_t			bytes;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (!line || fd < 0 || !(t = find_list(fd, &head)) || read(fd, buf, 0) < 0)
		return (-1);
	bytes = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		tmp = t->content;
		t->content = ft_strjoin(t->content, buf);
		free(tmp);
	}
	if (!ft_strlen(t->content))
		return (0);
	else
		t->content = make_both(t->content, line);
	return (1);
}
