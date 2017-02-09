/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:15:17 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:18:08 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_singleton(t_vm_mlx *t)
{
	t->pause = true;
}

static t_vm_mlx		**s_singleton(void)
{
	static t_vm_mlx		*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_vm_mlx *)malloc(sizeof(t_vm_mlx))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_vm_mlx			**sgt_addr_mlx(void)
{
	return (s_singleton());
}

t_vm_mlx			*sgt_mlx(void)
{
	t_vm_mlx	**t;

	t = sgt_addr_mlx();
	return (*t);
}
