/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:03:39 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:52:47 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	TODO Use to debug
*/

void		print_champ_data(t_head *champ)
{
	t_lists	*tmp;

	tmp = champ->first;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
	}
}

void		print_content(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		++i;
	}
}

void		print_label(t_head *head)
{
	t_lists *current;

	current = head->first;
	while (current)
	{
		ft_putendl(((t_order *)current->data)->label);
		current = current->next;
	}
}

/*
**	Print patern to print_instruction function
*/

static void	patern_print(t_instruct *elem, int i, int index)
{
	extern t_op g_op_tab[SIZE];

	index = 0;
	while (g_op_tab[index].id < elem->op_code)
		++index;
	ft_putstr("(op_code)[");
	ft_putnbr(elem->op_code);
	ft_putstr("](");
	ft_putstr(g_op_tab[index].name);
	ft_putstr(")");
	ft_putstr("\t(arg_type)[");
	ft_putnbr(elem->arg_type[i]);
	ft_putstr("]\t(value)[");
	ft_putstr(elem->arg_value[i]);
	ft_putstr("]");
	ft_putchar('\n');
}

/*
**	Print all elements of t_instruct
*/

void		print_instruction(t_head *instruction)
{
	t_lists		*current;
	int			i;
	int			index;
	t_instruct	*str;
	extern t_op g_op_tab[SIZE];

	current = instruction->first;
	while (current)
	{
		str = ((t_instruct *)current->data);
		i = -1;
		index = 0;
		while (g_op_tab[index].id < str->op_code)
			++index;
		index = g_op_tab[index].nb_arg;
		while (++i < index)
			patern_print(str, i, index);
		current = current->next;
	}
}
