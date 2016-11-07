/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:21 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/07 17:51:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Allocate and create name field
*/

void	write_name(char *data, int line, int res_open, unsigned int *size)
{
	char	*name;
	char	*first;
	char	*end;

	first = NULL;
	end = NULL;
	first = ft_strchr(data, '"');
	end = ft_strchr(++first, '"');
	if (!(name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1)))
		send_id("malloc", line);
	ft_memset(name, '\0', PROG_NAME_LENGTH);
	ft_memcpy(name, first, end - first);
	write(res_open, name, 4 + *size + PROG_NAME_LENGTH);
	*size += PROG_NAME_LENGTH;
}

/*
**	Allocate and create comment field
*/

void	write_comment(char *data, int line, int res_open, unsigned int *size)
{
	char	*name;
	char	*first;
	char	*end;

	first = NULL;
	end = NULL;
	first = ft_strchr(data, '"');
	end = ft_strchr(++first, '"');
	if (!(name = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1)))
		send_id("malloc", line);
	ft_memset(name, '\0', COMMENT_LENGTH);
	ft_memcpy(name, first, end - first);
	write(res_open, name, *size + COMMENT_LENGTH);
	*size += COMMENT_LENGTH;
}
