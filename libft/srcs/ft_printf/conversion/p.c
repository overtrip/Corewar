/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:49:25 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_p(t_printf *t)
{
	const void	*ptr;

	ptr = VA_ARG(t->args, void *);
	if (t->flags.prec == 0 && ptr == NULL)
	{
		t->flags.prec = -1;
		t->flags.pad = ' ';
		printf_string(t, ft_strdup("0x"));
		return ;
	}
	t->flags.base = 16;
	t->flags.number.word = (unsigned long int)ptr;
	t->flags.is_negative = false;
	t->flags.alt = true;
	t->flags.spec = 'x';
	printf_number(t);
}
