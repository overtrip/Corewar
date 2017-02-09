/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:21 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:43 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_space(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		if (pthread_mutex_trylock(&sgt_corewar()->mutex) != 0)
		{
			sgt_mlx()->pause = false;
			pthread_mutex_unlock(&sgt_corewar()->mutex);
		}
		else
		{
			sgt_mlx()->pause = true;
		}
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
