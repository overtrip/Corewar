/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:13:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:19:17 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	check_type_args(t_op op, int type[4], int arg[4])
{
	int		i;

	i = 0;
	while (i < op.nb_args)
	{
		if (!(op.type_args[i] & type[i]))
			return (false);
		if (type[i] == T_REG && (arg[i] <= 0 || arg[i] > REG_NUMBER))
			return (false);
		++i;
	}
	return (true);
}
