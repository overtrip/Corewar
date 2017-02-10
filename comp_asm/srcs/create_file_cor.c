/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_cor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:09:52 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/10 17:51:34 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Swap int to little edian
*/

static void		swapped(unsigned int *num, unsigned int *size)
{
	unsigned int	swapped;

	swapped = ((*num >> 24) & 0xff) |
	((*num << 8) & 0xff0000) |
	((*num >> 8) & 0xff00) |
	((*num << 24) & 0xff000000);
	*num = swapped;
	*size += 4;
}

/*
**	Initialise header of champ
*/

static void		init_head(t_header *head, unsigned int *size)
{
	ft_bzero(head, sizeof(t_header));
	head->magic = COREWAR_EXEC_MAGIC;
	swapped(&head->magic, size);
	head->prog_size = 0;
	swapped(&head->prog_size, size);
}

/*
**	Write in file all values converted
*/

static void		write_header(t_lists *champ, int res_open)
{
	t_lists			*cpy;
	t_header		head;
	int				line;
	unsigned int	size;
	char			*cast;
	t_head			*label_list;

	cpy = champ;
	line = 0;
	size = 0;
	label_list = NULL;
	init_head(&head, &size);
	while (cpy)
	{
		cast = (char*)((char **)cpy->data)[0];
		if (!ft_strncmp(cast, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			write_name(cast, &head, &size);
		if (!ft_strncmp(cast, COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)))
			write_comment(cast, &head, &size);
		cpy = cpy->next;
	}
	print_header(head, res_open);
}

/*
**	change name to create a writed in file.cor
*/

static char		*change_name(char *file_name)
{
	char	*final_path;
	char	*name;

	name = NULL;
	final_path = NULL;
	if (!(final_path = ft_strrchr(file_name, '.')))
		return (NULL);
	name = ft_strndup(file_name, final_path - file_name);
	final_path = ft_strjoin(name, ".cor");
	free(name);
	return (final_path);
}

/*
**	Create, open, call a writen function and close the new file.cor
*/

void			open_new_file(char *file_name, t_head *head, t_head *label_pos,
															t_lists *champ)
{
	int		res_open;

	(void)label_pos;
	(void)head;
	file_name = change_name(file_name);
	if ((res_open = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0755)) < 0)
		send_id("", 0);
	write_header(champ, res_open);
	wirte_instruction(head, label_pos);
	if (close(res_open) < 0)
		return ;
	free(file_name);
}
