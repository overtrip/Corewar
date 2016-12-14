/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/14 17:35:55 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Delete all label list elements
*/

static void		delete_label(t_lst *elem)
{
	t_lst	*save;
	t_lst	*current;

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
**	Launching tests to look the structure construction
*/

int				check_content(t_lst *champ, char *file_name)
{
	t_lst			*cpy;
	t_posandflag	var;
	t_head			*head;
	t_head			label_pos;

	cpy = champ;
	head = NULL;
	(void)file_name;
	ft_bzero(&label_pos, sizeof(t_head));
	ft_bzero(&var, sizeof(t_posandflag));
	var.pos = COMMENT_LENGTH + PROG_NAME_LENGTH + 4;
	var.flag = 0;
	while (cpy)
	{
		++var.line;
		if (find_prerequis(cpy->data, &var.flag, var.line))
			return (1);
		if (!find_label(&var.flag, var.line))
			find_pos_label(&cpy->data, &var.pos, &label_pos);
		if (find_flag_inst(&var.flag))
			if (find_instruction(cpy->data, &var.flag, var.line, &head))
				return (1);
		cpy = cpy->next;
	}
	delete_label(label_pos.first);
	printf("fin\n");
//	open_new_file(file_name, head, &label_pos);
	return (0);
}
