/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:12:12 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:40 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_press_key_s(t_vm_mlx *mlx)
{
	(void)mlx;
	if (pthread_mutex_trylock(&sgt_mlx()->mutex_key) == 0)
	{
		pthread_mutex_unlock(&sgt_corewar()->mutex);
		pthread_mutex_lock(&sgt_corewar()->mutex);
		sgt_mlx()->pause = true;
		pthread_mutex_unlock(&sgt_mlx()->mutex_key);
	}
}
