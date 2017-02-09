/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:57 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_add_wchar(t_printf *t, wchar_t c)
{
	if (c <= 0x7F)
	{
		printf_add_char(t, c);
	}
	else if (c <= 0x7FF)
	{
		printf_add_char(t, (c >> 6) + 0xC0);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		printf_add_char(t, (c >> 12) + 0xE0);
		printf_add_char(t, ((c >> 6) & 0x3F) + 0x80);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		printf_add_char(t, (c >> 18) + 0xF0);
		printf_add_char(t, ((c >> 12) & 0x3F) + 0x80);
		printf_add_char(t, ((c >> 6) & 0x3F) + 0x80);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
}
