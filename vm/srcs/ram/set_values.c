/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:08 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:18:23 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_1byte_value(t_process *process, int index, unsigned char value)
{
	index = (index < 0) ? MEM_SIZE + index : index;
	sgt_corewar()->ram[index % MEM_SIZE].data = value;
	sgt_corewar()->ram[index % MEM_SIZE].color_id = process->color_id;
	sgt_corewar()->ram[index % MEM_SIZE].modified_cycle =
		sgt_corewar()->cycle;
	sgt_corewar()->ram[index % MEM_SIZE].live = false;
}

void	set_2byte_value(t_process *process, int index, unsigned short value)
{
	set_1byte_value(process, index + 0, value >> 0x08);
	set_1byte_value(process, index + 1, value >> 0x00);
}

void	set_4byte_value(t_process *process, int index, unsigned int value)
{
	set_1byte_value(process, index + 0, value >> 0x18);
	set_1byte_value(process, index + 1, value >> 0x10);
	set_1byte_value(process, index + 2, value >> 0x08);
	set_1byte_value(process, index + 3, value >> 0x00);
}
