/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:11:35 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:12 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned int		s_swap_int(unsigned int a)
{
	return ((a << 24) | \
			((a << 8) & 0x00ff0000) | \
			((a >> 8) & 0x0000ff00) | \
			((unsigned int)(a >> 24)));
}

t_header				*file_get_header(void *ptr)
{
	t_header	*header;

	header = (t_header *)ptr;
	header->magic = s_swap_int(header->magic);
	header->prog_size = s_swap_int(header->prog_size);
	return (header);
}
