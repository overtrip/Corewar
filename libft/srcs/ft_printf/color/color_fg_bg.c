/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fg_bg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:03 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_valid_option(char *s)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[i]))
		++i;
	if (s[i] == '}')
		return (i);
	return (0);
}

void		printf_color_fg_bg(t_replace_color co)
{
	int		j;

	if (ft_strnstr(co.t->buffer + *(co.i), "{fg=", 4)
		&& (j = s_valid_option(co.t->buffer + *(co.i) + 4)))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len, co.t->buffer + *(co.save),
				*(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[38;5;", 7);
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.i) + 4, j);
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "m", 1);
		*(co.save) = *(co.i) + j + 5;
	}
	else if (ft_strnstr(co.t->buffer + *(co.i), "{bg=", 4)
		&& (j = s_valid_option(co.t->buffer + *(co.i) + 4)))
	{
		*(co.tmp) = printf_concat(*(co.tmp), co.len, co.t->buffer + *(co.save),
				*(co.i) - *(co.save));
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "\033[48;5;", 7);
		*(co.tmp) = printf_concat(*(co.tmp), co.len,
				co.t->buffer + *(co.i) + 4, j);
		*(co.tmp) = printf_concat(*(co.tmp), co.len, "m", 1);
		*(co.save) = *(co.i) + j + 5;
	}
	*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
}
