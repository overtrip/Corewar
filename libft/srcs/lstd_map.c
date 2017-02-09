/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_map(t_listd **alst, void (*map)())
{
	t_listd		*scan;

	if (!alst || !*alst)
		return ;
	scan = ft_lstd_front(*alst);
	while (scan)
	{
		map(scan->data);
		scan = scan->next;
	}
}
