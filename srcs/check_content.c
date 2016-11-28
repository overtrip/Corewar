/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/28 17:50:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Search in op.c the corespondence
*/

int	search_instruction(char *str, int line)
{
	int			i;
	extern t_op	g_op_tab[17];
	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(str, g_op_tab[i].name))
			return (i);
		++i;
	}
	send_id("token", line);
	ft_putendl(str);
	return (0);
}

/*
**	filing struct with elements
*/

void	fill_instruction(t_head **head, int i, char *str)
{

	t_instruct	*tmp;
	char		value;

	tmp = (t_instruct *)(*head)->last->data;
	value = define_type(str);
	*tmp->arg_type[i] = value;
}

/*
**	Check if  instructions are valide
*/

int	find_instruction(char **data, unsigned char *flag, int line, t_head **head)
{
	char		*new;
	int			index;
	int			i;
	extern t_op	g_op_tab[17];

	(void)flag;
	i = 0;
	printf("ici\n");
	while (!(new = ft_strsep(data, " ")))
			;
	printf("[%s]\n", new);
	new = ft_strtrim(new);
	if ((index = search_instruction(new, line)))
	{
		create_instruction(head, index);
		while (i < g_op_tab[index].nb_arg)
		{
			fill_instruction(head, i, ft_strsep(data, ","));
			++i;
		}
	}
	return (0);
}

/*
**	Launching tests to look the structure construction
*/

int	check_content(t_lst *champ, char *file_name)
{
	t_lst			*cpy;
	t_posandflag	var;
	t_head			*head;
	t_order			*label_pos;

	cpy = champ;
	head = NULL;
	(void)file_name;
	ft_bzero(&var, sizeof(t_posandflag));
	var.pos = COMMENT_LENGTH + PROG_NAME_LENGTH + 4;
	var.flag = 0;
	while (cpy)
	{
		++var.line;
		if (find_prerequis(cpy->data, &var.flag, var.line))
			return (1);
		if (!find_label(&var.flag, var.line))
		{
			printf("--[%s] [%d]--\n", cpy->data, var.pos);
			find_pos_label(cpy->data, &var.pos, &label_pos);
		}
		if (find_instruction(cpy->data, &var.flag, var.line, &head))
			return (1);
		cpy = cpy->next;
	}
	printf("ici [%d]\n",head->first == NULL);
//	open_new_file(file_name, head, label_pos);
	return (0);
}
