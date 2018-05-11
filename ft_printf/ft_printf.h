/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:10:30 by dpozinen          #+#    #+#             */
/*   Updated: 2018/03/15 12:57:18 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>
# include "handlers.h"
# include <stdarg.h>
# include "../libft.h"
# include <stdint.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);

#endif
