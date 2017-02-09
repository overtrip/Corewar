/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:38 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:25 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ldi(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	val[0] = (type[0] == T_REG) ? process->reg[arg[0] - 1] : arg[0];
	val[1] = (type[1] == T_REG) ? process->reg[arg[1] - 1] : arg[1];
	process->reg[arg[2] - 1] = get_dir_value(process->pc +
			((val[0] + val[1]) % IDX_MOD));
}
