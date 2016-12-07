/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:44:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/07 15:46:32 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Create a new elem who containt position in program and name to find
*/

t_lst		*create_label(unsigned int *size, char *data)
{
	t_order	*new;
	t_lst	*ret;

	new = NULL;
	ret = NULL;
	if (!(new = (t_order *)malloc(sizeof(t_order))))
		return (NULL);
	new->pos = *size;
	new->label = data;
	if (!(ret = ft_lst_create_no_malloc(new)))
	{
		free(new->label);
		free(new);
		free(data);
		return (NULL);
	}
	return (ret);
}

/*
**	Check if the string finding is a real label or other
*/

static char	*check_is_real(char **str)
{
	char	*tmp;
	char	*find;

	tmp = *str;
	find = ft_strchr(*str, LABEL_CHAR);
	while (tmp != find)
	{
		if (!ft_isalnum(*tmp) && *tmp != '_')
			return (NULL);
		++tmp;
	}
	return (*str);
}

/*
**	Find if line is a label or instruction
*/

void		find_pos_label(void **cast, unsigned int *size, t_head *label_pos)
{
	t_lst	*new;
	char	*label;
	char	**data;

	label = NULL;
	data = (char **)cast;
	if (check_is_real(data))
	{
		label = ft_strsep(data, ":");
		if (!(new = create_label(size, label)))
		{
			printf("[%s]\n", label);
			ft_lst_push_back(&label_pos, new);
		}
		printf("[%d]\n", ((t_order *)new->data)->pos);
		if (label)
			free(label);
	}
}
