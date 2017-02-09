/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:27 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:59 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_sleep(void)
{
	size_t	div[3];

	if (sgt_corewar()->nb_cycle_per_second > 0)
	{
		div[0] = sgt_corewar()->nb_cycle_per_second / 1000;
		div[1] = sgt_corewar()->nb_cycle_per_second / 500;
		div[2] = sgt_corewar()->nb_cycle_per_second / 100;
		if (div[0] > 0 && sgt_corewar()->cycle % div[0] == 0)
			usleep(1000000 / 1000);
		else if (div[1] > 0 && sgt_corewar()->cycle % div[1] == 0)
			usleep(1000000 / 500);
		else if (div[2] > 0 && sgt_corewar()->cycle % div[2] == 0)
			usleep(1000000 / 100);
		else if (div[2] == 0)
			usleep(1000000 / sgt_corewar()->nb_cycle_per_second);
	}
}

void			*thread_vm(void *e)
{
	(void)e;
	pthread_mutex_lock(&sgt_corewar()->mutex);
	while (sgt_corewar()->run)
	{
		pthread_mutex_lock(&sgt_corewar()->mutex);
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		cycle();
		s_sleep();
	}
	win();
	return (NULL);
}
