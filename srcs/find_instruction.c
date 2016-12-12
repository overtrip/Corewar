/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:00:17 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/12 18:21:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

/*
**	Search in op.c the corespondence
*/

static int		search_instruction(char *str, int line)
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

static void		fill_instruction(t_head **head, int i, char *str)
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

int				find_instruction(char **data, unsigned char *flag,
													int line, t_head **head)
{
	char		*new;
	char		*cast;
	int			index;
	int			i;
	extern t_op	g_op_tab[17];

	if (!(*flag & FLAG_INST))
	{
		printf("c'est ici\n");
		return (0);
	}
	i = 0;
	cast = (char *)data;
	if ((new = parse_strsep(&cast, " ")))
	{
	new = ft_strtrim(new);
	printf("++[%s]++\n", new);
	if ((index = search_instruction(new, line)))
	{
		create_instruction(head, index);
		while (i < g_op_tab[index].nb_arg)
		{
			fill_instruction(head, i, ft_strsep(data, ","));
			++i;
		}
	}
	}
	return (0);
}
