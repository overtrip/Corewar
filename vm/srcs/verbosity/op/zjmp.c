/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:16:53 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:43 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_zjmp(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (process->carry == 1)
	{
		ft_printf("P %4lu | %s %i OK\n",
				process->uid, process->op.name, arg[0]);
	}
	else
	{
		ft_printf("P %4lu | %s %i FAILED\n",
				process->uid, process->op.name, arg[0]);
	}
}
