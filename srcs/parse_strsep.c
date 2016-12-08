/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strsep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:55:43 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/08 17:48:44 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

	token = *str;
	begin = token;
	if (!**str)
		return (NULL);
	while (*token && !ft_compare(*token, delim))
		++token;
	*str = token;
	if (!*token)
	{
		ret = ft_strdup(begin);
		free(begin);
		return (ret);
	}
	**str = '\0';
	++(*str);
	ret = ft_strdup(begin);
	free(begin);
	return (ret);
}
