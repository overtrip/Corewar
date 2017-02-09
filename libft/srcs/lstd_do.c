/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:19:46 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_do(t_listd **alst, int (*cmp)(),
		void (*action)(), int type)
{
	t_listd		*scan;

	if (!alst || !*alst)
		return ;
	scan = ft_lstd_front(*alst);
	while (scan && scan->next)
	{
		if (type == 0 && cmp(scan->data, scan->next->data) == 0)
			action(scan->data, scan->next->data);
		if (type == 1 && cmp(scan->data, scan->next->data) >= 0)
			action(scan->data, scan->next->data);
		if (type == 2 && cmp(scan->data, scan->next->data) > 0)
			action(scan->data, scan->next->data);
		if (type == -1 && cmp(scan->data, scan->next->data) <= 0)
			action(scan->data, scan->next->data);
		if (type == -2 && cmp(scan->data, scan->next->data) < 0)
			action(scan->data, scan->next->data);
		if (type == 42 && cmp(scan->data, scan->next->data) != 0)
			action(scan->data, scan->next->data);
		scan = scan->next;
	}
}
