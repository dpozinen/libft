/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:08:35 by dpozinen          #+#    #+#             */
/*   Updated: 2018/01/30 12:08:36 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		ret;

	va_start(arguments, format);
	ret = execute_printf(&arguments, (char*)format);
	va_end(arguments);
	return (ret);
}
