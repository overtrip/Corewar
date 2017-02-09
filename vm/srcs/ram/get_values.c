/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:00 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:18:17 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_reg_value(size_t index)
{
	return ((unsigned int)(sgt_corewar()->ram[index % MEM_SIZE].data));
}

int		get_ind_value(size_t index)
{
	int		ret;

	ret = 0;
	ret |= sgt_corewar()->ram[(index + 0) % MEM_SIZE].data;
	ret = ret << 0x8;
	ret |= sgt_corewar()->ram[(index + 1) % MEM_SIZE].data;
	return ((short)ret);
}

int		get_dir_value(size_t index)
{
	int		ret;

	ret = 0;
	ret |= sgt_corewar()->ram[(index + 0) % MEM_SIZE].data;
	ret = ret << 0x8;
	ret |= sgt_corewar()->ram[(index + 1) % MEM_SIZE].data;
	ret = ret << 0x8;
	ret |= sgt_corewar()->ram[(index + 2) % MEM_SIZE].data;
	ret = ret << 0x8;
	ret |= sgt_corewar()->ram[(index + 3) % MEM_SIZE].data;
	return (ret);
}

int		get_value_from_type(size_t index, int type, int has_idx)
{
	if (type == T_REG)
		return (get_reg_value(index));
	if (type == T_IND)
		return (get_ind_value(index));
	if (type == T_DIR && has_idx == 1)
		return (get_ind_value(index));
	if (type == T_DIR)
		return (get_dir_value(index));
	return (0);
}
