/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:18:10 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:30 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_basic_run(void)
{
	while (sgt_corewar()->run)
		cycle();
	win();
}

void			corewar(int argc, char **argv)
{
	option(argc, argv);
	ini_ram();
	if (sgt_corewar()->option.graphic)
	{
		vm_mlx_init();
		vm_mlx_launch();
		thread_launch();
		mlx_loop(sgt_mlx()->mlx);
	}
	else
	{
		s_basic_run();
	}
}
