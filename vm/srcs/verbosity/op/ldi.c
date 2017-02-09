/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:16:06 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:12 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_ldi(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[0] == T_REG)
		val[0] = process->reg[arg[0] - 1];
	else
		val[0] = arg[0];
	if (type[1] == T_REG)
		val[1] = process->reg[arg[1] - 1];
	else
		val[1] = arg[0];
	ft_printf("P %4lu | %s %i %i r%i\n"
			"       | -> load from %i + %i = %i (with pc and mod %li)\n",
			process->uid, process->op.name,
			val[0], val[1], arg[2],
			val[0], val[1], val[0] + val[1],
			process->pc + (val[0] + val[1]) % IDX_MOD);
}
