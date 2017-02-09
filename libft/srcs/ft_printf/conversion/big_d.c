/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:42 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_big_d(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 10;
	signed_number = VA_ARG(t->args, long int);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
		t->flags.number.longlong = signed_number * -1;
	else
		t->flags.number.longlong = signed_number;
	printf_number(t);
}
