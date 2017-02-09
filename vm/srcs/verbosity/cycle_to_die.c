/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:07 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:48 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_cycle_to_die(void)
{
	if (sgt_corewar()->option.verbose.cycle == false)
		return ;
	ft_printf("Cycle to die is now %li\n", sgt_corewar()->cycle_to_die);
}
