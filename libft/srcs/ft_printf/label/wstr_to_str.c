/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:47:26 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	s_strwlen(const wchar_t *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			len += 1;
		else if (s[i] <= 0x7FF)
			len += 2;
		else if (s[i] <= 0xFFFF)
			len += 3;
		else if (s[i] <= 0x10FFFF)
			len += 4;
		++i;
	}
	return (len);
}

static size_t	s_wlen(const wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

static size_t	s_add_wchar_in_str(char **s, wchar_t wc, size_t j)
{
	if (wc <= 0x7F)
	{
		(*s)[j++] = wc;
	}
	else if (wc <= 0x7FF)
	{
		(*s)[j++] = (wc >> 6) + 0xC0;
		(*s)[j++] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		(*s)[j++] = (wc >> 12) + 0xE0;
		(*s)[j++] = ((wc >> 6) & 0x3F) + 0x80;
		(*s)[j++] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0x10FFFF)
	{
		(*s)[j++] = (wc >> 18) + 0xF0;
		(*s)[j++] = ((wc >> 12) & 0x3F) + 0x80;
		(*s)[j++] = ((wc >> 6) & 0x3F) + 0x80;
		(*s)[j++] = (wc & 0x3F) + 0x80;
	}
	return (j);
}

char			*printf_wstr_to_str(t_printf *t, wchar_t *s)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if ((tmp = (char *)malloc((s_strwlen(s) + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i] != '\0')
	{
		if (j + s_wlen(s[i]) > (unsigned long)t->flags.prec)
		{
			t->flags.prec = -1;
			tmp[j] = '\0';
			return (tmp);
		}
		j = s_add_wchar_in_str(&tmp, s[i], j);
		++i;
	}
	tmp[j] = '\0';
	return (tmp);
}
