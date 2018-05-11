/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:20:16 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/12 17:20:16 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_wchar(wchar_t chr, char *ret_s, t_attr *t_arg)
{
	if (chr <= (MB_CUR_MAX > 1 ? 127 : 255))
		*ret_s = chr;
	else if (chr <= 2047)
	{
		*ret_s = ((chr >> 6) + 192);
		*(++ret_s) = ((chr & 63) + 128);
	}
	else if (chr <= 65535)
	{
		*ret_s = ((chr >> 12) + 224);
		*(++ret_s) = (((chr >> 6) & 63) + 128);
		*(++ret_s) = ((chr & 63) + 128);
	}
	else if (chr <= 1114111)
	{
		*ret_s = ((chr >> 18) + 240);
		*(++ret_s) = (((chr >> 12) & 63) + 128);
		*(++ret_s) = (((chr >> 6) & 63) + 128);
		*(++ret_s) = ((chr & 63) + 128);
	}
	if (chr > 128 && chr <= 255 && MB_CUR_MAX <= 1)
		t_arg->wchar_error = 2;
	if (chr >= 256 && MB_CUR_MAX <= 1)
		t_arg->wchar_error = 1;
	*(++ret_s) = '\0';
}

char	*make_uni_string(va_list *arg, t_attr *t_arg, char *ret_s)
{
	wchar_t *wstring;
	char	*uni_s;

	MALCHK((uni_s = ft_strnew(1)));
	MALCHK((wstring = va_arg(*arg, wchar_t*)));
	while (*wstring)
	{
		make_wchar(*wstring, ret_s, t_arg);
		if (t_arg->prec >= 0 &&
			(int)(ft_strlen(ret_s) + ft_strlen(uni_s)) > t_arg->prec)
			break ;
		uni_s = free_n_join(uni_s, ret_s, 1);
		wstring++;
	}
	free(ret_s);
	return (uni_s);
}

char	*make_uni(va_list *arg, t_attr *t_arg, char *ret_s)
{
	wchar_t character;

	if (t_arg->sp == 'C' || t_arg->sp == 'c')
	{
		character = va_arg(*arg, wint_t);
		make_wchar(character, ret_s, t_arg);
		return (ret_s);
	}
	return (make_uni_string(arg, t_arg, ret_s));
}
