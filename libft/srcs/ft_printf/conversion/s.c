/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:49:32 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion_big_s(t_printf *t)
{
	wchar_t		*sw;

	sw = VA_ARG(t->args, wchar_t *);
	if (sw == NULL && t->flags.alt == true)
		printf_string(t, ft_strdup(""));
	else if (sw == NULL)
		printf_string(t, ft_strdup("(null)"));
	else
		printf_string(t, printf_wstr_to_str(t, sw));
}

void	printf_conversion_s(t_printf *t)
{
	char	*s;

	if (t->flags.is_long && !t->flags.is_long_double)
		return (printf_conversion_big_s(t));
	s = VA_ARG(t->args, char *);
	if (s == NULL && t->flags.alt == true)
		printf_string(t, ft_strdup(""));
	else if (s == NULL)
		printf_string(t, ft_strdup("(null)"));
	else
		printf_string(t, ft_strdup(s));
}
