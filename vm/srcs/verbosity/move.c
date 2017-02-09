/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:20 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:39 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'a' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'a' - 10 : '0';
	ret[2] = ' ';
	ret[3] = '\0';
}

void			verbose_move(t_process *process, int jump)
{
	int		i;
	int		index;
	char	str[1024];

	if (sgt_corewar()->option.verbose.move == false)
		return ;
	i = ft_sprintf(str, "ADV %u (0x%04x -> 0x%04x) ", jump, (int)process->pc,
			(int)(process->pc + jump));
	index = 0;
	while (index < jump)
	{
		s_convert_byte_to_hex(str + i,
				sgt_corewar()->ram[(process->pc + index) % MEM_SIZE].data);
		++index;
		i += 3;
	}
	ft_printf("%s\n", str);
}
