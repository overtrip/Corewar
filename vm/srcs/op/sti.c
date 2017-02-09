/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:10 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:48 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sti(t_process *process, int type[4], int arg[4])
{
	int		val[3];

	val[0] = (type[0] == T_REG) ? process->reg[arg[0] - 1] : arg[0];
	val[1] = (type[1] == T_REG) ? process->reg[arg[1] - 1] : arg[1];
	val[2] = (type[2] == T_REG) ? process->reg[arg[2] - 1] : arg[2];
	set_4byte_value(process,
			process->pc + ((val[1] + val[2]) % IDX_MOD),
			val[0]);
}
