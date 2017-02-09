/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:59 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:08 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_ld(t_process *process, int type[4], int arg[4])
{
	int		val;

	if (type[0] == T_IND)
		val = arg[0] % IDX_MOD;
	else
		val = arg[0];
	ft_printf("P %4lu | %s %i r%i\n",
			process->uid, process->op.name,
			val, arg[1]);
}
