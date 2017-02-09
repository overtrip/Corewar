/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:11:49 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:51 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_winner(char *str)
{
	t_listd		*list;
	t_player	*player;
	int			y;

	if (sgt_corewar()->run == true)
		return ;
	(void)str;
	y = 100;
	list = ft_lstd_back(sgt_corewar()->players);
	while (list)
	{
		player = list->data;
		if (player->id == sgt_corewar()->id_last_live)
		{
			LIBX_DRAW_SQUARE_TO_IMAGE(sgt_mlx()->img_info,
					11, y + 1, VM_INFO_WIDTH - 22, 78, 0xFFFF00);
			LIBX_DRAW_SQUARE_TO_IMAGE(sgt_mlx()->img_info,
					16, y + 6,
					VM_INFO_WIDTH - 20 - 12, 80 - 12, 0x101000);
		}
		list = list->prev;
		y += 90;
	}
}

static void		s_players(char *str)
{
	t_listd		*list;
	t_player	*player;
	int			y;

	y = 110;
	list = ft_lstd_back(sgt_corewar()->players);
	while (list)
	{
		player = list->data;
		ft_sprintf(str, "Player %-8i         : \n\n" \
				"Last live               : %-8li\n" \
				"Lives in current period : %-8li",
				-player->id,
				player->last_live,
				player->live);
		LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
				20, y, 0xFFFFFF);
		ft_sprintf(str, "%.26s", player->name);
		LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
				202, y, sgt_mlx()->color[player->color_id]);
		list = list->prev;
		y += 90;
	}
}

static void		s_general(char *str)
{
	ft_sprintf(str, "Cycle        : %-8lli     " \
			"Next check   : %8lli\n" \
			"Cycle to die : %-8lli     " \
			"Cycle delta  : %8lli\n\n" \
			"Process      : %-8u     " \
			"Cycles/second: %8lli",
			sgt_corewar()->cycle,
			sgt_corewar()->last_cycle_check + sgt_corewar()->cycle_to_die,
			sgt_corewar()->cycle_to_die,
			CYCLE_DELTA,
			sgt_corewar()->nb_process,
			sgt_corewar()->nb_cycle_per_second);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			20,
			20, 0x222222);
}

void			vm_mlx_draw_info(void)
{
	char	str[1024];

	ft_memcpy(sgt_mlx()->img_info->buffer, sgt_mlx()->background_info,
			sgt_mlx()->img_info->width * sgt_mlx()->img_info->height * \
			(sgt_mlx()->img_info->bits_per_pixel >> 3) * sizeof(unsigned char));
	s_general(str);
	s_winner(str);
	s_players(str);
}
