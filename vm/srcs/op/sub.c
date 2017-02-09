/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:14 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:53 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_process *process, int type[4], int arg[4])
{
	(void)type;
	process->reg[arg[2] - 1] = process->reg[arg[0] - 1] -
		process->reg[arg[1] - 1];
	process->carry = (process->reg[arg[2] - 1] == 0);
}
