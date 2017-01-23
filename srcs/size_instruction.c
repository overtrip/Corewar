/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:44:38 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/23 17:10:10 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Create a new elem who containt position in program and name to find
*/

static t_lst	*create_label(unsigned int *size, char *data)
{
	t_order	*new;
	t_lst	*ret;
	char	*trim;

	new = NULL;
	trim = NULL;
	if (data && *data)
		trim = ft_strtrim(data);
	if (!(new = (t_order *)malloc(sizeof(t_order))))
		return (NULL);
	new->pos = *size;
	new->label = trim;
	if (!(ret = ft_lst_create_no_malloc(new)))
		return (NULL);
	return (ret);
}

/*
**	Check if the string finding is a real label or other
*/

static char		*check_is_real(char **str)
{
	char	*find;
	char	*trim;
	char	*label;
	char	*stock;

	stock = *str;
	if (!(stock || *stock))
		return (NULL);
	trim = NULL;
	if ((find = ft_strchr(stock, LABEL_CHAR)))
	{
		label = ft_strndup(stock, find - stock);
		trim = ft_strtrim(label);
		free(label);
		if (is_t_lab(trim))
		{
			free(trim);
			return (*str);
		}
	}
	free(trim);
	return (NULL);
}

/*
**	Find if line is a label or instruction
*/

void			find_pos_label(void **cast, unsigned int *size, t_head *pos)
{
	t_lst	*new;
	char	*label;
	char	**data;

	data = (char **)cast;
	label = NULL;
	new = NULL;
	label = *data;
	if (check_is_real(data))
	{
		label = parse_strsep(data, ":");
		if ((new = create_label(size, label)))
			ft_lst_push_back(&pos, new);
		free(label);
	}
	else
		return ;
}
