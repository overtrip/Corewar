/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:18:23 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:20 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'a' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'a' - 10 : '0';
	ret[2] = '\0';
}

void			dump(void)
{
	char	hex[3];
	int		i;

	i = 0;
	ft_printf("0x%04x : ", i);
	while (i < MEM_SIZE)
	{
		s_convert_byte_to_hex(hex, sgt_corewar()->ram[i].data);
		ft_putstr(hex);
		++i;
		ft_putchar(' ');
		if (i % 64 == 0)
		{
			ft_putchar('\n');
			if (i < MEM_SIZE)
				ft_printf("0x%04x : ", i);
		}
	}
}
