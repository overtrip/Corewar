/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		s_replace(t_replace_color co)
{
	printf_color_fg_bg(co);
	printf_color_basic(co);
	printf_color_format(co);
}

void			printf_replace_color(t_printf *t, char *s, int len)
{
	int		i;
	int		tmp_len;
	int		save;
	char	*tmp;

	i = 0;
	tmp_len = 0;
	save = 0;
	tmp = NULL;
	while (i < len)
	{
		s_replace((t_replace_color){t, &tmp, &tmp_len, &i, &save});
		++i;
	}
	tmp = printf_concat(tmp, &tmp_len, s + save, i - save);
	ft_strdel(&t->buffer);
	t->buffer = tmp;
	t->len = tmp_len;
}
