/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:47:33 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		s_trunc(char **s, int length)
{
	int		index;
	int		size;
	char	*string;

	size = (length < 0) ? -length : length;
	string = (char *)malloc((size + 1) * sizeof(char));
	if (*s == NULL || string == NULL)
		return (0);
	index = 0;
	while ((*s)[index] && index < size)
	{
		string[index] = (*s)[index];
		++index;
	}
	string[index] = '\0';
	ft_strdel(s);
	*s = string;
	return (index);
}

void					printf_string(t_printf *t, char *s)
{
	size_t	len;

	if (t->flags.prec != -1)
		len = s_trunc(&s, t->flags.prec);
	else
		len = ft_strlen(s);
	if ((t->flags.width -= len) < 0)
		return (printf_add_string(t, s, len));
	if (t->flags.left == false)
		printf_fill_character(t, t->flags.pad);
	printf_add_string(t, s, len);
	if (t->flags.left)
		printf_fill_character(t, t->flags.pad);
}

void					printf_char(t_printf *t, char c)
{
	if ((t->flags.width -= 1) < 0)
		return (printf_add_char(t, c));
	if (t->flags.left == false)
		printf_fill_character(t, t->flags.pad);
	printf_add_char(t, c);
	if (t->flags.left)
		printf_fill_character(t, t->flags.pad);
}

void					printf_wchar(t_printf *t, wchar_t c)
{
	if ((t->flags.width -= 1) < 0)
		return (printf_add_wchar(t, c));
	if (t->flags.left == false)
		printf_fill_character(t, t->flags.pad);
	printf_add_wchar(t, c);
	if (t->flags.left)
		printf_fill_character(t, t->flags.pad);
}
