/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:46:16 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:46:46 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_check_action(t_printf *t, char **s)
{
	char	sc[2];

	++(*s);
	while ((printf_flags(t, s) || printf_modifiers(t, s)))
		++(*s);
	if (**s)
	{
		if (printf_function_conversion(t, **s) == false)
		{
			sc[0] = **s;
			sc[1] = '\0';
			t->flags.prec = -1;
			printf_string(t, ft_strdup(sc));
		}
	}
	else
	{
		--(*s);
	}
}

void			printf_format(t_printf *t, char *s)
{
	while (*s)
	{
		printf_ini_flags(t);
		if (*s == '%')
		{
			s_check_action(t, &s);
			++s;
		}
		else
		{
			if (*s == '{')
				t->search_color = true;
			printf_add_char(t, *s);
			++s;
		}
	}
}
