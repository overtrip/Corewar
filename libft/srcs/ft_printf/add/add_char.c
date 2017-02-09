/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:38 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_new_buffer(t_printf *t, unsigned char c)
{
	char	*tmp;

	t->buffer_size = t->len + 1 + BUFF_SIZE + 1;
	if ((tmp = (char *)malloc((t->buffer_size) * sizeof(char))) == NULL)
		return ;
	if (t->buffer)
	{
		ft_memcpy(tmp, t->buffer, t->len);
		tmp[t->len] = c;
		++t->len;
	}
	else
	{
		tmp[0] = c;
		++t->len;
	}
	ft_strdel(&t->buffer);
	t->buffer = tmp;
}

void			printf_add_char(t_printf *t, unsigned char c)
{
	if ((t->len + 1) > t->buffer_size)
		return (s_new_buffer(t, c));
	if (t->buffer)
	{
		t->buffer[t->len] = c;
		++t->len;
	}
	else
	{
		s_new_buffer(t, c);
	}
}
