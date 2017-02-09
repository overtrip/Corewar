/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:01 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:51 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_cycle(void)
{
	if (sgt_corewar()->option.verbose.cycle == false)
		return ;
	ft_printf("It is now cycle %li\n", sgt_corewar()->cycle);
}
