/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:42 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:29 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_process *process, int type[4], int arg[4])
{
	t_process		*new;
	unsigned short	addr;

	(void)type;
	addr = (process->pc + (arg[0])) % MEM_SIZE;
	if ((new = process_fork(process, addr)) == NULL)
		return ;
	ft_lstd_push_front(&sgt_corewar()->process, new);
}
