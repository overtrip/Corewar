/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:18:55 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:15:50 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	win(void)
{
	t_listd		*list;
	t_player	*player;
	t_player	*tmp;

	list = sgt_corewar()->players;
	tmp = NULL;
	while (list)
	{
		player = list->data;
		if (player->id == sgt_corewar()->id_last_live)
		{
			tmp = player;
			break ;
		}
		list = list->next;
	}
	if (tmp == NULL)
		ft_printf("All contestant, has lose !\n");
	else
		ft_printf("Contestant %i, \"%s\", has won !\n", -tmp->id, tmp->name);
}
