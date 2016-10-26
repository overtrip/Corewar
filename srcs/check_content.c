/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/26 13:18:54 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Find all label and links between them
*/

static int	find_label(char *data, unsigned char *flag, int line)
{
	/*
	**	TODO in progress
	*/
	(void)line;
	(void)data;
	(void)flag;
	//*flag |= FLAG_LABEL;
	return (0);
}

/*
**	Launching tests to look the structure construction
*/

int			check_content(t_lst *champ)
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
		cpy = cpy->next;
	}
	if (!(FLAG_C(flag) || FLAG_N(flag) || flag & FLAG_LABEL))
		ft_putendl("ICI");
	return (0);
}
