/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:09:52 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/02 15:25:33 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		write_instruction(t_lst *champ, int res_open)
{
	t_lst	*cpy;
	size_t	ret;

	cpy = champ;
	while (cpy)
	{
		if ((ret = write(res_open, cpy->data, ft_strlen(cpy->data)) < 0))
				ft_putendl("ca ecrit pas");
		cpy = cpy->next;
	}
}

/*
**	change name to create a writed in file.cor
*/

static char	*change_name(char *file_name)
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

void		write_in_file(t_lst *champ, char *file_name)
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
	while (cpy)
		cpy = cpy->next;
}
