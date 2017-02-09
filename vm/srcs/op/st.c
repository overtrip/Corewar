/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:42 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_st(t_process *process, int type[4], int arg[4])
{
	if (type[1] == T_REG)
		process->reg[arg[1] - 1] = process->reg[arg[0] - 1];
	else if (type[1] == T_IND)
		set_4byte_value(process, process->pc + (arg[1] % IDX_MOD),
				process->reg[arg[0] - 1]);
	else
		set_4byte_value(process, process->pc + arg[1],
				process->reg[arg[0] - 1]);
}
