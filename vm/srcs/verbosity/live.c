/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:15 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:42 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_live(int id, char *name)
{
	if (sgt_corewar()->option.verbose.live == false)
		return ;
	ft_printf("Player %i (%s) is said to be alive\n", id, name);
}
