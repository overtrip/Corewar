/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:24 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:36 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op(t_process *process, int type[4], int arg[4])
{
	if (sgt_corewar()->option.verbose.op == false)
		return ;
	func_verbose_tab(process->op.op_code - 1)(process, type, arg);
}
