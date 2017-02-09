/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:48:08 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	s_flags_1(t_printf *t, char **s)
{
	if (**s == ' ')
	{
		t->flags.space = true;
		return (true);
	}
	if (**s == '+')
	{
		t->flags.showsign = true;
		return (true);
	}
	if (**s == '-')
	{
		t->flags.pad = ' ';
		t->flags.left = true;
		return (true);
	}
	if (**s == '#')
	{
		t->flags.alt = true;
		return (true);
	}
	return (false);
}

static t_bool	s_flags_2(t_printf *t, char **s)
{
	if (**s == '*')
	{
		t->flags.width = VA_ARG(t->args, int);
		if (t->flags.width < 0)
		{
			t->flags.width = -t->flags.width;
			t->flags.pad = ' ';
			t->flags.left = true;
		}
		++(*s);
		if (ft_isdigit(**s))
		{
			t->flags.width = ft_atoi(*s);
			while (ft_isdigit(**s))
				++(*s);
		}
		--(*s);
		return (true);
	}
	return (false);
}

static t_bool	s_flags_3(t_printf *t, char **s)
{
	if (**s == '.')
	{
		++(*s);
		if (**s == '*')
		{
			t->flags.prec = VA_ARG(t->args, int);
			if (t->flags.prec < 0)
				t->flags.prec = -1;
			return (true);
		}
		if (ft_isdigit(**s))
		{
			t->flags.prec = ft_atoi(*s);
			while (ft_isdigit(**s))
				++(*s);
			--(*s);
		}
		else
		{
			t->flags.prec = 0;
			--(*s);
		}
		return (true);
	}
	return (false);
}

static t_bool	s_flags_4(t_printf *t, char **s)
{
	if (**s == '0')
	{
		if (t->flags.left == false)
			t->flags.pad = '0';
		return (true);
	}
	if (ft_isdigit(**s))
	{
		t->flags.width = ft_atoi(*s);
		while (ft_isdigit(**s))
			++(*s);
		--(*s);
		return (true);
	}
	return (false);
}

t_bool			printf_flags(t_printf *t, char **s)
{
	if (s_flags_1(t, s))
		return (true);
	if (s_flags_2(t, s))
		return (true);
	if (s_flags_3(t, s))
		return (true);
	if (s_flags_4(t, s))
		return (true);
	return (false);
}
