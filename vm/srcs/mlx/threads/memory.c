/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:36 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:34 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*vm_mlx_thread_memory(void *e)
{
	(void)e;
	while (true)
	{
		pthread_mutex_lock(&sgt_mlx()->mutex_memory);
		vm_mlx_draw_memory();
		pthread_mutex_unlock(&sgt_mlx()->mutex_memory);
		usleep(100);
	}
	return (NULL);
}
