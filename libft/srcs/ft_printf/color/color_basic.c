/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:49:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_replace4(t_replace_color co)
{
	int		j;
	char	c[3];
	char	**spl_replace;

	spl_replace = ft_strsplit(LIST_COLOR4, ';');
	ft_bzero(c, 3);
	c[0] = '9';
	j = 0;
	while (spl_replace[j])
	{
		if (ft_strnstr(co.t->buffer + *(co.i),
					spl_replace[j], ft_strlen(spl_replace[j])))
		{
			c[1] = '4' + j;
			*(co.tmp) = printf_concat(*(co.tmp), (co.len),
					co.t->buffer + *(co.save), *(co.i) - *(co.save));
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "\033[", 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), c, 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "m", 1);
			*(co.save) = *(co.i) + ft_strlen(spl_replace[j]);
		}
		*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
		++j;
	}
	ft_strtable_clear(&spl_replace);
}

static void		s_replace3(t_replace_color co)
{
	int		j;
	char	c[3];
	char	**spl_replace;

	spl_replace = ft_strsplit(LIST_COLOR3, ';');
	ft_bzero(c, 3);
	c[0] = '9';
	j = 0;
	while (spl_replace[j])
	{
		if (ft_strnstr(co.t->buffer + *(co.i),
					spl_replace[j], ft_strlen(spl_replace[j])))
		{
			c[1] = '0' + j;
			*(co.tmp) = printf_concat(*(co.tmp), (co.len),
					co.t->buffer + *(co.save), *(co.i) - *(co.save));
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "\033[", 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), c, 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "m", 1);
			*(co.save) = *(co.i) + ft_strlen(spl_replace[j]);
		}
		*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
		++j;
	}
	ft_strtable_clear(&spl_replace);
}

static void		s_replace2(t_replace_color co)
{
	int		j;
	char	c[3];
	char	**spl_replace;

	spl_replace = ft_strsplit(LIST_COLOR2, ';');
	ft_bzero(c, 3);
	c[0] = '3';
	j = 0;
	while (spl_replace[j])
	{
		if (ft_strnstr(co.t->buffer + *(co.i),
					spl_replace[j], ft_strlen(spl_replace[j])))
		{
			c[1] = '6' + j;
			*(co.tmp) = printf_concat(*(co.tmp), (co.len),
					co.t->buffer + *(co.save), *(co.i) - *(co.save));
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "\033[", 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), c, 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "m", 1);
			*(co.save) = *(co.i) + ft_strlen(spl_replace[j]);
		}
		*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
		++j;
	}
	ft_strtable_clear(&spl_replace);
}

static void		s_replace1(t_replace_color co)
{
	int		j;
	char	c[3];
	char	**spl_replace;

	spl_replace = ft_strsplit(LIST_COLOR1, ';');
	ft_bzero(c, 3);
	c[0] = '3';
	j = 0;
	while (spl_replace[j])
	{
		if (ft_strnstr(co.t->buffer + *(co.i),
					spl_replace[j], ft_strlen(spl_replace[j])))
		{
			c[1] = '0' + j;
			*(co.tmp) = printf_concat(*(co.tmp), (co.len),
					co.t->buffer + *(co.save), *(co.i) - *(co.save));
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "\033[", 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), c, 2);
			*(co.tmp) = printf_concat(*(co.tmp), (co.len), "m", 1);
			*(co.save) = *(co.i) + ft_strlen(spl_replace[j]);
		}
		*(co.i) = (*(co.save) > *(co.i)) ? *(co.save) - 1 : *(co.i);
		++j;
	}
	ft_strtable_clear(&spl_replace);
}

void			printf_color_basic(t_replace_color co)
{
	s_replace1(co);
	s_replace2(co);
	s_replace3(co);
	s_replace4(co);
}
