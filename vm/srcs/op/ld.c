/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:34 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:22 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_process *process, int type[4], int arg[4])
{
	if (type[0] == T_IND)
		process->reg[arg[1] - 1] = arg[0] % IDX_MOD;
	else
		process->reg[arg[1] - 1] = arg[0];
	process->carry = (process->reg[arg[1] - 1] == 0);
}
