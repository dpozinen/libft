/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_while_not_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:47:53 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/21 14:47:53 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_while_not_c(char *format, char c)
{
	int size;

	size = 0;
	while (format[size] != c && format[size])
		size++;
	write(1, format, size);
}
