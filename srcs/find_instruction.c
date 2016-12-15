/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:00:17 by jealonso          #+#    #+#             */
/*   Updated: 2016/12/15 15:11:42 by jealonso         ###   ########.fr       */
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
	if (!(str && *str))
		return (0);
//	printf("[%s](%d)-> search_instruction\n", str, line);
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(str, g_op_tab[i].name))
		{
//		printf("[%s]->[%s]\n", str, g_op_tab[i].name);
			return (i);
		}
		++i;
	}
//	printf("[%s](%d)\n", str, line);
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
** TODO	ft_strchr like, find multiple occurence in string
*/

int				multichr(char *str, char *to_find)
{
	char	*current;

	current = str;
	while (*current)
	{
		if (ft_strchr(to_find, *current))
			return (1);
		++current;
	}
	return (0);
}

/*
**	TODO check if line is empty or comment
*/

int				go_out(char *str)
{
	char	*current;

	if (!str || !*str || (str && *str == '#'))
		return (1);
	current = str;
	while (*current)
	{
		if (!ft_strchr(" #;\t", *current))
			return (0);
		++current;
	}
	return (1);
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

	i = 0;
	cast = (char *)data;
	(void)head;
	(void)flag;
	if (go_out(cast))
		return (0);
	while ((new = parse_strsep(&cast, " \t")))
	{
		if ((index = search_instruction(new, line)))
			break;
		free(new);
	}
	if (new && *new)
	{
		new = ft_strtrim(new);
		if ((index = search_instruction(new, line)))
		{
		/*	create_instruction(head, index);
			while (i < g_op_tab[index].nb_arg)
			{
				fill_instruction(head, i, ft_strsep(data, ","));
				++i;
			}*/
		}
	free(new);
	}
	return (0);
}
