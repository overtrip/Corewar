/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:22:15 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:53:36 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Create to cut str[0] and free str[1] avoid some leaks
*/

void		stock_box(char ***box, char *str)
{
	if (!(*box = (char **)malloc(sizeof(char *) * 2)))
		return ;
	(*box)[0] = str;
	(*box)[1] = str;
}

/*
**	Dup the buffer, create and push back the new link
*/

static int	get_line(t_head *champ, char **buff, int line)
{
	t_lists	*new_line;
	char	*tmp_buff;
	char	**box;

	box = NULL;
	if (!(tmp_buff = ft_strdup(*buff)))
		return (send_id("no_maloc_data", line));
	ft_strdel(buff);
	stock_box(&box, tmp_buff);
	if (!(new_line = ft_lst_create_no_malloc(box)))
		return (send_id("no_malloc_link", line));
	if (!ft_lst_push_back(&champ, new_line))
		return (send_id("no_malloc_link", line));
	return (0);
}

/*
**	Initialise all to 0 or NULL
*/

static void	init_null(t_head *files, int *line, int *i)
{
	files->first = NULL;
	files->last = NULL;
	i = 0;
	line = 0;
}

/*
**	Delete champ data and buffer
*/

static void	delete_all(t_head *champ, char **buff)
{
	t_lists	*save;
	t_lists	*current;
	char	*str;

	ft_strdel(buff);
	if (champ)
	{
		current = champ->first;
		while (current)
		{
			save = current;
			str = (char *)((char **)save->data)[1];
			current = current->next;
			free(str);
			free(save->data);
			free(save);
			save = NULL;
		}
		champ->first = NULL;
		champ->last = NULL;
	}
}

/*
**	Calling to open and close files
*/

static int	open_files(char *file_name)
{
	int		res_open;
	int		i;
	int		line;
	char	*buff;
	t_head	champ;

	i = 0;
	init_null(&champ, &line, &i);
	if ((res_open = open(file_name, O_RDONLY)) < 0)
		return (send_id("open", 0));
	else
	{
		while (get_next_line(res_open, &buff) > 0)
		{
			++line;
			if (get_line(&champ, &buff, line))
				i = 1;
		}
		if (check_content(champ.first, file_name))
			i = 1;
	}
	delete_all(&champ, &buff);
	if (close(res_open) < 0)
		return (send_id("close", 0));
	return (i);
}

/*
**	You know that
*/

int			main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2 || argc > MAX_ARGS_NUMBER)
		return (send_id("usage", 0));
	while (++i < argc)
		if (open_files(argv[i]))
			return (1);
	return (0);
}
