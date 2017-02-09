/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:25 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>

static t_bool	s_modifiers_1(t_printf *t, char **s)
{
	if ((*s)[0] == 'h' && (*s)[1] == 'h')
	{
		++s;
		t->flags.is_short = false;
		t->flags.is_char = true;
		return (true);
	}
	if (**s == 'h')
	{
		t->flags.is_short = true;
		return (true);
	}
	if ((*s)[0] == 'l' && (*s)[1] == 'l')
	{
		++(*s);
		t->flags.is_long_double = true;
		t->flags.is_long = true;
		return (true);
	}
	if (**s == 'l')
	{
		t->flags.is_long = true;
		return (true);
	}
	return (false);
}

static t_bool	s_modifiers_2(t_printf *t, char **s)
{
	if (**s == 'z')
	{
		t->flags.is_long_double =
			sizeof(size_t) > sizeof(unsigned long int);
		t->flags.is_long =
			sizeof(size_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'j')
	{
		t->flags.is_long_double =
			sizeof(intmax_t) > sizeof(unsigned long int);
		t->flags.is_long =
			sizeof(intmax_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'L' || **s == 'q')
	{
		t->flags.is_long_double = true;
		t->flags.is_long = true;
		return (true);
	}
	return (false);
}

t_bool			printf_modifiers(t_printf *t, char **s)
{
	if (s_modifiers_1(t, s))
		return (true);
	if (s_modifiers_2(t, s))
		return (true);
	return (false);
}
