/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:10 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_replace2(t_replace_color co)
{
	if (ft_strnstr(co.t->buffer + *(co.i), "{blink}", 7))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[5m", 4);
		*(co.save) = *(co.i) + 7;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{reverse}", 9))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[7m", 4);
		*(co.save) = *(co.i) + 9;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{hidden}", 8))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[8m", 4);
		*(co.save) = *(co.i) + 8;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}

static void		s_replace1(t_replace_color co)
{
	if (ft_strnstr(co.t->buffer + *(co.i), "{bold}", 6))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[1m", 4);
		*(co.save) = *(co.i) + 6;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{dim}", 5))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[2m", 4);
		*(co.save) = *(co.i) + 5;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{underline}", 11))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[4m", 4);
		*(co.save) = *(co.i) + 11;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}

void			printf_color_format(t_replace_color co)
{
	s_replace1(co);
	s_replace2(co);
	if (ft_strnstr(co.t->buffer + *(co.i), "{reset}", 7))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.save), *(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[0m", 4);
		*(co.save) = *(co.i) + 7;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}
