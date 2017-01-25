/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strsep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:55:43 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/25 17:42:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	compare the current char with reference separator char
*/

static int	ft_compare(char c, const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp)
	{
		if (*tmp == c)
			return (1);
		++tmp;
	}
	return (0);
}

/*
**	Return ocurence finding, replace the separator char by a '\0'
*/

char		*parse_strsep(char **str, const char *delim)
{
	char	*token;
	char	*begin;
	char	*ret;
	char	*tmp;

	token = *str;
	begin = token;
	if (!*str || !**str)
		return (NULL);
	while (*token && !ft_compare(*token, delim))
		++token;
	*str = token;
	if (!*token)
	{
		ret = ft_strdup(begin);
		return (ret);
	}
	tmp = ft_strdup(*str + 1);
	ret = ft_strsub(begin, 0, (*str - begin));
//	ft_strdel(&begin);
	*str = tmp;
	return (ret);
}
