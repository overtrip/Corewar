/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:47:58 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_ini(t_printf *t)
{
	t->buffer = NULL;
	t->work_buffer = NULL;
	t->buffer_size = 0;
	t->len = 0;
	t->search_color = false;
}

void	printf_ini_flags(t_printf *t)
{
	t->work_buffer = NULL;
	t->flags.is_negative = false;
	t->flags.number.longlong = 0;
	t->flags.base = 10;
	t->flags.alt = false;
	t->flags.space = false;
	t->flags.left = false;
	t->flags.showsign = false;
	t->flags.group = false;
	t->flags.is_long_double = false;
	t->flags.is_short = false;
	t->flags.is_long = false;
	t->flags.is_char = false;
	t->flags.width = 0;
	t->flags.prec = -1;
	t->flags.pad = ' ';
	t->flags.spec = '\0';
}
