/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:17:11 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:45 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_death(t_process *process)
{
	if (sgt_corewar()->option.verbose.death == false)
		return ;
	ft_printf("Process %lu hasn't lived for %li cycles (CTD %li)\n",
			process->uid,
			sgt_corewar()->cycle - process->live,
			sgt_corewar()->cycle_to_die);
}
