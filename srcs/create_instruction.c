/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:50:30 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/20 15:22:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Complete field of op_code instruction
*/

static void	define_op_code_function(t_lst **elem, int index, char **str)
{
	extern t_op	g_op_tab[17];

	if ((((t_instruct *)(*elem)->data)->op_code = g_op_tab[index].id))
	{
		*str = ft_strtrim(*str);
		free(parse_strsep(str, " "));
	}
}

/*
**	Set all fields in structure at 0
*/

static void	init_field(t_instruct *new, int index)
{
	int	var;

	var = 0;
	new->op_code = 0;
	while (var < index)
	{
		new->arg_type[var] = 0;
		new->arg_value[var] = NULL;
		++var;
	}
}

/*
**	Create and completed a new elem of instruction
*/

void		create_instruction(t_head *head, int index, char **str)
{
	t_lst		*new;
	t_instruct	*tmp;
	extern t_op	g_op_tab[17];

	tmp = NULL;
	if (!(tmp = (t_instruct *)malloc(sizeof(t_instruct))))
		return ;
	if (!(tmp->arg_type = (int *)malloc(sizeof(int) * g_op_tab[index].nb_arg)))
		return ;
	if (!(tmp->arg_value = (char **)malloc(sizeof(char *) *
													g_op_tab[index].nb_arg)))
		return ;
	init_field(tmp, g_op_tab[index].nb_arg);
	new = ft_lst_create_no_malloc(tmp);
	define_op_code_function(&new, index, str);
	ft_lst_push_back(&head, new);
}
