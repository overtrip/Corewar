/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:37:36 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/20 17:14:02 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	delete_instruction(t_head *head)
{
	t_lst	*elem;
	t_lst	*save;
	int		i;
	extern t_op g_op_tab[SIZE];

	if (!head)
		return ;
	elem = head->first;
	while (elem)
	{
		save = elem;
		elem = elem->next;
		i = -1;
		while (++i < g_op_tab[SIZE].nb_arg)
		if (((t_instruct *)(*elem).data)->arg_value[i])
			free(((t_instruct *)(*elem).data)->arg_value[i]);
		if (((t_instruct *)(*elem).data)->arg_value)
			free(((t_instruct *)(*elem).data)->arg_value);
		if (((t_instruct *)(*elem).data)->arg_type)
			free(((t_instruct *)(*elem).data)->arg_type);
		free(save);
	}
}
