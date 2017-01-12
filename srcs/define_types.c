/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:29:44 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/27 16:31:10 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** verify a char is in LABEL_CHARS
*/

static int	is_label_chars(char c)
{
	int		i;
	char	*str;

	i = -1;
	str = LABEL_CHARS;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

/*
** Define type of arg
*/

char		define_type(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	if (ft_strchr(str, '%'))
		return (T_DIR);
	else if (str[0] == 'r' && ft_atoi(str++) <= REG_NUMBER)
		return (T_REG);
	while (str[++i] && ft_isdigit(str[i]))
		if (!str[i + 1])
			return (T_IND);
	i = -1;
	while (str[++i] && is_label_chars(str[i]))
		if (!str[i + 1])
			return (T_LAB);
	return (0);
}
