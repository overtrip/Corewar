/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:22 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bool	s_mutex_init(void)
{
	if (pthread_mutex_init(&sgt_corewar()->mutex, NULL) < 0)
		return (false);
	if (pthread_mutex_init(&sgt_corewar()->mutex_process, NULL) < 0)
		return (false);
	return (true);
}

void			thread_launch(void)
{
	if (s_mutex_init() == false)
	{
		ERR("corwar: mlx mutex error.");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&sgt_corewar()->thread, NULL,
				&thread_vm, (void *)sgt_corewar()) < 0)
	{
		ERR("corwar: pthread creat error.");
		exit(EXIT_FAILURE);
	}
}
