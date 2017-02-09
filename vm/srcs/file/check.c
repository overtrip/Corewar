/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:11:30 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:09 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_check_if_free_id(int id)
{
	t_listd		*list;
	t_file		*file;

	list = sgt_corewar()->files;
	while (list)
	{
		file = list->data;
		if (file->id == id)
		{
			ERROR(ERR_FILE_SAME_ID, -id);
			exit(EXIT_FAILURE);
		}
		list = list->next;
	}
}

void			file_check(int *i, char **argv)
{
	t_file	*file;

	++(*i);
	if (ft_aisi(argv[*i]))
	{
		file = file_read(argv[(*i) + 1]);
		if (file == NULL)
		{
			ERROR("%s", ft_strerror());
			exit(EXIT_FAILURE);
		}
		file->id = -ft_atoi(argv[*i]);
		s_check_if_free_id(file->id);
		++(*i);
		ft_lstd_push_front(&sgt_corewar()->files, file);
	}
	else
	{
		ERROR(ERR_FILE_FORMAT_ID, argv[*i]);
		exit(EXIT_FAILURE);
	}
}
