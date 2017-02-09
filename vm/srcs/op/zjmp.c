/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:23 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:59 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (process->carry == 1)
		process->pc = (process->pc + (arg[0] % IDX_MOD) - 3) % MEM_SIZE;
}
