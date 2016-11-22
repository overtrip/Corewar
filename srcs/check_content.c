/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/22 13:56:38 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Check if  instructions are valide
*/

int	find_instruction(char *data, unsigned char *flag, int line, t_head **head)
{
	return (0);
}

/*
**	Check flags when detect FLAG_LABEL but other missing
*/

int	check_flag_order(unsigned char *flag, int line)
{
	if (!FLAG_C(*flag))
		return (send_id("no_name", line));
	if (!FLAG_N(*flag))
		return (send_id("no_comment", line));
	return (0);
}

/*
**	Find all label and links between them
*/

int	find_label(char *data, unsigned char *flag, int line, t_head *head)
{
	if (*flag & FLAG_LABEL && !(FLAG_C(*flag) && FLAG_N(*flag)))
		return (check_flag_order(flag, line));
	return (0);
}

/*
**	Launching tests to look the structure construction
*/

int	check_content(t_lst *champ, char *file_name)
{
	t_lst			*cpy;
	unsigned char	flag;
	int				line;
	unsigned int	pos;
	t_head			*head;
	t_order			*label_pos;

	cpy = champ;
	flag = 0;
	line = 0;
	pos = COMMENT_LENGTH + PROG_NAME_LENGTH + 4;
	while (cpy)
	{
		++line;
		if (find_prerequis(cpy->data, &flag, line))
			return (1);
		if (find_label(cpy->data, &flag, line, head))
			find_pos_label(cpy->data, &pos, &label_pos);
		if (find_instruction(cpy->data, &flag, line, &head))
			return (1);
		cpy = cpy->next;
	}
	open_new_file(champ, file_name);
	return (0);
}
