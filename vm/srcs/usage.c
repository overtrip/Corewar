/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:18:50 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:15:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	usage(void)
{
	ft_printf("Usage: %s\n", MSG_USAGE);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("%-10s Graphic MLX\n", "-g");
	ft_printf("%-10s Dumps memory after N cycles then exits\n", "-d N");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("%-10s Prints output from \"aff\"\n", "--aff");
	ft_printf("%-10s Show lives\n", "--lives");
	ft_printf("%-10s Show cycles\n", "--cycles");
	ft_printf("%-10s Show operations (Param are NOT litteral ...)\n", "--ops");
	ft_printf("%-10s Show deaths\n", "--deaths");
	ft_printf("%-10s Show PV movements (Except for jumps)\n", "--moves");
	exit(EXIT_FAILURE);
}
