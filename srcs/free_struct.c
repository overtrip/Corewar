/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:37:36 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/26 15:09:19 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	delete_instruction(t_head *head)
{
	t_lst	*elem;
	t_lst	*save;
	int		i;
	int		size;
	extern t_op g_op_tab[SIZE];

	if (!head)
		return ;
	elem = head->first;
	while (elem)
	{
		save = elem;
		elem = elem->next;
		i = -1;
		size = g_op_tab[DATA->op_code - 1].nb_arg;
		while (++i < size)
			free(DATA->arg_value[i]);
		if (DATA->arg_value)
			free(DATA->arg_value);
		if (DATA->arg_type)
			free(DATA->arg_type);
		free(save->data);
		free(save);
	}
}
