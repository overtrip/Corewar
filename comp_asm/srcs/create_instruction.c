/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:50:30 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:52:15 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Complete field of op_code instruction
*/

static void	define_op_code_function(t_lists **elem, int index, char **str,
															unsigned int pos)
{
	char		*str_trim;
	extern t_op	g_op_tab[SIZE];

	if ((((t_instruct *)(*elem)->data)->op_code = g_op_tab[index].id))
	{
		str_trim = ft_strtrim(*str);
		free(str[1]);
		str[0] = str_trim;
		str[1] = str_trim;
		free(parse_strsep(str, " "));
		pos += 2;
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

void		create_instruction(t_head *head, int index, char **str,
															t_posandflag* var)
{
	t_lists		*new;
	t_instruct	*tmp;
	extern t_op	g_op_tab[SIZE];

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
	define_op_code_function(&new, index, str, var->pos);
	ft_lst_push_back(&head, new);
}
