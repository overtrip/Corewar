/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:50:30 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/12 18:08:19 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Complete field of op_code instruction
*/

void	define_function(t_lst **elem, int index)
{
	extern t_op	g_op_tab[17];

	((t_instruct *)(*elem)->data)->op_code = g_op_tab[index].id;
}

/*
**	Create and completed a new elem of instruction
*/

void		create_instruction(t_head *head, int index)
{
	t_lst	*new;
	t_instruct	*tmp;
	extern t_op	g_op_tab[17];

	tmp = NULL;
	if (!(tmp = (t_instruct *)malloc(sizeof(t_instruct))))
		return ;
	if (!(tmp->arg_type = (int *)malloc(sizeof(int) * g_op_tab[index].id)))
		return ;
	if (!(tmp->arg_value = (int *)malloc(sizeof(int) * g_op_tab[index].id)))
		return ;
	new = ft_lst_create_no_malloc(tmp);
	define_function(&new, index);
	ft_lst_push_back(&head, new);
}
