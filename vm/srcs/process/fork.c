/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:50 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:18:37 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_fork_reg(t_process *new, t_process *process)
{
	size_t	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = process->reg[i];
		++i;
	}
}

t_process		*process_fork(t_process *process, size_t index)
{
	t_process	*new;

	if ((new = process_creat(index, process->id, process->color_id)) == NULL)
		return (NULL);
	s_fork_reg(new, process);
	new->live = process->live;
	new->carry = process->carry;
	new->op = op_tab(16);
	new->op_cycle = process->op_cycle;
	new->in_action = false;
	return (new);
}
