/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_verbose_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:18:31 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:11 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_ini_func_tab(t_func_op *t)
{
	t[0] = &verbose_op_live;
	t[1] = &verbose_op_ld;
	t[2] = &verbose_op_st;
	t[3] = &verbose_op_add;
	t[4] = &verbose_op_sub;
	t[5] = &verbose_op_and;
	t[6] = &verbose_op_or;
	t[7] = &verbose_op_xor;
	t[8] = &verbose_op_zjmp;
	t[9] = &verbose_op_ldi;
	t[10] = &verbose_op_sti;
	t[11] = &verbose_op_fork;
	t[12] = &verbose_op_lld;
	t[13] = &verbose_op_lldi;
	t[14] = &verbose_op_lfork;
	t[15] = &verbose_op_aff;
	t[16] = NULL;
}

t_func_op		func_verbose_tab(int index)
{
	static t_func_op	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_func_op *)malloc(sizeof(t_func_op) * 17)) == NULL)
		{
			ERR("malloc: error.");
			exit(EXIT_FAILURE);
		}
		s_ini_func_tab(t);
	}
	if (index >= 0 && index <= 15)
		return (t[index]);
	return (t[16]);
}
