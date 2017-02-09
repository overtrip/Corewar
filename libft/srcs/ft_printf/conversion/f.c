/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_big_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'F';
	t->flags.number.longdouble = VA_ARG(t->args, double);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	printf_number(t);
}

void	printf_conversion_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'f';
	if (t->flags.is_long)
		return ((void)printf_conversion_big_f(t));
	else
		t->flags.number.longdouble = VA_ARG(t->args, double);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	printf_number(t);
}
