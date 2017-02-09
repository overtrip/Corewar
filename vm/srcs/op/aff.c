/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:12 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:10 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (sgt_corewar()->option.verbose.aff == true)
		ft_putchar(process->reg[arg[0] - 1] % 256);
}
