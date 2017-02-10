/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/10 17:15:59 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Delete all label list elements
*/

static void		delete_label(t_lists *elem)
{
	t_lists	*save;
	t_lists	*current;

	if (!elem)
		return ;
	current = elem;
	while (current)
	{
		save = current;
		current = current->next;
		if (((t_order *)(save->data))->label)
			free(((t_order *)(save->data))->label);
		free(save->data);
		free(save);
	}
}

/*
**	Initialise check_content vars
*/

static void		init_vars(t_head *head, t_head *label_pos, t_posandflag *var)
{
	ft_bzero(label_pos, sizeof(t_head));
	ft_bzero(head, sizeof(t_head));
	ft_bzero(var, sizeof(t_posandflag));
	var->pos = COMMENT_LENGTH + PROG_NAME_LENGTH + 4;
	var->flag = 0;
}

/*
**	Launching tests to look the structure construction
*/

int				check_content(t_lists *champ, char *file_name)
{
	t_lists			*cpy;
	t_posandflag	var;
	t_head			head;
	t_head			label_pos;
	char			*cast;

	cpy = champ;
	init_vars(&head, &label_pos, &var);
	while (cpy)
	{
		cast = (char*)((char **)cpy->data)[0];
		++var.line;
		if (find_prerequis(cast, &var.flag, var.line))
			return (1);
		if (!find_label(&var.flag, var.line))
			find_pos_label(&cast, &var.pos, &label_pos);
		if (find_flag_inst(&var.flag))
			if (find_instruction(cpy->data, &var, &head))
				return (1);
		cpy = cpy->next;
	}
	open_new_file(file_name, &head, &label_pos, champ);
	delete_label(label_pos.first);
	delete_instruction(&head);
	printf("fin\n");
	return (0);
}
