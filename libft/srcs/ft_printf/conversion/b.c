/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:36 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_big_b(t_printf *t)
{
	t->flags.base = 2;
	t->flags.spec = 'b';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	printf_number(t);
}

void	printf_conversion_b(t_printf *t)
{
	t->flags.base = 2;
	t->flags.spec = 'b';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	else if (t->flags.is_char)
		t->flags.number.longlong = (unsigned char)VA_ARG(t->args, int);
	else
		t->flags.number.longlong = VA_ARG(t->args, unsigned int);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	printf_number(t);
}
