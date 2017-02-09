/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:47 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:25 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		vm_mlx_loop_hook(t_vm_mlx *mlx)
{
	pthread_mutex_lock(&mlx->mutex_memory);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_memory->img_ptr,
			VM_INFO_WIDTH, 5);
	pthread_mutex_unlock(&mlx->mutex_memory);
	if (pthread_mutex_trylock(&mlx->mutex_info) == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_info->img_ptr,
				0, 0);
		pthread_mutex_unlock(&mlx->mutex_info);
	}
	return (0);
}
