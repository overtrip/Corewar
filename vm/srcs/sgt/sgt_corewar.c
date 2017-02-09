/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:13 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:18:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_singleton(t_corewar *t)
{
	t->cycle = 0;
	t->cycle_to_die = CYCLE_TO_DIE;
	t->cycle_check = 0;
	t->files = NULL;
	t->players = NULL;
	t->process = NULL;
	t->nb_process = 0;
	t->nb_cycle_per_second = 500;
	t->option.verbose.aff = false;
	t->option.verbose.live = false;
	t->option.verbose.cycle = false;
	t->option.verbose.op = false;
	t->option.verbose.death = false;
	t->option.verbose.move = false;
	t->option.dump = -1;
	t->option.graphic = false;
	t->run = true;
}

static t_corewar	**s_singleton(void)
{
	static t_corewar	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_corewar *)malloc(sizeof(t_corewar))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_corewar			**sgt_addr_corewar(void)
{
	return (s_singleton());
}

t_corewar			*sgt_corewar(void)
{
	t_corewar	**t;

	t = sgt_addr_corewar();
	return (*t);
}
