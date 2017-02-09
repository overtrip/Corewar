/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:32 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:31 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*vm_mlx_thread_info(void *e)
{
	(void)e;
	while (true)
	{
		pthread_mutex_lock(&sgt_mlx()->mutex_info);
		vm_mlx_draw_info();
		pthread_mutex_unlock(&sgt_mlx()->mutex_info);
		usleep(10000);
	}
	return (NULL);
}
