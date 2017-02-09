/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:31 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:00 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*player_creat(t_file *file, int color_id)
{
	t_player	*player;

	if ((player = (t_player *)malloc(sizeof(t_player))) == NULL)
		return (NULL);
	player->id = file->id;
	player->color_id = color_id;
	player->live = 0;
	player->last_live = -1;
	player->name = file->header->prog_name;
	player->description = file->header->comment;
	ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			-player->id, file->header->prog_size,
			player->name, player->description);
	return (player);
}
