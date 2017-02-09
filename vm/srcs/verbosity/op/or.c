/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:16:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:27 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_or(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[0] == T_REG)
		val[0] = process->reg[arg[0] - 1];
	else
		val[0] = arg[0];
	if (type[1] == T_REG)
		val[1] = process->reg[arg[1] - 1];
	else
		val[1] = arg[1];
	ft_printf("P %4lu | %s %i %i r%i\n",
			process->uid, process->op.name,
			val[0], val[1], arg[2]);
}
