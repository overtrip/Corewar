/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:47 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_strjoin(t_printf *t, char *s1, char *s2, unsigned int len)
{
	ft_memcpy(s1 + t->len, s2, len);
	t->len += len;
	ft_strdel(&s2);
}

static void		s_new_buffer(t_printf *t, char *s, unsigned int len)
{
	char	*tmp;

	tmp = NULL;
	if (s == NULL)
		return ;
	t->buffer_size = t->len + len + BUFF_SIZE + 1;
	if ((tmp = (char *)malloc((t->buffer_size) * sizeof(char))) == NULL)
		return ((void)ft_strdel(&s));
	ft_memcpy(tmp, t->buffer, t->len);
	ft_memcpy(tmp + t->len, s, len);
	ft_strdel(&t->buffer);
	t->buffer = tmp;
	t->len += len;
	ft_strdel(&s);
}

void			printf_add_string(t_printf *t, char *s, unsigned int len)
{
	if (s == NULL || *s == '\0')
		return (ft_strdel(&s));
	if ((t->len + len) > t->buffer_size)
		return (s_new_buffer(t, s, len));
	if (t->buffer != NULL)
		s_strjoin(t, t->buffer, s, len);
}
