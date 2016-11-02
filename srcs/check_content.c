/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/02 14:45:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Check if  instructions are valid
*/

int	find_instruction(char *data, unsigned char *flag, int line)
{
	(void)data;
	(void)line;
	(void)*flag;
	return (0);
}

/*
**	Check flags when detect FLAG_LABEL but other missing
*/

int	check_flag_order(unsigned char *flag, int line)
{
	ft_putendl("ici");
	if (!FLAG_C(*flag))
		return (send_id("no_name", line));
	if (!FLAG_N(*flag))
		return (send_id("no_comment", line));
	return (0);
}

/*
**	Find all label and links between them
*/

int	find_label(char *data, unsigned char *flag, int line)
{
	(void)line;
	(void)data;
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

	cpy = champ;
	flag = 0;
	line = 0;
	while (cpy)
	{
		++line;
		if (find_prerequis(cpy->data, &flag, line))
			return (1);
		if (find_label(cpy->data, &flag, line))
			return (1);
/*		if (find_instruction(cpy->data, &flag, line))
			return (1);*/
		cpy = cpy->next;
	}
	write_in_file(champ, file_name);
	return (0);
}
