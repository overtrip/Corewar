/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:09:52 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/30 14:53:47 by jealonso         ###   ########.fr       */
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

static void		write_instruction(t_lst *champ, int res_open)
{
	t_lst			*cpy;
	t_header		head;
	int				line;
	unsigned int	size;
	t_head			*label_list;

	cpy = champ;
	line = 0;
	size = 0;
	label_list = NULL;
	init_head(&head, &size);
	while (cpy)
	{
		printf("[%s]\n", cpy->data);
		if (!ft_strncmp(cpy->data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			write_name(cpy->data, &head, &size);
		if (!ft_strncmp(cpy->data, COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)))
			write_comment(cpy->data, &head, &size);
	//	find_pos_label(cpy->data, &size, label_list);
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

void			open_new_file(char *file_name, t_head *head, t_head *label_pos)
{
	int		res_open;

	//TODO Modif that !!
	(void)label_pos;
	file_name = change_name(file_name);
	if ((res_open = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0755)) < 0)
		send_id("", 0);
	write_instruction(head->first, res_open);
	if (close(res_open) < 0)
		return ;
	free(file_name);
}
