/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:09:52 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/08 16:25:38 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
**	Print header file.cor
*/

void			print_header(header_t head, int res_open)
{
	write(res_open, &head.magic, 4);
	write(res_open, &head.prog_name, PROG_NAME_LENGTH + 4);
	write(res_open, &head.prog_size, 4);
	write(res_open, &head.comment, COMMENT_LENGTH + 4);
}

/*
**	Initialise header of champ
*/

static void		init_head(header_t *head, unsigned int *size)
{
	ft_bzero(head, sizeof(header_t));
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
	header_t		head;
	int				line;
	unsigned int	size;

	cpy = champ;
	line = 0;
	size = 0;
	init_head(&head, &size);
	while (cpy)
	{
		if (!ft_strncmp(cpy->data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			write_name(cpy->data, &head, &size);
		if (!ft_strncmp(cpy->data, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			write_comment(cpy->data, &head, &size);
		//if ((ret = write(res_open, cpy->data, ft_strlen(cpy->data)) < 0))
		//	ft_putendl("ca ecrit pas");
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
	char	*extenssion;

	final_path = NULL;
	name = ft_strrchr(file_name, '/');
	file_name = ft_strndup(file_name, name - file_name);
	extenssion = ft_strrchr(name, '.');
	extenssion = ft_strndup(name, extenssion - name);
	name = ft_strjoin(file_name, extenssion);
	final_path = ft_strjoin(name, ".cor");
	free(name);
	free(file_name);
	free(extenssion);
	return (final_path);
}

/*
**	Create, open, call a writen function and close the new file.cor
*/

void			open_new_file(t_lst *champ, char *file_name)
{
	t_lst	*cpy;
	int		res_open;

	cpy = champ;
	file_name = change_name(file_name);
	if ((res_open = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0755)) < 0)
		send_id("", 0);
	write_instruction(champ, res_open);
	if (close(res_open) < 0)
		return ;
	free(file_name);
}
