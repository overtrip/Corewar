/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:37:36 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:53:15 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	delete_instruction(t_head *head)
{
	t_lists		*elem;
	t_lists		*save;
	int			i;
	int			size;
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
