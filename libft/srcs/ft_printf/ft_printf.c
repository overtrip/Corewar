/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:46:07 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:46:40 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_va(t_printf *t, char *format)
{
	printf_format(t, format);
	va_end(t->args);
	if (t->search_color)
		printf_replace_color(t, t->buffer, t->len);
}

int				ft_asprintf(char **ret, const char *format, ...)
{
	t_printf	t;

	printf_ini(&t);
	va_start(t.args, format);
	s_va(&t, (char *)format);
	ft_strdel(ret);
	if ((*ret = (char *)malloc((t.len + 1) * sizeof(char))) == NULL)
		return (-1);
	ft_memcpy(*ret, t.buffer, t.len);
	(*ret)[t.len] = '\0';
	ft_strdel(&t.buffer);
	return (t.len);
}

int				ft_sprintf(char *ret, const char *format, ...)
{
	t_printf	t;

	printf_ini(&t);
	va_start(t.args, format);
	s_va(&t, (char *)format);
	ft_memcpy(ret, t.buffer, t.len);
	ret[t.len] = '\0';
	ft_strdel(&t.buffer);
	return (t.len);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_printf	t;

	printf_ini(&t);
	va_start(t.args, format);
	s_va(&t, (char *)format);
	write(fd, t.buffer, t.len);
	ft_strdel(&t.buffer);
	return (t.len);
}

int				ft_printf(const char *format, ...)
{
	t_printf	t;

	printf_ini(&t);
	va_start(t.args, format);
	s_va(&t, (char *)format);
	write(STDOUT_FILENO, t.buffer, t.len);
	ft_strdel(&t.buffer);
	return (t.len);
}
