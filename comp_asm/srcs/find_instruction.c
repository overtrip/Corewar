/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:00:17 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/10 16:02:49 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Search in op.c the corespondence
*/

static int		search_instruction(char *str, int line)
{
	int			i;
	char		*to_find;
	char		*begin;
	extern t_op	g_op_tab[SIZE];

	i = -1;
	if (!str || !*str)
		return (-1);
	begin = str;
	to_find = ft_strchr(str, ' ');
	begin = ft_strndup(str, to_find - begin);
	while (g_op_tab[++i].name)
		if (!ft_strcmp(begin, g_op_tab[i].name))
		{
			free(begin);
			return (i);
		}
	send_id("token", line);
	return (-1);
}

/*
**	Cut comment and trim string
*/

static char		*cut_comment(char *str)
{
	char	*delete;
	char	*cut;
	char	*tmp;
	char	*ret;

	delete = NULL;
	cut = NULL;
	tmp = NULL;
	ret = NULL;
	if ((delete = ft_strrchr(str, ';'))
		|| (delete = ft_strrchr(str, '#')))
	{
		tmp = ft_strsub(str, 0, delete - str);
		cut = ft_strtrim(tmp);
		free(tmp);
		return (cut);
	}
	if (str && *str)
		ret = ft_strtrim(str);
	return (ret);
}

/*
**	Check if T_DIR size is 2 or 4 octets
*/

int				size_arg(char value, int op_code)
{
	int			size;
	extern t_op	g_op_tab[SIZE];

	size = g_op_tab[op_code].label_size;
	if (value == T_DIR)
		return (size == 2 ? 2 : 4);
	if (value == T_REG)
		return (1);
	if (value == T_IND)
		return (2);
	return (0);
}

/*
**	filing struct with elements
*/

void			fill_type_instruction(t_head *head, int i, char *str,
															unsigned int *pos)
{
	t_instruct	*tmp;
	char		type;
	char		*cut;

	tmp = (t_instruct *)head->last->data;
	cut = cut_comment(str);
	type = define_type(cut);
	free(cut);
	if (type)
	{
		tmp->arg_type[i] = type;
		*pos += size_arg(type, (int)(tmp)->op_code);
	}
}

/*
**	filing struct with elements
*/

void			fill_value_instruction(t_head *head, int i, char *str)
{
	t_instruct	*tmp;
	char		*cut;

	tmp = (t_instruct *)head->last->data;
	cut = cut_comment(str);
	if (cut)
	{
		tmp->arg_value[i] = ft_strdup(cut);
		free(cut);
	}
}

/*
**	Check if line is a comment or a label
*/

static int		go_out(char *str)
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

int				find_instruction(char **cast, t_posandflag *var, t_head *head)
{
	char		*new;
	char		*substring;
	int			index;
	int			i;
	void		*save;
	extern t_op	g_op_tab[SIZE];

	save = *cast;
	new = ft_strtrim(*cast);
	if (new && *new && !go_out(new))
	{
		index = search_instruction(new, var->line);
		if (index > -1 && index < SIZE)
		{
			i = -1;
			create_instruction(head, index, cast, var);
			if (g_op_tab[index].nb_arg > 1)
				var->pos += 2;
			while (++i < g_op_tab[index].nb_arg)
			{
				substring = parse_strsep(cast, ",");
				fill_type_instruction(head, i, substring, &var->pos);
				fill_value_instruction(head, i, substring);
				ft_strdel(&substring);
			}
		}
	}
	*cast = save;
	free(new);
	return (0);
}
