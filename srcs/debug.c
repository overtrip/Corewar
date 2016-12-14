/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:03:39 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/14 18:31:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	TODO Use to debug
*/

void	print_champ_data(t_head *champ)
{
	t_lst	*tmp;

	tmp = champ->first;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}

void	print_content(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		++i;
	}
}

void	print_label(t_head *head)
{
	t_lst *current;

	current = head->first;
	while (current)
	{
		ft_putendl(((t_order *)current->data)->label);
		current = current->next;
	}
}

/*
**	TODO print all elements of t_instruct
*/

void	print_instruction(t_head *instruction)
{
	t_lst	*current;
	int		i;
	int		index;
	t_instruct	*str;
	extern t_op g_op_tab[17];

	current = instruction->first;
	while (current)
	{
		str = ((t_instruct *)current->data);
		i = 0;
		index = g_op_tab[str->op_code].nb_arg;
		while (i < index)
		{
			//ft_putnbr((*str)->arg_type[i]);
			++i;
		}
		current = current->next;
	}
}
