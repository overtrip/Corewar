/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:49:05 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_i(t_printf *t)
{
	long long int	signed_number;

	if (t->flags.is_long)
		signed_number = VA_ARG(t->args, long int);
	else if (t->flags.is_char)
		signed_number = (signed char)VA_ARG(t->args, unsigned int);
	else if (t->flags.is_short)
		signed_number = (short int)VA_ARG(t->args, unsigned int);
	else
		signed_number = VA_ARG(t->args, int);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
		t->flags.number.longlong = signed_number * -1;
	else
		t->flags.number.longlong = signed_number;
	printf_number(t);
}
