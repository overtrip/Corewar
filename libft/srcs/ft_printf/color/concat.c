/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:45:45 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:16 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_concat2(char *s1, int len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	ft_strdel(&s1);
	return (tmp);
}

char	*printf_concat(char *s1, int *len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(*len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, *len1);
	ft_memcpy(tmp + *len1, s2, len2);
	ft_strdel(&s1);
	*len1 += len2;
	return (tmp);
}
