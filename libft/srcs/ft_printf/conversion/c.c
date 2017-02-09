/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:49 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_big_c(t_printf *t)
{
	printf_wchar(t, VA_ARG(t->args, wchar_t));
}

void	printf_conversion_c(t_printf *t)
{
	if (t->flags.is_long)
		return ((void)printf_conversion_big_c(t));
	printf_char(t, (unsigned char)VA_ARG(t->args, int));
}
