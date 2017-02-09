/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:51 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:34 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_process *process, int type[4], int arg[4])
{
	if (type[0] == T_DIR)
		process->reg[arg[1] - 1] = get_dir_value(process->pc +
				(arg[0]));
	else
		process->reg[arg[1] - 1] = get_ind_value(process->pc +
				(arg[0]));
	process->carry = (process->reg[arg[1] - 1] == 0);
}
