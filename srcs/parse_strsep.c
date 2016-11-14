/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strsep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:55:43 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/14 16:57:52 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_compare(char c, const char *str)
{
	const char	*tmp;

	tmp = str;
	while (tmp)
	{
		if (*tmp == c)
			return (1);
		++tmp;
	}
	return (0);
}

char		*ft_strsep(char **str, const char *delim)
{
	char	*token;
	char	*begin;

	token = *str;
	begin = token;
	if (!token)
		return (NULL);
	while (token && !ft_compare(*token, delim))
		++token;
	if (!token)
		*str = token;
	**str = token - *str;
	*(*str) = '\0';
	++*str;
	return (begin);
}
