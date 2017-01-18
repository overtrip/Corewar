/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:29:44 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/18 17:23:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Check if char is a label_char
*/

static int is_t_lab(char *str)
{
	char	*tmp;
	char	*current;

	tmp = LABEL_CHARS;
	current = str;
	if (!*str)
		return (0);
	while (*current)
	{
		if (!ft_strchr(tmp, *current))
			return (0);
		++current;
	}
	return (1);
}

/*
**	TODO check if the string was a T_REG
*/

static int is_t_reg(char *str)
{
	(void);
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
	if (*str && ft_isnumber(str))
		return (T_IND);
	if (is_t_lab(str))
		return (T_LAB);
	return (0);
}
