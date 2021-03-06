/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:41 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_add(t_process *process, int type[4], int arg[4])
{
	(void)type;
	ft_printf("P %4lu | %s r%i r%i r%i\n",
			process->uid, process->op.name,
			arg[0], arg[1], arg[2]);
}
