/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:44:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/14 17:18:58 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Create a new elem who containt position in program and name to find
*/

t_order	*create_label(unsigned int *size, char *data, char *find)
{
	t_order	*new;

	new = NULL;
	if (!(new = (t_order *)malloc(sizeof(t_order))))
		return (NULL);
	new->pos = *size;
	new->label = ft_strndup(data, find - data);
	return (new);
	new->next = NULL;
}

/*
**	Push back the new elem
*/

void	push_label(t_order *pos, t_order *new)
{
	t_order	*tmp;

	tmp = pos;
	if (!pos)
		pos = new;
	while (tmp)
		tmp = tmp->next;
	tmp->next = new;
}

/*
**	Find if line is a label or instruction
*/

void	find_pos_label(char *data, unsigned int *size, t_order *pos)
{
	char	*find;
	char	*tmp;
	int		i;
	t_order	*new;

	i = 0;
	tmp = data;
	if ((find = ft_strchr(data, ':')))
	{
		while (tmp != find)
		{
			if (!ft_strchr(LABEL_CHARS, *tmp))
				break ;
			++tmp;
		}
		if (!(++tmp))
		{
			ft_putendl("ici");
			new = create_label(size, data, find);
			push_label(pos, new);
		}
		else
			return ;
	}
}
