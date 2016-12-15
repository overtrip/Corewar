/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:00:17 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/15 15:56:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Search in op.c the corespondence
*/

static int		search_instruction(char *str, int line)
{
	int			i;
	char		*to_find;
	char		*begin;
	extern t_op	g_op_tab[17];

	i = -1;
	if (!str || !*str)
		return (0);
	begin = str;
	to_find = ft_strchr(str, ' ');
	begin = ft_strndup(str, to_find - begin);
	while (++i && g_op_tab[i].name)
		if (!ft_strcmp(begin, g_op_tab[i].name))
		{
			printf("ICI\n");
				return (i);
		}
	send_id("token", line);
	return (0);
}

/*
**	filing struct with elements
*/

void		fill_instruction(t_head **head, int i, char *str)
{
	t_instruct	*tmp;
	char		value;

	tmp = (t_instruct *)(*head)->last->data;
	value = define_type(str);
	*tmp->arg_type[i] = value;
}

/*
**	Check if line is a comment or a label
*/

int				go_out(char *str)
{
	char	*find;

	if (*str == '#')
		return (1);
	if (!(find = ft_strchr(str, ':')))
		return (0);
	if (++find && !*find)
		return (1);
	return (0);
}


/*
**	Check if  instructions are valide
*/

int				find_instruction(char **data, unsigned char *flag,
													int line, t_head **head)
{
	char		*new;
	int			index;
	int			i;
	extern t_op	g_op_tab[17];

	i = 0;
	(void)head;
	(void)flag;
	new = ft_strtrim((char *)data);
	if (new && *new && !go_out(new))
	{
		if ((index = search_instruction(new, line)))
		{
			printf("+%d+\n", index);
		/*	create_instruction(head, index);
			while (i < g_op_tab[index].nb_arg)
			{
				fill_instruction(head, i, ft_strsep(data, ","));
				++i;
			}*/
		}
	}
	free(new);
	return (0);
}
