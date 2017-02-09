/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:41 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:23 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_draw_init(void)
{
	vm_mlx_draw_background_memory();
	vm_mlx_draw_background_info();
}

static t_bool	s_mutex_init(void)
{
	if (pthread_mutex_init(&sgt_mlx()->mutex_memory, NULL) < 0)
		return (false);
	if (pthread_mutex_init(&sgt_mlx()->mutex_info, NULL) < 0)
		return (false);
	if (pthread_mutex_init(&sgt_mlx()->mutex_key, NULL) < 0)
		return (false);
	return (true);
}

void			vm_mlx_launch(void)
{
	if (s_mutex_init() == false)
	{
		ERR("corewar: mlx mutex error.");
		exit(EXIT_FAILURE);
	}
	s_draw_init();
	if (pthread_create(&sgt_mlx()->thread_memory, NULL,
				&vm_mlx_thread_memory, (void *)sgt_mlx()) < 0)
	{
		ERR("corewar: pthread creat error.");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&sgt_mlx()->thread_info, NULL,
				&vm_mlx_thread_info, (void *)sgt_mlx()) < 0)
	{
		ERR("corewar: pthread creat error.");
		exit(EXIT_FAILURE);
	}
}
