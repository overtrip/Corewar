/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:21 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/08 16:28:21 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Allocate and create name field
*/

void	write_name(char *data, header_t *head, unsigned int *size)
{
	char	*first;
	char	*end;

	first = NULL;
	end = NULL;
	first = ft_strchr(data, '"');
	end = ft_strchr(++first, '"');
	ft_memset(head->prog_name, '\0', PROG_NAME_LENGTH + 1);
	ft_memcpy(head->prog_name, first, end - first);
	*size += PROG_NAME_LENGTH;
}

/*
**	Allocate and create comment field
*/

void	write_comment(char *data, header_t *head, unsigned int *size)
{
	char	*first;
	char	*end;

	first = NULL;
	end = NULL;
	first = ft_strchr(data, '"');
	end = ft_strchr(++first, '"');
	ft_memset(head->comment, '\0', COMMENT_LENGTH + 1);
	ft_memcpy(head->comment, first, end - first);
	*size += COMMENT_LENGTH;
}
